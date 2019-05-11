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
 faster than 100%
 memory less than 70%
 **/
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return {};
        if (!root->left and !root->right) 
        {
            if (root->val==sum) return {{root->val}};
            else return {};
        }
        
        vector<vector<int>> res;
        vector<int> cur;
        DFS(root, sum, res, cur);
        return res;
    }
    
    void DFS(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& cur){
        
        cur.push_back(root->val);
        if (sum==root->val && !root->left && !root->right) res.push_back(cur);
        else{ //very important, truncating... may work better if the signs are limited
            
            if (root->left) DFS(root->left, sum-root->val, res, cur);
            if (root->right) DFS(root->right, sum-root->val, res, cur);
        }
        cur.pop_back();
        
    }
};
