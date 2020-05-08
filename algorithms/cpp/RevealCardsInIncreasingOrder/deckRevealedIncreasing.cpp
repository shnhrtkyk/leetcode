class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // get the mapping
        queue<int> q;
        int n = deck.size();
        int ord2rev[n];
        for (int i = 0; i < n; i++)
            q.push(i);
        for (int i = 0; i < n; i++) {
            int x = q.front();
            q.pop();
            ord2rev[x] = i;
            if (!q.empty()) {
                x = q.front();
                q.pop();
                q.push(x);
            }
        }
        // sort
        sort(deck.begin(), deck.end());
        // apply reversed mapping
        vector<int> ans;
        for (int i = 0; i < n; i++)
            ans.push_back(deck[ord2rev[i]]);
        return ans;
    }
};
