#include <iostream>
using namespace std;

int maxprofit(int arr[],int be,int en, int year){
    if(be>en)return 0;

    int q1=arr[be]*year + maxprofit(arr,be+1,en,year+1);
    int q2=arr[en]*year + maxprofit(arr,be,en-1,year+1);
    int ans = max(q1,q2);
    return ans;
}

int maxprofitDP(int arr[],int n){
    int year=n;
    int DP[100][100]={};
    for(int i=0;i<n;i++){
        DP[i][i]=year*arr[i];
    }
    year--;
    for(int len=2;len<=n;len++){
        int srt=0;
        int end=n-len;
        while(srt<=end){
            int endWindow=srt+len-1;
            DP[srt][endWindow]=max(
                arr[srt]*year +DP[srt+1][endWindow],
                arr[endWindow]*year + DP[srt][endWindow-1]
            );
            srt++;
        }
        year--;
    }
    return DP[0][n-1];
}

int main() {
int n;
cin>>n;
int arr[100];
for(int i=0;i<n;i++){
    cin>>arr[i];

}
// int ans=maxprofit(arr,0,n-1,1);
int ans=maxprofitDP(arr,n);
cout<<ans;
// cout<<ans;
}
