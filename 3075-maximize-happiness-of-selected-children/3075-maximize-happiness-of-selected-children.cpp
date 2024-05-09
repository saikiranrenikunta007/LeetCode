class Solution {
public:
    long long maximumHappinessSum(vector<int>& a, int k) {
        
        sort(a.begin(),a.end(),greater<int>());
        int i=0;
        long long ans=0;
        while(k--) {
            ans += max(a[i]-i,0);
            i++;
        }
        return ans;
    }
};