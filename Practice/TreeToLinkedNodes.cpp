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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        helper(root);
    }
    TreeNode* helper(TreeNode *curr){
        if(!curr->left && !curr->right)
            return curr;
        if(!curr->right){
            curr->right=curr->left;
            curr->left=NULL;
            
        }
        else if(curr->left && curr->right){
            TreeNode *temp=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
            curr=helper(curr->right);
            curr->right=temp;
        }
        return helper(curr->right);
    } 
};
