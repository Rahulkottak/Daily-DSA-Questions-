//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin(string S) {
        int n =S.length();
    //   initialize DP
       int dp[1000][1000]={0};
    // base condtion for 1 length of substring always a Palindromic
      for(int i=0;i<n;i++){
        dp[i][i]=1;
      }
    // base condtion for 2 length of substring is Palindromic if s[i]==s[i+1]
      for(int i=0;i<n-1;i++){
          if(S[i]==S[i+1]){
            dp[i][i+1]=1;
          }  
      }
    //for k length of substring is Palindromic if dp[i + 1][j - 1]==1 && s[i] == s[j]
       for(int k=3;k<=n;k++){
         for (int i = 0; i < n - k + 1; ++i) {
           
            int j = i + k - 1;
 
             if (dp[i + 1][j - 1]==1 && S[i] == S[j]) {
                dp[i][j] = 1;
             }

         }
       }
       // to find the max length substring you can uncomment both the cout to watch the 2d dp
        int ans=0;
         string str;
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            //   cout<<dp[i][j]<<" ";
               if(dp[i][j]==1){
                    int length =j-i+1;
                    if(length>ans){
                     ans=length;
                    str = S.substr(i,j-i+1);
               }

           }
          }
        //   cout<<endl;
        }


     return str;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends