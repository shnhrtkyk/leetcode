class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    if (words.empty() || s.empty()) return {};
    
    const int n = words.size();
    const int l = words[0].length();
    
    if (n * l > s.length()) return {};
    
    std::string_view ss(s);
    
    std::unordered_map<std::string_view, int> expected;
    
    for (const string& word : words)
      ++expected[string_view(word)];
 
    vector<int> ans;
    
    for (int i = 0; i <= ss.length() - n * l; ++i) {      
      std::unordered_map<std::string_view, int> seen;
      int count = 0;
      for (int j = 0; j < n; ++j) {
        std::string_view w = ss.substr(i + j * l, l);
        auto it = expected.find(w);
        if (it == expected.end()) break;
        if (++seen[w] > it->second) break;
        ++count;
      }
      if (count == n) 
        ans.push_back(i);
    }
    return ans;
  }
};
