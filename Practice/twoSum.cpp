#include <unordered_map>;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> tbl;
        int ptr=0;
        vector<int> ret;
        for(int i : nums)
            tbl[i]=ptr++;
        for(int i=0;i<nums.size();i++){
            if(tbl[target-nums[i]]>i){
                return {i,tbl[target-nums[i]]};
            }
        }
        return ret;
    }
};
