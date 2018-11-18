class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        int ptr=1,dp[amount+1]={};
        while(ptr<=amount){
            int i=0;
            while(i<coins.size()){
                int temp(coins[i++]);
                if(temp>ptr)
                    continue;
                else if(ptr!=temp && dp[ptr-temp]==0)
                    continue;
                else if(dp[ptr]==0)
                    dp[ptr]=dp[ptr-temp]+1;
                else
                    dp[ptr]=(dp[ptr]>(dp[ptr-temp]+1))?(dp[ptr-temp]+1):dp[ptr];
            }
            ++ptr;
        }
        return dp[amount]>0?dp[amount]:-1;
    }
};
