#include<bits/stdc++.h>
using namespace std;
struct abc{
        int a,b;
    };
bool comp(abc x,abc y){
    return (x.b<y.b);
}

int main()
{
    //Write your code here
    int n;
    cin>>n;
    // vector<pair<int,int>>v;
    
    abc arr[n];
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        arr[i].a=x;
        arr[i].b=y;
        
    }
    int j=0,ans=1;
    sort(arr,arr+n,comp);
    for(int i=1;i<n;i++){
        // cout<<arr[i].a<<" "<<arr[i].b<<endl;
        if(arr[i].a>=arr[j].b){
            ans++;
            j=i;
        }
        
        
    }
    cout<<ans;
    return 0;
}