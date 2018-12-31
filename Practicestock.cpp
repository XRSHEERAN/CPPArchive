class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //prices={1,2};
        if(prices.size()<2)
            return 0;
        int sell[prices.size()]{},buy[prices.size()]{},mx=0;
        buy[0]=-prices[0];
        for(int i=1;i<prices.size();++i){
            sell[i]=max(sell[i-1],buy[i-1]+prices[i]);
            //cout<<sell[i]<<','<<i;
            mx=(mx>sell[i])?mx:sell[i];
            if(i==1){
                buy[1]=max(-prices[0],-prices[1]);
                continue;
            }
            buy[i]=max(buy[i-1],sell[i-2]-prices[i]);
            
        }
        return mx;
    }
};
