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
    ListNode* reverse_(ListNode* &head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode* smallhead = reverse_(head->next);
        head->next->next = head;
        head->next = NULL;
        return smallhead;
    }
public:
    ListNode* reverseList(ListNode* head) {
       
        return reverse_(head);
        /*
            ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr!=NULL)
        {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
        */
    }
};