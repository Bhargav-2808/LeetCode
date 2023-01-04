/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
    unordered_map<int, int>mp;
    int findPosition(vector<int>&inorder, int n, int element){
    for(int i=0;i<n;i++){
       if(element == inorder[i]){
           return i;
       }
    }    
    return -1;
}


    TreeNode* make_tree(int start, int end, int &preIdx, vector<int>& preorder, vector<int>& inorder,int n){
        
        if(start > end || preIdx>=n ) return NULL;
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        
        int pos = mp[root->val];
        
        root->left = make_tree(start, pos-1, preIdx, preorder, inorder,n);
        root->right = make_tree(pos+1, end, preIdx, preorder, inorder,n);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        for(int i=0; i<n; i++){
            
            mp[inorder[i]] = i;
        }
        return make_tree(0,n-1, idx, preorder, inorder,n);
    }
};