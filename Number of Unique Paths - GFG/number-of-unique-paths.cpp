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
    
    
    
    int NumberOfPath(int a, int b)
    {
        vector<int> dp(b,0);
        
        for(int i=0;i<a;i++)
        {
             vector<int> cur(b,-1);
            for(int j=0;j<b;j++)
            {
                if(i==0 && j==0)
                cur[j]=1;
                else
                {
                    int up=0,left=0;
                    if(i>0)
                    up=dp[j];
                    if(j>0)
                    left=cur[j-1];
                    
                    cur[j]=left+up;
                }
            }
            dp=cur;
        }
        
        
        
        
        return dp[b-1];
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