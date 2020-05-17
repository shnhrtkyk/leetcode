//
//  submissions.cpp
//  
//
//  Created by takayuki shinohara on 2020/05/17.
//
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
    void solve(TreeNode *rt, int ma, int &ans) {
        if (!rt)
            return;

        if (ma <= rt->val)
            ans++;

        solve(rt->left, max(ma, rt->val), ans);
        solve(rt->right, max(ma, rt->val), ans);
    }

    int goodNodes(TreeNode* root) {
        int ans = 0;
        solve(root, INT_MIN, ans);
        return ans;
    }
};


