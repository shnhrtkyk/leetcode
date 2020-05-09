// Recursion
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        string str1 = s1, str2 = s2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if (str1 != str2) return false;
        for (int i = 1; i < s1.size(); ++i) {
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
            s21 = s2.substr(s1.size() - i);
            s22 = s2.substr(0, s1.size() - i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
        }
        return false;
    }
};


// // DP
// class Solution {
// public:
//     bool isScramble(string s1, string s2) {
//         if (s1.size() != s2.size()) return false;
//         if (s1 == s2) return true;
//         int n = s1.size();
//         vector<vector<vector<bool>>> dp (n, vector<vector<bool>>(n, vector<bool>(n + 1)));
//         for (int len = 1; len <= n; ++len) {
//             for (int i = 0; i <= n - len; ++i) {
//                 for (int j = 0; j <= n - len; ++j) {
//                     if (len == 1) {
//                         dp[i][j][1] = s1[i] == s2[j];
//                     } else {
//                         for (int k = 1; k < len; ++k) {
//                             if ((dp[i][j][k] && dp[i + k][j + k][len - k]) || (dp[i + k][j][len - k] && dp[i][j + len - k][k])) {
//                                 dp[i][j][len] = true;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return dp[0][0][n];
//     }
// };

// // Still DP
// class Solution {
// public:
//     bool isScramble(string s1, string s2) {
//         if (s1.size() != s2.size()) return false;
//         if (s1 == s2) return true;
//         int n = s1.size();
//         vector<vector<vector<bool>>> dp (n, vector<vector<bool>>(n, vector<bool>(n + 1)));
//         for (int i = n - 1; i >= 0; --i) {
//             for (int j = n - 1; j >= 0; --j) {
//                 for (int k = 1; k <= n - max(i, j); ++k) {
//                     if (s1.substr(i, k) == s2.substr(j, k)) {
//                         dp[i][j][k] = true;
//                     } else {
//                         for (int t = 1; t < k; ++t) {
//                             if ((dp[i][j][t] && dp[i + t][j + t][k - t]) || (dp[i][j + k - t][t] && dp[i + t][j][k - t])) {
//                                 dp[i][j][k] = true;
//                                 break;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return dp[0][0][n];
//     }
// };

