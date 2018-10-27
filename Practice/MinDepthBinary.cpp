/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>;
#include <utility>;
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        std::queue <std::pair<TreeNode*,int>> myqueue; //Bfs
        myqueue.push(std::make_pair(root,1));
        std::pair<TreeNode*,int> temp;
        while(!myqueue.empty()){
            temp=myqueue.front();
            myqueue.pop();
            if(temp.first->left==NULL && temp.first->right==NULL){
                return temp.second;
            }
            if(temp.first->left!=NULL)
                myqueue.push(std::make_pair(temp.first->left,temp.second+1));
            if(temp.first->right!=NULL)
                myqueue.push(std::make_pair(temp.first->right,temp.second+1));
        }
        return 0;
    }
};
