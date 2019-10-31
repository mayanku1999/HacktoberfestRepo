#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int memo[100];
int maxprofit(int arr[],int totalLen){
    if(totalLen==0){
        return 0;
    }
    if(memo[totalLen]!=-1)return memo[totalLen];
    int best=0;
    for(int len=1;len<=totalLen;len++){
        int netProfit=arr[len]+maxprofit(arr,totalLen-len);
        best=max(best,netProfit);
    }
    memo[totalLen]=best;
    return best;
}
int maxprofit_DP(int arr[],int totalLen){
    int DP[100]={};
    for(int len=1;len<=totalLen;len++){
        int best=0;
        for(int cut=1;cut<=len;cut++){
            best=max(best,arr[cut]+DP[len-cut]);
        }
        DP[len]=best;
    }

return DP[totalLen];


}
int main() {
int n;
cin>>n;
int arr[100];
for(int i=1;i<=n;i++){
cin>>arr[i];
}
for(int i=0;i<=n;i++){
memo[i]=-1;
}
// int ans=maxprofit(arr,n);
int ans= maxprofit_DP(arr,n);
cout<<ans;
}
