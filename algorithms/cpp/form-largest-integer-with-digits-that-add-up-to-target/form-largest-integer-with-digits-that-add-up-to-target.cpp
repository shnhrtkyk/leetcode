//
//  form-largest-integer-with-digits-that-add-up-to-target.cpp
//  
//
//  Created by takayuki shinohara on 2020/05/17.
//

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> f(target + 1, INT_MIN);

        f[0] = 0;
        for (int i = 0; i < 9; i++)
            for (int j = cost[i]; j <= target; j++)
                f[j] = max(f[j], f[j - cost[i]] + 1);

        if (f[target] < 0)
            return "0";

        string ans;
        for (int i = 8, j = target; i >= 0; i--) {
            while (j >= cost[i] && f[j] == f[j - cost[i]] + 1) {
                ans += to_string(i + 1);
                j -= cost[i];
            }
        }

        return ans;
    }
};


