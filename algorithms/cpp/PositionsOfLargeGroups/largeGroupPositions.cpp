class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int i=0,j=0; // two pointers (start & end)
        vector<vector<int>> res;
        for(int k=0;k<S.size();) {
            i=k;
            for(j=i+1;j<S.size();j++) {
                if(S.at(j)==S.at(i)) 
                    continue;
                else 
                    break;
            }
            if(j-i>=3) { // call a group large if it has 3 or more characters
                res.push_back({i,j-1}); // here is "j-1"
            }
            k=j; // avoid double counting of the same string
        }
        return res;
    }
};
