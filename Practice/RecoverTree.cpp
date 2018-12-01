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
    void recoverTree(TreeNode* root) {
        TreeNode *first=NULL,*second=NULL,*pre=NULL;
        preOrder(first,second,pre,root);
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
    }
    //sort the bst to order
    void preOrder(TreeNode* &first,TreeNode* &second,TreeNode* &pre,TreeNode* curr){
        if(!curr)
            return;
        preOrder(first,second,pre,curr->right);
        if(!pre)
            pre=curr;
        else{
            if(pre->val<curr->val){
                if(!first)
                    first=pre;
                second=curr;
            }
            else
                pre=curr;
        }
        preOrder(first,second,pre,curr->left);
    }
};
