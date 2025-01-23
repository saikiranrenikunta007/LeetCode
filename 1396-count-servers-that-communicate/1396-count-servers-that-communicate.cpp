class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        

          int n = grid.size();
          int m = grid[0].size();
          vector<int>rows(n,0);
          vector<int>cols(m,0);

          for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){

                 if(grid[i][j]) {
                    rows[i]+=1;
                    cols[j]+=1;
                 }
            }
          }
          int count = 0;
          for(int i=0;i<n;++i){

            for(int j=0;j<m;++j){

                if(grid[i][j]) count+=(rows[i]>=2 || cols[j]>=2);
            }
          }
          return count;
    }
};