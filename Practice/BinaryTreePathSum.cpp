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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL) return false;
        else{
            int temp(sum-root->val);
            if(temp==0 && root->left==NULL && root->right ==NULL)
                return true;
            else
                return hasPathSum(root->left,temp) || hasPathSum(root->right,temp);
        }
    }
};
