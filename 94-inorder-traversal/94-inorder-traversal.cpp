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
    void recursiveTraversal(TreeNode* node, vector<int>& res) {
        if (node != NULL) {
            recursiveTraversal(node->left, res);
            res.push_back(node->val);
            recursiveTraversal(node->right, res);
        } else return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorderTraversal;
        recursiveTraversal(root, inorderTraversal);
        return inorderTraversal;
    }
};