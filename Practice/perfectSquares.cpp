#include <vector>
class Solution {
public:
    int numSquares(int n) {
        
        vector<int> tbl;
        int curr=1;
        while(curr*curr<=n){
            tbl.push_back(curr*curr);
            ++curr;
        }
        
        int dp[n+1]={},len(tbl.size());
        
        for(int i=1;i<=n;i++){
            int ptr=0;
            while(ptr<len && tbl[ptr]<=i){
                int temp=tbl[ptr];
                if(dp[i]==0)
                    dp[i]=dp[i-temp]+1;
                else
                    dp[i]=dp[i]>(dp[i-temp]+1)?(dp[i-temp]+1):dp[i];
                ptr++;
            }
            
        }
        return dp[n];
    }
};
