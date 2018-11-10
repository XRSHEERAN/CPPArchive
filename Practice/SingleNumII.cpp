class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int rounds=nums.size(),ret=0;
        
        for(int i=0;i<32;i++){
            int sum(0);
            for(int j=0;j<rounds;j++){
                sum+=(nums[j]&1);
                nums[j]>>=1;
            }
            ret+=(sum%3)<<i;
        }
        return ret;
    }
};
