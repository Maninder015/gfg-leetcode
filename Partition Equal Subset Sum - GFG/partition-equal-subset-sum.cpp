//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int func(int i,int sum,int arr[],vector<vector<int>> &dp)
    {
        if(sum==0) return 1;
        if(i==0) return sum==arr[0];
        
        if(dp[i][sum]!=-1)
        return dp[i][sum];
        
        int not_take = func(i-1,sum,arr,dp);
        int take=false;
        if(sum>= arr[i])
        take = func(i-1,sum-arr[i],arr,dp);
        
        return dp[i][sum]= take | not_take;
        
        
    }

    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        int x=sum/2;
        vector<vector<int>> dp(N,vector<int> (sum+1,-1));
        if(sum % 2)
        return false;
        else
        {
            return func(N-1,x,arr,dp); 
        }
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends