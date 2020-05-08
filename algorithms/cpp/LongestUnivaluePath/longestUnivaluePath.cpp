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
    int longestUnivaluePath(TreeNode* root) {
        if(root == nullptr) return 0;
        int res = 0;
        getPath(root, res);
        return res;
    }
private:
    int getPath(TreeNode* root, int &res){
        if(root == nullptr) return 0;
        int l = getPath(root->left, res);
        int r = getPath(root->right, res);
        int pl = 0, pr = 0;
        if(root->left && (root->left->val == root->val)) pl = l + 1;
        if(root->right && (root->right->val == root->val)) pr = r + 1;
        res = max(res, pl + pr);
        return max(pl, pr);
    }
};
