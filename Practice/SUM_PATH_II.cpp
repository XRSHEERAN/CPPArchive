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
    vector<vector<int>> ret;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<int> temp;
        helper(temp,sum,root);
        return ret;
    }
    void helper(vector<int> temp,int sum, TreeNode* root){
        if(root==NULL)
            return;
        int tempN(sum-root->val);
        temp.push_back(root->val);
        if(tempN==0 && root->left==NULL && root->right==NULL)
            ret.push_back(temp);
        else{
            helper(temp,tempN,root->left);
            helper(temp,tempN,root->right);
        }
        return;
    }
};
