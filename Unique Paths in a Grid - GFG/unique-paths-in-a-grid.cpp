//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int modu=pow(10,9)+7;
    
    int uniquePaths(int n, int m, vector<vector<int>> &grid) 
    {
        if(grid[0][0]==0 || grid[n-1][m-1]==0)
        return 0;
        
        vector<int> dp(m,0);
        
        for(int i=0;i<n;i++)
        {
            vector<int> cur(m,0);   
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)
                cur[j]=1;
                else if(grid[i][j]==0)
                cur[j]=0;
                else
                {
                    int up=0;
                    int left=0;
                    
                    if(i>0)
                    up=dp[j];
                    if(j>0)
                    left=cur[j-1];
                    
                    cur[j]=(((up%modu)+(left%modu))%modu);
                }
            }
            dp=cur;
        }
        
        
        
        return dp[m-1];
        
        
        
        
        
        
        
        
        // return func(n-1,m-1,grid,dp)%modu;
        
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