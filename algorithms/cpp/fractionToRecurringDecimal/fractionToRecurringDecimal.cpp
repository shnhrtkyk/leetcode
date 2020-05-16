
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        if(!numerator)  return "0";
        if(numerator<0 ^ denominator<0)
            res += '-';
        long num = abs(long(numerator));
        long den = abs(long(denominator));
        long quotient = num/den;
        if(num%den == 0)
            return res += to_string(abs(num/den));
        
        res += to_string(quotient);
        res += '.';
        long rmd = num%den;
        unordered_map<long, long> m;
        while(rmd){
            if(m.find(rmd)!=m.end()){
                res.insert(m[rmd], 1, '(');
                res+=')';
                break;
            }
            m[rmd] = res.size();
            res += to_string(rmd*10/den);
            rmd = (rmd*10%den);
            
        }
        return res;
    }

};
//
//class Solution {
//public:
//    string fractionToDecimal(int numerator, int denominator) {
//        if (numerator == 0) return "0";
//        
//        string integer_part;
//        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
//            integer_part += "-";
//        
//        int64_t dividend = abs((int64_t)numerator);
//        int64_t divisor = abs((int64_t)denominator);
//        if (dividend < divisor) integer_part += "0";
//        
//        while (dividend >= divisor) {
//            integer_part += to_string(dividend / divisor);
//            dividend %= divisor;
//            // cout << "integer part: " << integer_part << endl;
//        }
//        
//        if (dividend == 0) return integer_part;
//        
//        string decimal_part;
//        // {dividend, quotient}
//        vector<pair<int, int>> dq;
//        unordered_set<int> dividends;
//        while (true) {
//            dividend *= 10;
//            int quotient = dividend / divisor;
//            int remainder = dividend % divisor;
//            
//            // printf("%d / %d = %d * %d + %d\n", dividend, divisor, divisor, quotient, remainder);
//            
//            if (remainder == 0) {
//                for (auto& p : dq)
//                    decimal_part += to_string(p.second);
//                decimal_part += to_string(quotient);
//                break;
//            } else if (dividends.count(dividend)) {
//                for (auto& p : dq) {
//                    if (p.first == dividend)
//                        decimal_part += "(";
//                    decimal_part += to_string(p.second);
//                }
//                decimal_part += ")";
//                break;
//            }
//            
//            dq.push_back({dividend, quotient});
//            dividends.insert(dividend);
//            dividend = remainder;
//        }
//        return integer_part + "." + decimal_part;
//    }
//};
