class Solution {
public:
  bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> counts;
    for (int card : deck) ++counts[card];
    for (int i = 2; i <= deck.size(); ++i) {
      if (deck.size() % i) continue;
      bool ok = true;
      for (const auto& pair : counts)
        if (pair.second % i) {
          ok = false;
          break;
        }
      if (ok) return true;
    }
    return false;
  }
};

// class Solution {
// public:
//     bool hasGroupsSizeX(vector<int>& deck) {
//         unordered_map<int, int> counter;
//         for (int d : deck) {
//             counter[d] ++;
//         }
//         int res = 0;
//         for (auto& c : counter) {
//             res = gcd(c.second, res);
//         }
//         return res > 1;
//     }
//     int gcd(int x, int y) {
//         return y == 0 ? x : gcd(y, x % y);
//     }
// };






// class Solution {
// public:
//   bool hasGroupsSizeX(vector<int>& deck) {
//     unordered_map<int, int> counts;
//     for (int card : deck) ++counts[card];
//     int X = deck.size();
//     for (const auto& p : counts) 
//       X = __gcd(X, p.second);
//     return X >= 2;
//   }
// };
