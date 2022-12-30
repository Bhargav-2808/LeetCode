/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL) 
        {
            return NULL;
        }
        
        if(root== p || root == q) return root;
        
        TreeNode* leftNode = solve(root->left,p,q);        
        TreeNode* rightNode = solve(root->right,p,q);
        
        if(leftNode && rightNode) 
            return root;
        else if(leftNode == NULL && rightNode) 
            return rightNode;
        else if(leftNode && rightNode==NULL)
            return leftNode;
        else
            return NULL;
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        
        return solve(root, p, q);
    }
};