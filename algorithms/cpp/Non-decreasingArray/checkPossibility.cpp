//
//  checkPossibility.cpp
//  
//
//  Created by takayuki shinohara on 2020/05/16.
//

//class Solution {
//public:
//    bool checkPossibility(vector<int>& nums) {
//        int cnt = 1, n = nums.size();
//        for (int i = 1; i < n; ++i) {
//            if (nums[i] < nums[i - 1]) {
//                if (cnt == 0) return false;
//                if (i == 1 || nums[i] >= nums[i - 2]) nums[i - 1] = nums[i];
//                else nums[i] = nums[i - 1];
//                --cnt;
//            }
//        }
//        return true;
//    }
//};

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() < 2)
            return true;
        int count = 0;
        vector<int>temp = nums;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i]>nums[i + 1])
            {
                if (i != 0)
                {
                    nums[i] = nums[i + 1];
                    i-=2;
                }
                count++;
            }
        }
        if (count<2)
            return true;
        count = 0;
        for (int i = 0; i < temp.size() - 1; i++)
        {
            if (temp[i]>temp[i + 1])
            {
                temp[i + 1] = temp[i];
                count++;
            }
        }
        if (count < 2)
            return true;
        return false;
    }
};
————————————————
版权声明：本文为CSDN博主「夏洛的网」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/liuxiao214/java/article/details/78128421
