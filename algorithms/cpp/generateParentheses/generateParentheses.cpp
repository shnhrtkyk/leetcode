class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisDFS(n, n, "", res);
        return res;
    }
    void generateParenthesisDFS(int left, int right, string out, vector<string> &res) {
        if (left > right) return;
        if (left == 0 && right == 0) res.push_back(out);
        else {
            if (left > 0) generateParenthesisDFS(left - 1, right, out + '(', res);
            if (right > 0) generateParenthesisDFS(left, right - 1, out + ')', res);
        }
    }
};


//class Solution {
//public:
//    vector<string> generateParenthesis(int n) {
//        unordered_set<string> st;
//        if (n == 0) st.insert("");
//        else {
//            vector<string> pre = generateParenthesis(n - 1);
//            for (auto a : pre) {
//                for (int i = 0; i < a.size(); ++i) {
//                    if (a[i] == '(') {
//                        a.insert(a.begin() + i + 1, '(');
//                        a.insert(a.begin() + i + 2, ')');
//                        st.insert(a);
//                        a.erase(a.begin() + i + 1, a.begin() + i + 3);
//                    }
//                }
//                st.insert("()" + a);
//            }
//        }
//        return vector<string>(st.begin(), st.end());
//    }
//};
