class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> memo(m, vector<int>(n));
        return helper(word1, 0, word2, 0, memo);
    }
    int helper(string& word1, int i, string& word2, int j, vector<vector<int>>& memo) {
        if (i == word1.size()) return (int)word2.size() - j;
        if (j == word2.size()) return (int)word1.size() - i;
        if (memo[i][j] > 0) return memo[i][j];
        int res = 0;
        if (word1[i] == word2[j]) {
            return helper(word1, i + 1, word2, j + 1, memo);
        } else {
            int insertCnt = helper(word1, i, word2, j + 1, memo);
            int deleteCnt = helper(word1, i + 1, word2, j, memo);
            int replaceCnt = helper(word1, i + 1, word2, j + 1, memo);
            res = min(insertCnt, min(deleteCnt, replaceCnt)) + 1;
        }
        return memo[i][j] = res;
    }
};
