class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1)
            return nums.size();
        int pt1=0,pt2=1,lst=1;
        
        while(pt2<nums.size()){
            if(pt1==0 || nums[pt1-1]!=nums[pt1] || nums[pt1]!=nums[pt2]){
                ++lst;
                nums[++pt1]=nums[pt2];
            }
            pt2++;
                
        }
        return lst;
    }
};
