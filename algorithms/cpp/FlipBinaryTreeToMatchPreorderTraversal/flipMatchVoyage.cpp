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
    int i = 0;
    vector<int> res;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        res.clear();
        if (dfs(root, voyage)) {
            return res;
        }
        return {-1};
    }
    // can we get v by flip root?
    bool dfs(TreeNode* root, vector<int>& v) {
        if (!root) return true;
        if (root->val != v[i++]) return false;
        if (root->left && root->left->val == v[i]) {
            return dfs(root->left, v) && dfs(root->right, v);
        } else if (root->right && root->right->val == v[i]) {
            if (root->left)
                res.push_back(root->val);
            return dfs(root->right, v) && dfs(root->left, v);
        }
        return !root->left && !root->right;
    }
};
