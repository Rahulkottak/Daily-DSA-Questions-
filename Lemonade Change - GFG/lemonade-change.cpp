//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &b) {
        // code here
        int five=0;
        int ten=0;
        for(int i=0;i<N;i++){
            if(b[i]==5){
                five++;
            }
            else if(b[i]==10){
                five--;
                ten++;
            }
            else{
                if(ten==0)
                five=five-3;
                else{
                ten--;
                five--;
                }
            }
            if(five<0)
                return false;
        }
        
        if(five<0 || ten<0)
            return false;
        else
            return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends