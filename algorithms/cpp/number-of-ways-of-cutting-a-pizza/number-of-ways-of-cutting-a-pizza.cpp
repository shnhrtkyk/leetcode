//
//  number-of-ways-of-cutting-a-pizza.cpp
//  
//
//  Created by takayuki shinohara on 2020/05/16.
//

class Solution {
public:
    int ways(vector<string>& p, int k) {
        int dp[15][55][55],n = p.size(),m = p[0].size(),mod = 1e9 + 7;
        memset(dp,-1,sizeof dp);
        vector<vector<int>>s(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; i++)   //
            for (int j = 0; j < m; j++)
                s[i + 1][j + 1] = (p[i][j] == 'A') + s[i + 1][j] + s[i][j + 1] - s[i][j];
        auto sumRegion = [&](int r1, int c1, int r2, int c2){  //
            return s[r2 + 1][c2 + 1] - s[r1][c2 + 1] - s[r2 + 1][c1] + s[r1][c1];
        };
        function<int(int, int, int)> dfs = [&](int x, int y, int k)
        {
            if(k<=1)
                return sumRegion(x, y, n-1, m - 1)>0?1:0; //
            if (dp[k][x][y] != -1)
                return dp[k][x][y];
            long long ret = 0;
            for (int i = x; i < n-1; i++)  //
                if (sumRegion(x, y, i, m - 1))
                    ret += dfs(i+1, y, k - 1);
            for (int j = y; j < m-1; j++)  //
                if (sumRegion(x, y, n-1,j))
                    ret += dfs(x, j+1, k - 1);
            return dp[k][x][y] = ret % mod;
        };
        return dfs(0, 0, k);
    }
};
