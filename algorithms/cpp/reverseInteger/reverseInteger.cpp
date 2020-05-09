class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (abs(res) > INT_MAX / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};

//class Solution {
//public:
//    int reverse(int x) {
//        long res = 0;
//        while (x != 0) {
//            res = 10 * res + x % 10;
//            x /= 10;
//        }
//        return (res > INT_MAX || res < INT_MIN) ? 0 : res;
//    }
//};
