class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<1)
            return 0;
        int buy[prices.size()+1],sell[prices.size()+1],coolb[prices.size()+1],cools[prices.size()+1];
        buy[0]=-1*prices.at(0),coolb[0]=-1*prices.at(0),cools[0]=0,sell[0]=0;
        for(int i=0;i<prices.size();i++){
            buy[i+1]=cools[i]-prices.at(i);
            sell[i+1]=max(buy[i],coolb[i])+prices.at(i);
            cools[i+1]=max(sell[i],cools[i]);
            coolb[i+1]=max(buy[i],coolb[i]);
        }
        int temp=prices.size();
        return max(sell[temp],cools[temp]);
    }
};
