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
    int findPosition(vector<int>&inorder, int n, int element){
    for(int i=0;i<n;i++){
       if(element == inorder[i]){
           return i;
       }
    }    
    return -1;
}

TreeNode*solve(vector<int>& preorder, vector<int>& inorder,int &index , int n , int start,int end){
    if(index>=n || start>end){
        return NULL;
    }
    
    int element = preorder[index++];
    TreeNode*root = new TreeNode(element);
    int position = findPosition(inorder,n,element);
    
    root->left = solve(preorder, inorder, index, n, start,position-1);
    root->right = solve(preorder, inorder, index, n, position+1,end);
    return root;
    
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preorderIndex = 0;
    int n = preorder.size();
    TreeNode*ans = solve(preorder,inorder,preorderIndex,n,0,n-1);
    return ans;
}

};