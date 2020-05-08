class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        const int N = A.size();
        int pos, i;
        for (pos = N; pos > 0; pos--) {
            for (i = 0; A[i] != pos; i ++);
            reverse(A.begin(), A.begin() + i + 1);
            if (i != 0)
                res.push_back(i + 1);
            reverse(A.begin(), A.begin() + pos);
            res.push_back(pos);
        }
        return res;
    }
};
