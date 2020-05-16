//
//  number-of-ways-of-cutting-a-pizza.cpp
//  
//
//  Created by takayuki shinohara on 2020/05/16.
//

//class Solution {
//public:
//    int ways(vector<string>& p, int k) {
//        int dp[15][55][55],n = p.size(),m = p[0].size(),mod = 1e9 + 7;
//        memset(dp,-1,sizeof dp);
//        vector<vector<int>>s(n + 1, vector<int>(m + 1));
//        for (int i = 0; i < n; i++)   //
//            for (int j = 0; j < m; j++)
//                s[i + 1][j + 1] = (p[i][j] == 'A') + s[i + 1][j] + s[i][j + 1] - s[i][j];
//        auto sumRegion = [&](int r1, int c1, int r2, int c2){  //
//            return s[r2 + 1][c2 + 1] - s[r1][c2 + 1] - s[r2 + 1][c1] + s[r1][c1];
//        };
//        function<int(int, int, int)> dfs = [&](int x, int y, int k)
//        {
//            if(k<=1)
//                return sumRegion(x, y, n-1, m - 1)>0?1:0; //
//            if (dp[k][x][y] != -1)
//                return dp[k][x][y];
//            long long ret = 0;
//            for (int i = x; i < n-1; i++)  //
//                if (sumRegion(x, y, i, m - 1))
//                    ret += dfs(i+1, y, k - 1);
//            for (int j = y; j < m-1; j++)  //
//                if (sumRegion(x, y, n-1,j))
//                    ret += dfs(x, j+1, k - 1);
//            return dp[k][x][y] = ret % mod;
//        };
//        return dfs(0, 0, k);
//    }
//};

//
//class Solution {
//    void add(long &a, long &b) { a = (a + b) % ((int) 1e9+7); }
//public:
//    int ways(vector<string>& A, int K) {
//        int M = A.size(), N = A[0].size();
//        vector<vector<int>> cnt(M + 1, vector<int>(N + 1));
//        for (int i = M - 1; i >= 0; --i) {
//            int s = 0;
//            for (int j = N - 1; j >= 0; --j) {
//                s += A[i][j] == 'A';
//                cnt[i][j] = cnt[i + 1][j] + s;
//            }
//        }
//        vector<vector<vector<long>>> dp(M + 1, vector<vector<long>>(N + 1, vector<long>(K + 1)));
//        for (int i = M - 1; i >= 0; --i) {
//            for (int j = N - 1; j >= 0; --j) {
//                dp[i][j][1] = 1;
//                for (int k = 2; k <= K; ++k) {
//                    for (int t = i + 1; t < M; ++t) {
//                        if (cnt[i][j] == cnt[t][j]) continue;
//                        if (cnt[t][j] == 0) break;
//                        add(dp[i][j][k], dp[t][j][k - 1]);
//                    }
//                    for (int t = j + 1; t < N; ++t) {
//                        if (cnt[i][j] == cnt[i][t]) continue;
//                        if (cnt[i][t] == 0) break;
//                        add(dp[i][j][k], dp[i][t][k - 1]);
//                    }
//                }
//            }
//        }
//        return dp[0][0][K];
//    }
//};

//
//class Solution {
//public:
//  int ways(vector<string>& pizza, int K) {
//    const int MOD = 1e9 + 7;
//    const int n = pizza.size();
//    const int m = pizza[0].length();
//    
//    int sum[n][m];
//    
//    for (int i = n - 1; i >= 0; i--)
//    for (int j = m - 1; j >= 0; j--) {
//      sum[i][j] = pizza[i][j] == 'A';
//      if (i < n - 1) sum[i][j] += sum[i + 1][j];
//      if (j < m - 1) sum[i][j] += sum[i][j + 1];
//      if (i < n - 1 && j < m - 1) sum[i][j] -= sum[i + 1][j + 1];
//    }
//    
//    int dp[n][m][K];
//    
//    for (int k = 0; k < K; k++)
//    for (int i = n - 1; i >= 0; i--)
//    for (int j = m - 1; j >= 0; j--)
//      if (k == 0) {
//        dp[i][j][k] = sum[i][j] > 0;
//      } else {
//        dp[i][j][k] = 0;
//        for (int ii = i + 1; ii < n; ii++)
//          if (sum[i][j] - sum[ii][j] > 0) {
//            dp[i][j][k] += dp[ii][j][k - 1];
//            dp[i][j][k] %= MOD;
//          }
//        for (int jj = j + 1; jj < m; jj++)
//          if (sum[i][j] - sum[i][jj] > 0) {
//            dp[i][j][k] += dp[i][jj][k - 1];
//            dp[i][j][k] %= MOD;
//          }
//      }
//    
//    return dp[0][0][K - 1];
//  }
//};


class Solution {
    int n, m;
    vector<string> pizza;
    typedef long long int LL;
    LL P = 1e9 + 7;
    LL g[55][55];
    LL f[55][55][15];
    
    int dp(int r, int c, int rest) {
        if (f[r][c][rest] != -1) return f[r][c][rest];
        
        if (rest == 0) {
            if (g[r][c] > 0) f[r][c][rest] = 1;
            else f[r][c][rest] = 0;
            return f[r][c][rest];
        }
        
        f[r][c][rest] = 0;
        
        // cut horizontally to [row, i-1] [i, n-1]
        for (int i = r + 1; i < n; i++) {
            if (g[r][c] - g[i][c] > 0 && g[i][c] >= rest) {
                f[r][c][rest] = (f[r][c][rest] + dp(i, c, rest - 1)) % P;
            }
        }
        
        // cut vertically to [col, j-1] [j, m-1]
        for (int j = c + 1; j < m; j++) {
            if (g[r][c] - g[r][j] > 0 && g[r][j] >= rest)
                f[r][c][rest] = (f[r][c][rest] + dp(r, j, rest - 1)) % P;
        }
        
        return f[r][c][rest];
    }
    
public:
    int ways(vector<string>& pizza, int k) {
        n = pizza.size();
        m = pizza[0].length();
        this->pizza = pizza;
        
        memset(g, 0, sizeof(g));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                g[i][j] = g[i][j+1];
                for (int l = i; l < n; l++)
                    g[i][j] += (pizza[l][j] == 'A');
            }
        }
        
        memset(f, -1, sizeof(f));
        
        return dp(0, 0, k-1);
    }
};
