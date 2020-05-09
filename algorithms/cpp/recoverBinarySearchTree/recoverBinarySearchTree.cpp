// // O(n) space complexity
// class Solution {
// public:
//     void recoverTree(TreeNode* root) {
//         vector<TreeNode*> list;
//         vector<int> vals;
//         inorder(root, list, vals);
//         sort(vals.begin(), vals.end());
//         for (int i = 0; i < list.size(); ++i) {
//             list[i]->val = vals[i];
//         }
//     }
//     void inorder(TreeNode* root, vector<TreeNode*>& list, vector<int>& vals) {
//         if (!root) return;
//         inorder(root->left, list, vals);
//         list.push_back(root);
//         vals.push_back(root->val);
//         inorder(root->right, list, vals);
//     }
// };


// Now O(1) space complexity
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *cur = root, *pre = nullptr ;
        while (cur) {
            if (cur->left){
                TreeNode *p = cur->left;
                while (p->right && p->right != cur) p = p->right;
                if (!p->right) {
                    p->right = cur;
                    cur = cur->left;
                    continue;
                } else {
                    p->right = NULL;
                }
            }
            if (pre && cur->val < pre->val){
              if (!first) first = pre;
              second = cur;
            }
            pre = cur;
            cur = cur->right;
        }
        swap(first->val, second->val);
    }
};
