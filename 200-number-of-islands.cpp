class Solution {
public:
    bool isSafe(int i, int j, int m, int n){
        return (i>=0 && i<m && j>=0 && j < n);
    }
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited,int i, int j, int m, int n){
        visited[i][j]=1;
       // cout << " i:" << i << "    j:" << j << endl;
        int x[]={0,0,1,-1};
        int y[]={1,-1,0,0};
        
        for(int k=0;k<4;k++){
            int newi =i +x[k], newj = j+y[k];
            if(isSafe(newi, newj, m,n) && grid[newi][newj]=='1' && visited[newi][newj]==0)
                dfs(grid, visited, newi, newj, m, n);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m==0)
            return 0;
        int n = grid[0].size();
        
        vector<vector<bool>> visited;
        vector<bool> temp(n,0);
        
        for(int i=0;i<m;i++)
            visited.push_back(temp);
    
        int ans=0;
        //cout << "m:"<<m << "   n:" << n << endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    dfs(grid, visited, i,j,m,n);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
