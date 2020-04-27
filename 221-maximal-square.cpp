class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m==0)
            return 0;
        int n = matrix[0].size();
        
        int DP[m][n];
        int ans = 0;        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 ||j==0){
                    DP[i][j] = matrix[i][j]-'0';
                }else{
                    if(matrix[i][j]=='1'){
                        DP[i][j] = 1 + min(DP[i-1][j-1], min(DP[i-1][j], DP[i][j-1]));    
                    }else
                        DP[i][j]=0;
                }
                ans = max(ans, DP[i][j]);
            }
        }
        return ans*ans;
    }
};
