class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, mx = 0, n = height.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = mx;
            mx = max(mx, height[i]);
        }
        mx = 0;
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = min(dp[i], mx);
            mx = max(mx, height[i]);
            if (dp[i] > height[i]) res += dp[i] - height[i];
        }
        return res;
    }
};


// class Solution {
// public:
//   int trap(vector<int>& height) {
//     const int n = height.size();
//     vector<int> l(n);
//     vector<int> r(n);
//     int ans = 0;
//     for (int i = 0; i < n; ++i)
//       l[i] = i == 0 ? height[i] : max(l[i - 1], height[i]);
//     for (int i = n - 1; i >= 0; --i)
//       r[i] = i == n - 1 ? height[i] : max(r[i + 1], height[i]);
//     for (int i = 0; i < n; ++i)
//       ans += min(l[i], r[i]) - height[i];
//     return ans;
//   }
// };


// class Solution {
// public:
//   int trap(vector<int>& height) {
//     const int n = height.size();
//     if (n == 0) return 0;
//     int l = 0;
//     int r = n - 1;
//     int max_l = height[l];
//     int max_r = height[r];
//     int ans = 0;
//     while (l < r) {      
//       if (max_l < max_r) {
//         ans += max_l - height[l];
//         max_l = max(max_l, height[++l]);
//       } else {
//         ans += max_r - height[r];
//         max_r = max(max_r, height[--r]);
//       }
//     }
//     return ans;
//   }
// };
