//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:

    Node* func(Node* root,int ele,unordered_map<Node*,Node*> &parent)
    {
        Node* temp1=NULL;
        queue<Node*> qe;
        qe.push(root);
        while(!qe.empty())
        {
            Node* temp= qe.front();
            qe.pop();
            if(temp->data==ele)
            temp1=temp;
            if(temp->left)
            {
                qe.push(temp->left);
                parent[temp->left]=temp;
            }
             if(temp->right)
            {
                qe.push(temp->right);
                parent[temp->right]=temp;
            }
        }

        return temp1;
        
        
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        unordered_map<Node*,Node*> parent;
        Node* ele= func(root,target,parent);
        
        
        unordered_map<Node*,bool> vis;
        queue<Node*> qe;
        qe.push(ele);
        vis[ele]=true;
        int level=0;
        while(!qe.empty())
        {
            // cout<<"l="<<level<<" ";
            int size=qe.size();
            if(level==k)
            break;
            level++;
            // cout<<qe.front()->data<<endl;
            
            for(int i=0;i<size;i++)
            {
                Node* cur= qe.front();
                qe.pop();
                
                if(cur->left && !vis[cur->left])
                {
                    // cout<<cur->left->data<<" ";
                    
                    qe.push(cur->left);
                    vis[cur->left]=true;
                }
                if(cur->right && !vis[cur->right])
                {
                    // cout<<cur->right->data<<" ";
                    
                    qe.push(cur->right);
                    vis[cur->right]=true;
                }
                if(parent[cur] && !vis[parent[cur]])
                {
                    // cout<<parent[cur]->data<<endl;
                    
                    qe.push(parent[cur]);
                    vis[parent[cur]]=true;
                }
                
                
                
                
            }
            
            
        }
        // cout<<endl;
        vector<int> ans;
        while(!qe.empty())
        {
            Node* temp=qe.front();
            qe.pop();
            ans.push_back(temp->data);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
        
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends