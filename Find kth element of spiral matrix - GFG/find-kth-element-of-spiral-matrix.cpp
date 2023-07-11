//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    int findK(int a[MAX][MAX],int n,int m,int k){
 		int sRow=0,sCol=0;
 		int eRow=n-1 , eCol=m-1 ;
 		
 		int cnt=0;
 		
 		while(sRow <= eRow && sCol <= eCol){
 		    for(int index=sCol;index<=eCol ; index++){
                cnt++;
                if(cnt==k) return a[sRow][index];
 		    }
 		    sRow++;
 		    for(int index=sRow;index<=eRow ; index++){  
                cnt++;
                if(cnt==k) return a[index][eCol];
 		    }
 		    eCol--;
 		    for(int index=eCol;index>=sCol ; index--){
                cnt++;
                if(cnt==k) return a[eRow][index];
 		    }
 		    eRow--;
 		    for(int index=eRow;index>=sRow;index--){
                cnt++;
                if(cnt==k) return a[index][sCol];
 		    }
 		    sCol++;
 		}
 		return -1 ;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends