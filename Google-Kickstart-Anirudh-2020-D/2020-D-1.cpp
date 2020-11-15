#include"bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    
    for(int case_num=1;case_num<=t;case_num++){
        int n;cin>>n;
        vector<int> arr(n);
        int ans=0,curr_max=-1;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=0;i<n;i++){
            ans+=arr[i]>curr_max && (i+1==n || arr[i]>arr[i+1]);
            curr_max=max(curr_max,arr[i]);
        }
        
        
        cout<<"Case #"<<case_num<<": "<<ans<<endl;
    }

    return 0;
}
