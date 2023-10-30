//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	
// 	void func(int n,int &count,bool flag)
// 	{
// 	    if(n==1)
// 	    {
// 	        if(!flag)
// 	        count++;
	        
// 	        count++;
// 	    }
	    
// 	    if(!flag)
// 	    func(n-1,count,!flag);
	    
// 	    func(n-1,count,flag);
	    
	    
	    
	    
// 	}
	
	
	
	
	
	
	ll countStrings(int n) {
	   // long long count=0;
	   // func(n,count,false);
	    
	   // return count;
	   
	   int a[n+1],b[n+1];
	   a[1]=1;
	   b[1]=1;
	   
	   for(int i=2;i<=n;i++)
	   {
	       a[i]=(a[i-1]+b[i-1])%1000000007;
	       b[i]=a[i-1]%1000000007;
	   }
	   
	   return (a[n]+b[n])%1000000007;
	   
	   
	   
	   
	   
	   
	   
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends