class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int mv=0,ptr2=0;
        while(ptr2<nums.size()){
            if(nums[ptr2]==0)
                mv++;
            else
                nums[ptr2-mv]=nums[ptr2];
            ptr2++;
        }
        int addin=nums.size()-mv;
        while(mv-->0)
            nums[addin++]=0;
    }
};
