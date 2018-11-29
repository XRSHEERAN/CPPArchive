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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr=head,*prev=NULL,*ret=NULL;
        int count=0,curr;
        while(ptr){
            curr=ptr->val;
            ListNode *temp=ptr;
            while(ptr && ptr->val==curr){
                ++count;
                ptr=ptr->next;
            }
            if(count==1){
                if(!prev){
                    prev=temp;
                    ret=prev;
                }
                else{
                    prev->next=temp;
                    prev=prev->next;
                }
                prev->next=NULL;
            }
            count=0;
        }
        return ret;
    }
};
