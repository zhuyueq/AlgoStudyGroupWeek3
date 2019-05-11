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
 faster than 87%
 **/
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        if (!root->left and !root->right) return {to_string(root->val)};
        vector<string> solution;
        for (string str:binaryTreePaths(root->left)) solution.push_back(to_string(root->val)+"->"+str);
        for (string str:binaryTreePaths(root->right)) solution.push_back(to_string(root->val)+"->"+str);
        return solution;
    }
};