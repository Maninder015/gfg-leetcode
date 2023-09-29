//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

  

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(N,vector<int> (N,0));
    
        for(int i=0;i<N;i++)
        dp[0][i]=Matrix[0][i];
        
        for(int i=1;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                int a=Matrix[i][j]+dp[i-1][j];
                
                int b=Matrix[i][j];
                if(j-1>=0)
                b+=dp[i-1][j-1];
                else 
                b+=-1e8;
                
                int c=Matrix[i][j];
                if(j+1<N)
                c+=dp[i-1][j+1];
                else 
                c+=-1e8;
        
         dp[i][j]=max(a,max(b,c));
            }
        }
    
    
    
    
    
        int maxx=-1e8;
        for(int i=0;i<N;i++)
        {
            maxx=max(maxx,dp[N-1][i]);
        }
        return maxx;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends