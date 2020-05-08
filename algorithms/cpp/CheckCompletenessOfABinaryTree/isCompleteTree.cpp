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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (!node) break;
            q.push(node->left);
            q.push(node->right);
        }
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node)
                return false;
        }
        return true;
    }
};
