/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    void insertTail(Node* &cloneHead, Node* &cloneTail, int val)
    {
        Node*  temp = new Node(val);
        if(cloneHead == NULL)
        {
            cloneHead = temp;
            cloneTail = temp;
            return;
        }
        else
        {
            cloneTail->next=temp;
            cloneTail = temp;
        }
    }
public:
   
    
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        unordered_map<Node*, Node*> mapData;
        
        Node* temp = head;
        while(temp!=NULL)
        {
            insertTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode!= NULL && cloneNode!=NULL)
        {
            mapData[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode=cloneNode->next;
        }
        
        originalNode = head;
        cloneNode = cloneHead;
        
        
        while(originalNode!= NULL)
        {
            cloneNode->random = mapData[originalNode->random];
            originalNode = originalNode->next;
            cloneNode=cloneNode->next;
            
        }
        return cloneHead;
        
    }
};