class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m=coins.size();
        if(m==0)
            return amount==0;
        int DP[m][amount+1];
        
        for(int i=0;i<m;i++){
            for(int j=0;j<=amount;j++){
                if(j==0){
                    DP[i][j]=1;
                }else if(i==0){
                    if(j>=coins[i])
                        DP[i][j]=DP[i][j-coins[i]];
                    else
                        DP[i][j]=0;
                }else{
                    DP[i][j]=DP[i-1][j];
                    
                    if(j>=coins[i])
                        DP[i][j]+=DP[i][j-coins[i]];
                }
            }
        }
        
    /*    for(int i=0;i<m;i++){
            for(int j=0;j<=amount;j++)
                cout <<DP[i][j] << "  ";
            cout <<endl;
        }
        */
        return DP[m-1][amount];
    }
};
