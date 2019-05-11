/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /**
 faster than 99%
 **/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> solution;
        std::stack<TreeNode*> q;
        q.push(root);
        TreeNode* cur;
        while (!q.empty()){
            cur=q.top();
            q.pop();
            solution.push_back(cur->val);
            if (cur->right) q.push(cur->right);
            if (cur->left) q.push(cur->left);
        }
        return solution;
    }
};