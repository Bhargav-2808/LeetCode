/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        int len = 1;
        
        if(head->next == NULL)
        {
            return NULL;
        }
        
        while(temp!=NULL)
        {
            len++;
            temp = temp->next;
        }
        int mid = len/2;
        int count=0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        if(len%2==0)
        {
             count=1;
        }
     
        
        while(count<mid)
        {
            prev = curr;
            curr= curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        
        return head;
    }
};