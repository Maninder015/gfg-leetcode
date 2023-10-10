//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // vector<int> dp(n);
        
        // int prev1=0;
        // int prev2=0;
        // dp[1]=arr[1];
        // for(int i=2;i<n;i++)
        // {
        //     prev1=arr[i];
        //     if(i>2)
        //     prev2+=dp[i-2];
        //     prev2=dp[i-1];
            
        //     dp[i]=max(prev1,prev2);
        // }
        // int maxx1=dp[n-1];
        
        // dp.clear();
        
        // dp[0]=arr[0];
        // for(int i=1;i<n-1;i++)
        // {
        //     prev1=arr[i];
        //     if(i>1)
        //     prev2+=dp[i-2];
        //     prev2=dp[i-1];
            
        //     dp[i]=max(prev1,prev2);
        // }
        
        // int maxx2= dp[n-2];
        
        
        
        // return max(maxx1,maxx2);
         for(int i=1;i<n;i++)
	    {
	        
	         int  pick = arr[i];
	         if(i>1) pick+= arr[i-2];
	         int  notpick = arr[i-1];
	    
	      arr[i]=max(pick,notpick);
	    }
	    
	    return arr[n-1];
        
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends