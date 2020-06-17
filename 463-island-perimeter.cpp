class Solution {
public:
    bool isSafe(int i, int j, int m, int n){
        if(i>=0 && i < m && j >=0 && j <n)
            return 1;
        return 0;
    }
    
    int openFaces(vector<vector<int>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[i][j]==0)
            return 0;
        int count = 0;
        
        int x[]={1, -1 ,0, 0};
        int y[]={0, 0, 1, -1};
        
        for(int k =0;k<4;k++){
            int newi = i + x[k];
            int newj = j + y[k];
            if(!isSafe(newi, newj, m, n))
                count++;
            else{
                count+=(1-grid[newi][newj]);
            }
                
        }
        
        return count;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans += openFaces(grid, i,j);
            }
        }
        return ans;
    }
};
