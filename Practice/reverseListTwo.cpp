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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m==n)
            return head;
        
        int strt=1;
        ListNode *curr=head,*ptr=NULL,*prev=NULL,*ptrA=NULL,*ptrB=NULL;
        while(curr){
            if(strt==m){
                ptrB=new ListNode(curr->val);
                ++strt;
                prev=ptrB;
                while(strt<=n){
                    curr=curr->next;
                    ptr=new ListNode(curr->val);
                    ptr->next=prev;
                    prev=ptr;
                    ++strt;
                }
                ptrB->next=curr->next;
                if(ptrA)
                    ptrA->next=ptr;
                else
                    head=ptr;
                break;
            }
            ptrA=curr;
            curr=curr->next;
            ++strt;
        }
        return head;
    }
};
