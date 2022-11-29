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
    bool hasCycle(ListNode *head) {
        /*map<ListNode*, bool> visited;
        
        if(head == NULL)
        {
            return false;
        }
        
        ListNode* temp = head;
        while(temp != NULL)
        {
            if(visited[temp] == true)
            {
                return true;
            }
            
            visited[temp] = true;
            temp = temp ->next;
        }*/
        //floyed detection
        ListNode* slow = head;
        ListNode* fast = head;
        
        if(head == NULL || head->next == NULL )
        {
            return false;
        }
        
        while(slow!=NULL && fast!=NULL)
        {
            fast= fast ->next;
            if(fast!=NULL)
            {
                fast= fast->next;
            }
            slow=slow->next;
            
            if(slow==fast)
            {
                return true;
            }
        }
        
        
        return false;
    }
};