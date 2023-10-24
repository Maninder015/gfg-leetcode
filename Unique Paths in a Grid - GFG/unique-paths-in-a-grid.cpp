//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int modu=pow(10,9)+7;
    int func(int m,int n,vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        if(m==0 && n==0)
        return 1;
        
        if(m<0 || n<0)
        return 0;
        
        if(grid[m][n]==0)
        return 0;
        
        if(dp[m][n]!=-1)
        return dp[m][n];
        
        int up=func(m-1,n,grid,dp);
        int left=func(m,n-1,grid,dp);
        
        return dp[m][n]=(((up%modu)+(left%modu))%modu);
        
    }
    
    int uniquePaths(int n, int m, vector<vector<int>> &grid) 
    {
        if(grid[0][0]==0 || grid[n-1][m-1]==0)
        return 0;
        
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return func(n-1,m-1,grid,dp)%modu;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends