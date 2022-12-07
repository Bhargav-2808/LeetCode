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
    bool reverse(vector<int> &data)
    {
        int i = 0;
        int j = data.size()-1;
        while(i<j)
        {
            if(data[i++]!=data[j--])
            {
                return false;
            }
        }
        
        return true;
    }
    
    ListNode* middle_list(ListNode* &head)
    {
        ListNode*  slow = head;
        ListNode*  fast = head->next;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            fast =fast->next->next;
            slow=slow->next;
        }
        return slow;
        
    }
    
    ListNode* reverse_list(ListNode* &temp1)
    {
        ListNode* prev = NULL;
        ListNode* temp = temp1;
        
        while(temp!=NULL)
        {
             ListNode*  forward = temp->next;
             temp->next = prev;
             prev= temp;
             temp=forward;
        }
        return prev;
       
        
    }
public:

    bool isPalindrome(ListNode* head) {
       /* vector<int> data;
        
        ListNode* temp =head;
        while(temp!=NULL)
        {
            data.push_back(temp->val);
            temp=temp->next;
        }
        return reverse(data);
        */
        
        //approch 2
        ListNode* middle = middle_list(head);
        ListNode* temp = middle->next;
        middle->next = reverse_list(temp);
        
        ListNode* head1 = head;
        ListNode* head2 = middle->next;
        
        while(head2!=NULL)
        {
            if(head1->val!=head2->val)
            {
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
      
        
        //temp = middle->next;
        //middle->next = reverse_list(temp);
        return true;

        
    }
};