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
    void insertAtTail(  ListNode* &ansHead,   ListNode* &ansTail,int digit)
    {
        ListNode* temp = new ListNode(digit);
        //empty list
        if(ansHead == NULL) {
            ansHead = temp;
            ansTail = temp;
            return;
        }
        else
        {
            ansTail -> next = temp;
            ansTail = temp;
        }
    }
    ListNode* addition(ListNode* &l1,ListNode* &l2)
    {
       int carry = 0;
        
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        
        while(l1 != NULL || l2 != NULL || carry != 0) {
            
            int val1 = 0;
            if(l1 != NULL)
                val1 = l1 -> val;
                
            int val2 = 0;
            if(l2 !=NULL)
                val2 = l2 -> val;
            
            
            int sum = carry + val1 + val2;
            
            int digit = sum%10;
            
            //create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            if(l1 != NULL)
                l1 = l1 -> next;
            
            if(l2 != NULL)
                l2 = l2 -> next;
        }
        return ansHead;
    }
    
    ListNode* reverse(ListNode* &temp1)
    {
        ListNode* temp = temp1;
        ListNode* prev = NULL;
        ListNode* forw = NULL;
        
        while(temp!=NULL)
        {
            forw = temp->next;
            temp->next=prev;
            prev=temp;
            temp=forw;
        }
        return prev;
    }
        
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //l1 = reverse(l1);        
        //l2 = reverse(l2);
        
        ListNode* ans = addition(l1,l2);
        ///ans = reverse(ans);
        return ans;

    }
};