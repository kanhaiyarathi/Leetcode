class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m==0)
            return 0;
        int n = grid[0].size();
        
        int DP[m][n];
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    DP[i][j]=grid[i][j];
                else if(i==0){
                    DP[i][j]=(DP[i][j-1] + grid[i][j]);
                }else if(j==0){
                    DP[i][j]=(DP[i-1][j] + grid[i][j]);
                }else{
                    DP[i][j]=grid[i][j];
                    DP[i][j]=min(DP[i][j]+DP[i-1][j], DP[i][j]+DP[i][j-1]);
                }
            }
        }
        /*
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                cout << DP[i][j] << "    ";
            cout << endl;
        }*/
        return DP[m-1][n-1];
    }
};
