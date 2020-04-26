class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        int DP[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0)
                    DP[i][j]=0;
                else{
                    DP[i][j]=0;
                    if(text1[i-1]==text2[j-1])
                        DP[i][j]=DP[i-1][j-1]+1;
                    DP[i][j]=max(DP[i][j], max(DP[i-1][j],DP[i][j-1]));
                }
            }
        }
        
        return DP[m][n];
    }
};
