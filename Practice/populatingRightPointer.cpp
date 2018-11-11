/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        helper(root);
        if(root->left)
            connect(root->left);
        else if(root->right)
            connect(root->right);
        else
            connect(root->next);
    }
    TreeLinkNode* helper(TreeLinkNode *root){
        if(!root)
            return NULL;
        else if(!root->left && !root->right){ //node with no children
            cout<<root->val<<0<<';';
            return helper(root->next);
        }
        else if(root->left && root->right){
            cout<<root->val<<1;
            root->left->next=root->right;
            root->right->next=helper(root->next);
        }
        else if(!root->left){
            cout<<root->val<<2;
            root->right->next=helper(root->next);
            return root->right;
        }
        else{
            cout<<root->val<<3;
            root->left->next=helper(root->next);
        }
        
        return root->left;
    }
};
