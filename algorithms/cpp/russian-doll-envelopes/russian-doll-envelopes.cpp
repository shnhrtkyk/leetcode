class Solution {
    
public:
    int maxEnvelopes(vector<vector<int>>& xs) {
        int n = xs.size();
        if(n<=1) return n;

        vector<int> f(n, 1);
        f[0] = 1;

        sort(begin(xs), end(xs),
             [](const vector<int>&a, const vector<int>& b) { return a[0]<b[0] || (a[0]==b[0] && a[1]<b[1]); });

        int res = 1;
        for(int i=1; i<n; i++) {
            for(int j=i-1; j>=0; j--) {
                if(xs[i][0] > xs[j][0] && xs[i][1] > xs[j][1]) f[i] = max(f[i], 1+f[j]);
            }
            res = max(res, f[i]);
        }

        return res;
        
    }
};
