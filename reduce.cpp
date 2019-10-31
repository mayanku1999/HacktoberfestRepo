#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int memo[10000];
int reduce(int n){
    if(n==1)return 0;
    int  c1=INT_MAX,c2=INT_MAX,c3=INT_MAX;
    if(memo[n]!=-1)return memo[n];
    if(n%3==0) c1= 1+reduce(n/3);
    if(n%2==0) c2= 1+reduce(n/2);
     c3 = 1+reduce(n-1);
    memo[n] = min(c1, min(c2,c3));
    return memo[n];
}
int reduce_DP(int n){
    int DP[10000];
    DP[0]=0;   DP[1]=0;
    DP[2]=1;   DP[3]=1;
    for(int i=4;i<=n;i++){
        int c1=INT_MAX,c2=INT_MAX,c3=INT_MAX;
        if(i%3==0) c1=1+DP[i/3];
        if(i%2==0) c2=1+DP[i/2];
        c3= 1 +DP[i-1];
        DP[i]=min(c1,min(c2,c3));}
        return DP[n];
}

int main() {
 int n;
 cin>>n;
 fill(memo,memo+n+1,-1);
 int c=reduce_DP(n);
 cout<<c;
}
