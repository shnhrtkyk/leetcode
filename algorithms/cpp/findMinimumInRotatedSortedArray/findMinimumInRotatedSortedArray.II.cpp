class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;
            else if (nums[mid] < nums[right]) right = mid;
            else --right;
        }
        return nums[right];
    }
};

//class Solution {
//public:
//    int findMin(vector<int>& nums) {
//        return helper(nums, 0, (int)nums.size() - 1);
//    }
//    int helper(vector<int>& nums, int start, int end) {
//        if (start == end) return nums[start];
//        if (nums[start] < nums[end]) return nums[start];
//        int mid = (start + end) / 2;
//        return min(helper(nums, start, mid), helper(nums, mid + 1, end));
//    }
//};
