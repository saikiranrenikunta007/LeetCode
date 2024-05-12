class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& mat) {
        
         int n = mat.size();
         vector<vector<int>>ans;
         for(int i=0;i<n-2;++i) {
              vector<int>temp;
              for(int j=0;j<n-2;++j) {
                   int mx = INT_MIN;
                   for(int k=i;k<i+3;++k){
                       for(int l=j;l<j+3;++l){
                           mx = max(mx,mat[k][l]);
                       }
                   }
                   temp.push_back(mx);
              }
              ans.push_back(temp);
         }
         return ans;
         
    }
};