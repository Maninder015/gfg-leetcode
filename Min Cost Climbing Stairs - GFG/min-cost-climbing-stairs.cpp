//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    
    int func(vector<int>&cost ,int i,int N,vector<int> &minn)
    {
        if(i==0 || i==1)
        return cost[i];
        
        if(minn[i]!=-1)
        return minn[i];
        
        int a=0;
        int b=0;
        if(i!=N)
        a=cost[i]+func(cost,i-1,N,minn);
        else 
        a= func(cost,i-1,N,minn);
        if(i!=N)
        b=cost[i]+func(cost,i-2,N,minn);
        else
        b=func(cost,i-2,N,minn);
        
        return minn[i]=min(a,b);
        
        
    }
      
  
  
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        
        vector<int> minn(N+1,-1);
        
        
        return min(func(cost,N,N,minn),func(cost,N-1,N,minn));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends