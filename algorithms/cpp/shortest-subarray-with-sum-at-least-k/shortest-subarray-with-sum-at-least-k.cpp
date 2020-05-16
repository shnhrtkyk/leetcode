//
//  shortest-subarray-with-sum-at-least-k.cpp
//
//
//  Created by takayuki shinohara on 2020/05/16.
//
//愚直
// class Solution {
// public:
//     int shortestSubarray(vector<int>& A, int K) {
//         //
//         vector<long long int> frontSum(A.size()+1, 0);
//         for(int i = 1; i <= A.size(); ++i)
//         {
//             frontSum[i] = frontSum[i-1] + A[i-1];
//         }

//         int ans = -1;
//         //
//         for(int i = 0; i < A.size(); ++i)
//         {
//             for(int j = i; j < A.size(); ++j)
//             {
//                 if(frontSum[j+1] - frontSum[i] >= K && (ans == -1 || ans > j+1-i))
//                 {
//                     ans = j+1-i;
//                     break;
//                 }
//             }
//         }

//         return ans;

//     }
// };

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        vector<long long int> frontSum(A.size()+1, 0);

        for(int i = 1; i <= A.size(); ++i)
        {
            frontSum[i] = frontSum[i-1] + A[i-1];
        }

        int ans = -1;

        deque<int> begCandidates;

        for(size_t end = 0; end <= A.size(); ++end)
        {

            while(!begCandidates.empty() && frontSum[end] - frontSum[begCandidates.back()] <= 0)
            {
                begCandidates.pop_back();
            }


            while(!begCandidates.empty() && frontSum[end] - frontSum[begCandidates.front()] >= K)
            {
                int beg = begCandidates.front();
                begCandidates.pop_front();

                if(ans == -1) ans = end - beg;
                else ans = min(ans, (int)end - beg);
            }

            begCandidates.push_back(end);
        }

        return ans;

    }
};
