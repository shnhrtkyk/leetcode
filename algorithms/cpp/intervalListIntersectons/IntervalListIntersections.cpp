

/***************************************************************************************************** 
 *
 * Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted 
 * order.
 * 
 * Return the intersection of these two interval lists.
 * 
 * (Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= 
 * b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can 
 * be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)
 * 
 * Example 1:
 *    
 *             0   2     5      10     13           23 24 25
 *      A     +---+     +-------+     +-------------+  +--+
 *    
 *               1      5    8     12      15        24 25  26
 *      B        +------+    +------+      +----------+  +--+
 *    
 *              1  2    5    8  10         15      23 24 25
 *    Ans        ++     +    +--+          +--------+ +  +
 *    
 * 
 * Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
 * Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 * Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
 * 
 * Note:
 * 
 * 	0 <= A.length < 1000
 * 	0 <= B.length < 1000
 * 	0 <= A[i].start, A[i].end, B[i].start, B[i].end < 109
 * 
 ******************************************************************************************************/


class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = B.size();
        vector<vector<int>> res;
        int i = 0, j = 0;
        while (i < m && j < n) {
            auto p = A[i], q = B[j];
            int start = std::max(p[0], q[0]);
            int end = std::min(p[1], q[1]);
            if (start <= end) res.push_back({start, end});
            if (p[1] < q[1]) ++ i;
            else ++ j;
        }
        return res;
    }
};
