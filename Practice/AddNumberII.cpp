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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> tbl1,tbl2;
        while(l1){
            tbl1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            tbl2.push(l2->val);
            l2=l2->next;
        }
        ListNode* ptr=new ListNode(0);
        ListNode* temp;
        int leftover=0,curr=0,temp1=0,temp2=0;
        while(!tbl1.empty() || !tbl2.empty()){
            
            if(tbl1.empty()){
                temp2=tbl2.top();
                tbl2.pop();
                temp1=0;
            }
            else if(tbl2.empty()){
                temp1=tbl1.top();
                tbl1.pop();
                temp2=0;
            }
            else{
                temp1=tbl1.top();
                temp2=tbl2.top();
                tbl1.pop();
                tbl2.pop();
            }
            
            curr=temp1+temp2+leftover;
            if(curr>9)
                leftover=1;
            else
                leftover=0;
            
            ptr->val=curr%10;
            cout<<ptr->val<<','<<temp1<<','<<temp2<<'\n';
            temp=ptr;
            ptr= new ListNode(0);
            ptr->next=temp;
        }
        if(leftover==1){
            ptr->val=1;
        }
        else
            ptr=temp;
        return ptr;
    }
};
