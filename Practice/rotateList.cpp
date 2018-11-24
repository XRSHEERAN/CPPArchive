/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        stack<ListNode*> stk;
        ListNode *curr=head;
        int n=0;
        while(curr){
            stk.push(curr);
            n++;
            curr=curr->next;
        }
        if(n==0)
            return head;
        k%=n;
        if(k==0)
            return head;
        curr=stk.top();
        curr->next=head;
        stk.pop();
        ListNode *prev=curr;
        while(k>1){
            curr=stk.top();
            curr->next=prev;
            stk.pop();
            prev=curr;
            k--;
        }
        stk.top()->next=NULL;
        return curr;
    }
};
