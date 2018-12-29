class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int,int> tbl;
        for(int i=0;i<nums.size();i++){
            if(tbl.find(nums[i])==tbl.end()){
                tbl[nums[i]]=1;
                continue;
            }
            ++tbl[nums[i]];
        }
        
        vector<int> keys{};
        for(auto pr : tbl)
            keys.push_back(pr.first);
        vector<vector<int>> ret{};
        ret.push_back({});
        helper(ret,{},keys,tbl,0);
        return ret;
    }
    void helper(vector<vector<int>>& ret, vector<int> par, vector<int> keys, unordered_map<int,int>& tbl, int pos){
        for(int i=pos;i<keys.size();++i){
            vector<int> temp=par;
            temp.push_back(keys[i]);
            ret.push_back(temp);
            if(tbl[keys[i]]>1){
                --tbl[keys[i]];
                helper(ret,temp,keys,tbl,i);
                ++tbl[keys[i]];
            }
            else
                helper(ret,temp,keys,tbl,i+1);
        }
    }
};
