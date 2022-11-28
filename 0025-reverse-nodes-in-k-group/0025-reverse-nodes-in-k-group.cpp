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
    int lenLin(ListNode* head)
    {
        int len = 0;
        ListNode* temp = head;
        while(temp!= NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        if(head == NULL)
        {
            return NULL;
        }
        
        int tempCount = lenLin(head);
        
        if(tempCount<k) return head;
        
        int count = 0;
        while(curr!= NULL && count<k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        
        if(next!=NULL)
        {
            head->next = reverseKGroup(next,k);
        }
        return prev;
    }
};