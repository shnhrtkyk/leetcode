class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        string res;
        int size = 2 * numRows - 2, n = s.size();
        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < n; j += size) {
                res += s[j];
                int pos = j + size - 2 * i;
                if (i != 0 && i != numRows - 1 && pos < n) res += s[pos];
            }
        }
        return res;
    }
};

//class Solution {
//public:
//    string convert(string s, int numRows) {
//        if (numRows <= 1) return s;
//        string res;
//        int i = 0, n = s.size();
//        vector<string> vec(numRows);
//        while (i < n) {
//            for (int pos = 0; pos < numRows && i < n; ++pos) {
//                vec[pos] += s[i++];
//            }
//            for (int pos = numRows - 2; pos >= 1 && i < n; --pos) {
//                vec[pos] += s[i++];
//            }
//        }
//        for (auto &a : vec) res += a;
//        return res;
//    }
//};
