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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector<int> > ans;
        queue<TreeNode*> q;
        if(root == NULL) return ans;
        q.push(root);
        
        while(!q.empty())
        {
            int s = q.size();
            vector<int> temp(s);
            for(int i=0;i<s ;i++)
            {
                TreeNode* frontNode = q.front();
                q.pop();
                
                temp[i]=frontNode->val;
               
                if(frontNode->left)  q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
              
             }
            ans.push_back(temp);
        }
        return ans;
    }
};