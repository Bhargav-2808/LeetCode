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
    
    TreeNode* make_tree(int start, int end, int &postIdx, vector<int>& postorder, vector<int>& inorder){
        
        if(start > end) return NULL;
        TreeNode* root = new TreeNode(postorder[postIdx--]);
        int pos = mp[root->val];
        root->right = make_tree(pos+1, end, postIdx, postorder, inorder);
        root->left = make_tree(start, pos-1, postIdx, postorder, inorder);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int idx = n-1;
        for(int i=0; i<n; i++){
            
            mp[inorder[i]] = i;
        }
        return make_tree(0,n-1, idx, postorder, inorder);
    }
};
