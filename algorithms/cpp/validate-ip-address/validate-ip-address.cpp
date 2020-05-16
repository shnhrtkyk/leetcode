//
//  validate-ip-address.cpp
//  
//
//  Created by takayuki shinohara on 2020/05/16.
//
//
//class Solution {
//public:
//    string validIPAddress(string IP) {
//        const int N = IP.size();
//        int i = 0;
//        int cnt = 0;
//        int parts = 0;
//        if (IP.find('.') != string::npos) {
//            while (i < N) {
//                if (!isdigit(IP[i])) return "Neither";
//                
//                // leading zero
//                if (IP[i] == '0' && i + 1 < N && isdigit(IP[i + 1])) return "Neither";
//                
//                int j = i;
//                int n = 0;
//                while (i < N && isdigit(IP[i])) {
//                    if (i - j + 1 > 3) return "Neither";
//                    n = n * 10 + IP[i++] - '0';
//                }
//                if (n > 255) return "Neither";
//                
//                if (i < N && IP[i] != '.') return "Neither";
//                if (i < N && IP[i] == '.') ++cnt;
//                ++i;
//                ++parts;
//            }
//            return cnt == 3 && parts == 4 ? "IPv4" : "Neither";
//        } else if (IP.find(':') != string::npos) {
//            static const unordered_map<char, int> v6{
//                {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9},
//                {'a', 10}, {'b', 11}, {'c', 12}, {'d', 13}, {'e', 14}, {'f', 15},
//                {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}
//            };
//            
//            while (i < N) {
//                if (!v6.count(IP[i])) return "Neither";
//                    
//                int j = i;
//                int n = 0;
//                while (i < N && v6.count(IP[i])) {
//                    if (i - j + 1 > 4) return "Neither";
//                    n = n * 16 + v6.at(IP[i++]);
//                }
//                if (n > 0xffff) return "Neither";
//                
//                // leading zero
//                if (IP[j] == '0' && j + 4 < i) return "Neither";
//                
//                if (i < N && IP[i] != ':') return "Neither";
//                if (i < N && IP[i] == ':') ++cnt;
//                ++i;
//                ++parts;
//            }
//            return cnt == 7 && parts == 8 ? "IPv6" : "Neither";
//        }
//        return "Neither";
//    }
//};

class Solution {
public:
    string validIPAddress(string IP) {
        istringstream is(IP);
        string t = "";
        int cnt = 0;
        if (IP.find(':') == string::npos) { // Check IPv4
            while (getline(is, t, '.')) {
                ++cnt;
                if (cnt > 4 || t.empty() || (t.size() > 1 && t[0] == '0') || t.size() > 3) return "Neither";
                for (char c : t) {
                    if (c < '0' || c > '9') return "Neither";
                }
                int val = stoi(t);
                if (val < 0 || val > 255) return "Neither";
            }
            return (cnt == 4 && IP.back() != '.') ? "IPv4" : "Neither";
        } else { // Check IPv6
            while (getline(is, t, ':')) {
                ++cnt;
                if (cnt > 8 || t.empty() || t.size() > 4) return "Neither";
                for (char c : t) {
                    if (!(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F')) return "Neither";
                }
            }
            return (cnt == 8 && IP.back() != ':') ? "IPv6" : "Neither";
        }
    }
};
