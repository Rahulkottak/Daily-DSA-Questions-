//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    class node{
        public:
        int data ;
        int row ;
        int col ;
        
        node(int d,int r ,int c){
            this->data = d;
            this->row = r ;
            this->col = c ; 
        }
    };
    
    class compare{
        public:
        bool operator()(node* a,node* b){
            return a->data > b->data ;
        }
    };
    
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<node*,vector<node*>,compare> pq ;
        
        for(int i=0;i<K;i++){
            node* temp = new node(arr[i][0],i,0);
            pq.push(temp);
        }
        
        vector<int> ans ;
        while(pq.size()>0){
            node* tmp = pq.top();
            ans.push_back(tmp->data);
            pq.pop();
            
            int row=tmp->row ;
            int col=tmp->col ;
            
            if(col+1<arr[row].size()){
                node* next = new node(arr[row][col+1],row,col+1);
                pq.push(next) ;
            }
        }
        return ans ;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends