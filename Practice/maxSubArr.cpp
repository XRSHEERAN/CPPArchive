class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int dp[nums.size()+1]{};
        int max=nums[0];
        for(int i=0;i<nums.size();++i){
            dp[i+1]=dp[i] > 0? dp[i]+nums[i] : nums[i];
            max=(max>dp[i+1])?max:dp[i+1];
        }
        return max;
    }
};
