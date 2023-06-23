//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        vector<int> mp(26,0);
        int max_freq=0,count_maxfreq=0;
        for(char i:tasks){
            mp[i-'A']++ ;
            if(mp[i-'A']>max_freq){
                max_freq=mp[i-'A'];
            }
        }

        for(int i=0;i<26;i++){
            if(mp[i]==max_freq){
                count_maxfreq++ ;
            }
        }
        int time = (max_freq-1)*(K+1) + count_maxfreq ;
        return max(time,N);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends