// class Solution {
// public:
//     int maxPoints(vector<vector<int>>& points) {
//         int res = 0;
//         for (int i = 0; i < points.size(); ++i) {
//             map<pair<int, int>, int> m;
//             int duplicate = 1;
//             for (int j = i + 1; j < points.size(); ++j) {
//                 if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
//                     ++duplicate; continue;
//                 }
//                 int dx = points[j][0] - points[i][0];
//                 int dy = points[j][1] - points[i][1];
//                 int d = gcd(dx, dy);
//                 ++m[{dx / d, dy / d}];
//             }
//             res = max(res, duplicate);
//             for (auto it = m.begin(); it != m.end(); ++it) {
//                 res = max(res, it->second + duplicate);
//             }
//         }
//         return res;
//     }
//     int gcd(int a, int b) {
//         return (b == 0) ? a : gcd(b, a % b);
//     }
// };

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            int duplicate = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                int cnt = 0;
                long long x1 = points[i][0], y1 = points[i][1];
                long long x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2 && y1 == y2) {++duplicate; continue;}
                for (int k = 0; k < points.size(); ++k) {
                    int x3 = points[k][0], y3 = points[k][1];
                    if (x1 * y2 + x2 * y3 + x3 * y1 - x3 * y2 - x2 * y1 - x1 * y3 == 0) {
                        ++cnt;
                    }
                }
                res = max(res, cnt);
            }
            res = max(res, duplicate);
        }
        return res;
    }
};
