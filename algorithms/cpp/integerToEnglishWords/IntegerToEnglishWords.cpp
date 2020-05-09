// Author: Huahua
constexpr char * kUnder20[] = {"One", "Two", "Three", "Four", "Five",
                               "Six", "Seven", "Eight", "Nine","Ten",
                               "Eleven", "Twelve", "Thirteen", "Fourteen",
                               "Fifteen", "Sixteen", "Seventeen", "Eighteen",
                               "Nineteen"};
constexpr char * kUnder100[] = {"Twenty", "Thirty", "Forty", "Fifty",
                                "Sixty", "Seventy", "Eighty", "Ninety"};
constexpr char * kHTMB[] = {"Hundred", "Thousand", "Million", "Billion"};
constexpr long kP[] = {100, 1000, 1000*1000, 1000*1000*1000};
 
class Solution {
public:
  string numberToWords(int n) {
    if (n == 0) return "Zero";
    return convert(n).substr(1);
  }
private:
  string convert(int n) {
    if (n == 0) return "";
    if (n < 20) return string(" ") + kUnder20[n - 1]; // 1 - 19
    if (n < 100) return string(" ") + kUnder100[n / 10 - 2] + convert(n % 10); // 20 ~ 99
    for (int i = 3; i >= 0; --i)
      if (n >= kP[i]) return convert(n / kP[i]) + " " + kHTMB[i] + convert(n % kP[i]);
    return "";
  }
};
