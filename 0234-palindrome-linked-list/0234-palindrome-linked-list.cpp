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
public:

    bool isPalindrome(ListNode* head) {
        vector<int> data;
        
        ListNode* temp =head;
        while(temp!=NULL)
        {
            data.push_back(temp->val);
            temp=temp->next;
        }
        return reverse(data);
    
    }
};