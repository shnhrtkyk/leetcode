class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, iStar = -1, jStar = -1, m = s.size(), n = p.size();
        while (i < m) {
            if (j < n && (s[i] == p[j] || p[j] == '?')) {
                ++i; ++j;
            } else if (j < n && p[j] == '*') {
                iStar = i;
                jStar = j++;
            } else if (iStar >= 0) {
                i = ++iStar;
                j = jStar + 1;
            } else return false;
        }
        while (j < n && p[j] == '*') ++j;
        return j == n;
    }
};

// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int m = s.size(), n = p.size();
//         vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
//         dp[0][0] = true;
//         for (int i = 1; i <= n; ++i) {
//             if (p[i - 1] == '*') dp[0][i] = dp[0][i - 1];
//         }
//         for (int i = 1; i <= m; ++i) {
//             for (int j = 1; j <= n; ++j) {
//                 if (p[j - 1] == '*') {
//                     dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
//                 } else {
//                     dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
//                 }
//             }
//         }
//         return dp[m][n];
//     }
// };

// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         return helper(s, p, 0, 0) > 1;
//     }
//     int helper(string& s, string& p, int i, int j) {
//         if (i == s.size() && j == p.size()) return 2;
//         if (i == s.size() && p[j] != '*') return 0;
//         if (j == p.size()) return 1;
//         if (s[i] == p[j] || p[j] == '?') {
//             return helper(s, p, i + 1, j + 1);
//         }
//         if (p[j] == '*') {
//             if (j + 1 < p.size() && p[j + 1] == '*') {
//                 return helper(s, p, i, j + 1);
//             }
//             for (int k = 0; k <= (int)s.size() - i; ++k) {
//                 int res = helper(s, p, i + k, j + 1);
//                 if (res == 0 || res == 2) return res;
//             }
//         }
//         return 1;
//     }
// };
