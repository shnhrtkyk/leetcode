class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        /*
        A.length >= 3
        */
        int i=0;
        if(A.size()<3) {
            return false;
        }
        else {
            /*
            Walk up
            */
            while(i+1<A.size() && A.at(i)<A.at(i+1)) {
                i++;
            }
            if(i==0 || i==A.size()-1) {
                /*
                0 < i < A.length - 1
                */
                return false;
            }
            /*
            Walk down
            */
            while(i+1<A.size() && A.at(i)>A.at(i+1)) {
                i++;
            }
            return i==A.size()-1;
        }
    }
};
