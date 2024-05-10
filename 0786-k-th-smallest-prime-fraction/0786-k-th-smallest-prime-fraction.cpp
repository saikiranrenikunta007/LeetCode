class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double,pair<int,int>>>ans;
        int n = arr.size();
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j) {
                
                ans.push_back({arr[i]/(1.0 * arr[j]),{arr[i],arr[j]}});
            }
        }
        sort(ans.begin(),ans.end());
        return {ans[k-1].second.first,ans[k-1].second.second};
    }
};