//class Solution {
//public:
//    int jump(vector<int>& nums) {
//        int res = 0, n = nums.size(), i = 0, cur = 0;
//        while (cur < n - 1) {
//            ++res;
//            int pre = cur;
//            for (; i <= pre; ++i) {
//                cur = max(cur, i + nums[i]);
//            }
//            if (pre == cur) return -1; // May not need this
//        }
//        return res;
//    }
//};

class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, n = nums.size(), last = 0, cur = 0;
        for (int i = 0; i < n - 1; ++i) {
            cur = max(cur, i + nums[i]);
            if (i == last) {
                last = cur;
                ++res;
                if (cur >= n - 1) break;
            }
        }
        return res;
    }
};
