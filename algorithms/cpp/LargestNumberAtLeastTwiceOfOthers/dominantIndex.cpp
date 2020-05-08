class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        /*
        First determine the size of the vector nums
        */
        if(nums.size()<2) {
            /*
            nums will have a length in the range [1, 50]
            */
            return 0;
        }
        else if(nums.size()==2) {
            /*
            In order to reduce memory consumption
            */
            if(nums.at(0)>=2*nums.at(1)) {
                return 0;
            }
            else if(nums.at(1)>=2*nums.at(0)) {
                return 1;
            }
            else {
                return -1;
            }
        }
        else {
            map<int,int>locationOfElement;
            for(int i=0;i<nums.size();i++) {
            /*
            Record the location of the original array
            */
            locationOfElement[nums.at(i)]=i; 
            }
            sort(nums.begin(),nums.end(),greater<int>());
            /*
            Sort the array from larger to smaller
            */
            if(nums.at(0)>=2*nums.at(1)) {
                return locationOfElement[nums.at(0)];
            }
        }
        return -1;
    }
};
