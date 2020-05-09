class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
        for (int k = 0; k < (int)nums.size() - 2; ++k) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            int target = 0 - nums[k], i = k + 1, j = (int)nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    res.push_back({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1]) ++i;
                    while (i < j && nums[j] == nums[j - 1]) --j;
                    ++i; --j;
                } else if (nums[i] + nums[j] < target) ++i;
                else --j;
            }
        }
        return res;
    }
};

//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        set<vector<int>> res;
//        sort(nums.begin(), nums.end());
//        if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
//        for (int k = 0; k < (int)nums.size() - 2; ++k) {
//            if (nums[k] > 0) break;
//            int target = 0 - nums[k], i = k + 1, j = (int)nums.size() - 1;
//            while (i < j) {
//                if (nums[i] + nums[j] == target) {
//                    res.insert({nums[k], nums[i], nums[j]});
//                    while (i < j && nums[i] == nums[i + 1]) ++i;
//                    while (i < j && nums[j] == nums[j - 1]) --j;
//                    ++i; --j;
//                } else if (nums[i] + nums[j] < target) ++i;
//                else --j;
//            }
//        }
//        return vector<vector<int>>(res.begin(), res.end());
//    }
//};
