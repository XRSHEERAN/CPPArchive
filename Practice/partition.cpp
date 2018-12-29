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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL)
            return NULL;
        ListNode *frtH=NULL,*endH=NULL,*front=NULL,*end=NULL;
        while(head){
            if(head->val<x){
                if(front==NULL){
                    front=new ListNode(head->val);
                    frtH=front;
                }
                else{
                    ListNode *temp=front;
                    front=new ListNode(head->val);
                    temp->next=front;
                }
            }
            else{
                if(end==NULL){
                    end=new ListNode(head->val);
                    endH=end;
                }
                else{
                    ListNode *temp=end;
                    end=new ListNode(head->val);
                    temp->next=end;
                }
            }
            head=head->next;
        }
        if(front){
            front->next=endH;
            return frtH;
        }
        return endH;
    }
};
