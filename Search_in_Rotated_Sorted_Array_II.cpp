class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return matching(nums,target,0,nums.size()-1);
    }
    bool matching(vector<int> & nums, int target, int lft, int rgt){
        if(lft>rgt)
            return false;
        int mid=(lft+rgt)/2, R=nums[rgt], M=nums[mid], L=nums[lft];
        if(target==L || target==M || target==R)
            return true;
        else if(L==R && L==M)
            return matching(nums,target,mid+1,rgt-1) || matching(nums,target,lft+1,mid-1);
        else if(M<target){
            if(target<R || R<M || M==L)
                return matching(nums,target,mid+1,rgt-1);
            return matching(nums,target,lft+1,mid-1);
        }
        if(target>L || M==R || L>M)
            return matching(nums,target,lft+1,mid-1);
        return matching(nums,target,mid+1,rgt-1);
    }
};
