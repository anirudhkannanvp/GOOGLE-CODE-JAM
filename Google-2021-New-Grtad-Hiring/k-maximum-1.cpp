#include<bits/stdc++.h>
using namespace std;

vector<int> funct(vector<int> total,int m,int n,int k,vector<vector<int>> dp){
   int i,j;
   sort(total.begin(),total.end(),greater<int>());
   vector<int> ans;
   int ele=total[k-1];
   for(i=0;i<m;i++){
       for(j=0;j<n;j++){
          if(dp[i][j]==ele){
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
          }
       }
   }
}

vector<int> solve (int N, int M, vector<vector<int> > A, int K) {
   // Write your code here
   int i,j,m=M,n=N;
   vector<vector<int>> dp (m,vector<int>(n,0));
   vector<int> ans;
   vector<int> total;
   dp[0][0]=A[0][0];
   if(m==1 && n==1){
       ans.push_back(1);
       ans.push_back(1);
       return ans;
   }
   else if(m==1 && n>1){
       for(j=1;j<n;j++){
       dp[0][j]=dp[0][j-1]^A[0][j];
       total.push_back(dp[0][j]);
       }
       return funct(total,m,n,K,dp);
   }
   else if(m>1 && n==1){
        for(i=1;i<m;i++){
            dp[i][0]=dp[i-1][0]^A[i][0];
            total.push_back(dp[i][0]);
        }
        return funct(total,m,n,K,dp);
   }
   else{
        for(i=1;i<m;i++){
            dp[i][0]=dp[i-1][0]^A[i][0];
            total.push_back(dp[i][0]);
        }
        for(j=1;j<n;j++){
            dp[0][j]=dp[0][j-1]^A[0][j];
            total.push_back(dp[0][j]);
        }
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                dp[i][j]=(dp[i-1][j]^dp[i][j-1])^dp[i-1][j-1]^A[i][j];
                total.push_back(dp[i][j]);
            }
        }
    return funct(total,m,n,K,dp);
   }
   return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int M;
        cin >> M;
        vector<vector<int> > A(N, vector<int>(M));
        for (int i_A = 0; i_A < N; i_A++)
        {
        	for(int j_A = 0; j_A < M; j_A++)
        	{
        		cin >> A[i_A][j_A];
        	}
        }
        int K;
        cin >> K;

        vector<int> out_;
        out_ = solve(N, M, A, K);
        cout << out_[0];
        for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
        {
        	cout << " " << out_[i_out_];
        }
        cout << "\n";
    }
}
