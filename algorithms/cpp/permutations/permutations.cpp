class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        vector<int> out, visited(num.size(), 0);
        permuteDFS(num, 0, visited, out, res);
        return res;
    }
    void permuteDFS(vector<int>& num, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
        if (level == num.size()) {res.push_back(out); return;}
        for (int i = 0; i < num.size(); ++i) {
            if (visited[i] == 1) continue;
            visited[i] = 1;
            out.push_back(num[i]);
            permuteDFS(num, level + 1, visited, out, res);
            out.pop_back();
            visited[i] = 0;
        }
    }
};

// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& num) {
//         vector<vector<int>> res;
//         permuteDFS(num, 0, res);
//         return res;
//     }
//     void permuteDFS(vector<int>& num, int start, vector<vector<int>>& res) {
//         if (start >= num.size()) res.push_back(num);
//         for (int i = start; i < num.size(); ++i) {
//             swap(num[start], num[i]);
//             permuteDFS(num, start + 1, res);
//             swap(num[start], num[i]);
//         }
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& num) {
//         if (num.empty()) return vector<vector<int>>(1, vector<int>());
//         vector<vector<int>> res;
//         int first = num[0];
//         num.erase(num.begin());
//         vector<vector<int>> words = permute(num);
//         for (auto &a : words) {
//             for (int i = 0; i <= a.size(); ++i) {
//                 a.insert(a.begin() + i, first);
//                 res.push_back(a);
//                 a.erase(a.begin() + i);
//             }
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& num) {
//         vector<vector<int>> res{{}};
//         for (int a : num) {
//             for (int k = res.size(); k > 0; --k) {
//                 vector<int> t = res.front();
//                 res.erase(res.begin());
//                 for (int i = 0; i <= t.size(); ++i) {
//                     vector<int> one = t;
//                     one.insert(one.begin() + i, a);
//                     res.push_back(one);
//                 }
//             }
//         }
//         return res;
//     }
// };
