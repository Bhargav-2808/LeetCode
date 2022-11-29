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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, bool> visited;
        //map<int,int> index;
        //int count  =0;
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
            //index[count++] = count;
                        
            temp = temp ->next;
        }
        return NULL;
    }
};