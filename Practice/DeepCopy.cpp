/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
#include <un_ordered_map>;
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return NULL;
        unordered_map<RandomListNode*,RandomListNode*> tbl;
        RandomListNode *ret=head,*curr=head;\
        while(ret){
            tbl.insert(make_pair(ret,new RandomListNode(ret->label)));
            ret=ret->next;
        }
        while(curr){
            ret=tbl.at(curr);
            if(curr->next)
                ret->next=tbl.at(curr->next);
            if(curr->random)
                ret->random=tbl.at(curr->random);
            curr=curr->next;
        }
        return tbl.at(head);
    }
};
