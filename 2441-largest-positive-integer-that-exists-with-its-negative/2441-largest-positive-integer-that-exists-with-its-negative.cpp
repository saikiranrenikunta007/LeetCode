class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        unordered_set<int>st;
        int ans=-1;
        for(auto &a : nums) {
            if(st.find(-a) != st.end()) {
                ans = max(abs(a),ans);
            }
            st.insert(a);
        }
        return ans;
    }
};