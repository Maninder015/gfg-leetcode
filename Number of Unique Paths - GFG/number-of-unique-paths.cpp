//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    
    int func(int m,int n,vector<vector<int>> &dp)
    {
        if(m==0 && n==0)
        return 1;
        
        if(m<0 || n<0)
        return 0;
        
        if(dp[m][n]!=-1)
        return dp[m][n];
        
        int up=func(m-1,n,dp);
        int left=func(m,n-1,dp);
        
        return dp[m][n]=up+left;
        
    }
    
    
    int NumberOfPath(int a, int b)
    {
        vector<vector<int>> dp(a,vector<int> (b,-1));
        
        return func(a-1,b-1,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends