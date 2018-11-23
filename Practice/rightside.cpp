/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return vector<int>({});
        vector<int> retV={};
        queue<TreeNode*> outer;
        outer.push(root);
        
        while(!outer.empty()){
            queue<TreeNode*> temp;
            int ret;
            while(!outer.empty()){
                TreeNode* curr=outer.front();
                if(curr->left){
                    temp.push(curr->left);
                }
                if(curr->right)
                    temp.push(curr->right);
                outer.pop();
                ret=curr->val;
            }
            retV.push_back(ret);
            outer=temp;
        }
        
        return retV;
    }
};
