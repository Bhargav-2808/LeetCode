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
    ListNode* detect(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        
        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }
        
        while(slow!=NULL && fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL) fast= fast->next;
            slow=slow->next;
            if(fast==slow) return slow;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
       /* map<ListNode*, bool> visited;
        if(head == NULL)
        {
            return NULL;
        }
        
        ListNode* temp = head;
        while(temp != NULL)
        {
            if(visited[temp] == true)
            {
                return temp;
            }
            
            visited[temp] = true;
            temp = temp ->next;
        }*/
        if(head == NULL)
        {
            return NULL;
        }
        ListNode* intersect = detect(head);
        if(intersect == NULL)
        {
            return NULL;
        }
        
        ListNode* slow = head;
        
        while(slow!=intersect)
        {
            slow=slow->next;
            intersect=intersect->next;
        }
            

        
        
        return slow;
    }
};