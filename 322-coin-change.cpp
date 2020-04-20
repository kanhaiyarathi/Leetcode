class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int m = coins.size();
        if(m==0){
            return amount==0?0:-1;
        }
        int DP[m][amount+1];
        for(int i=0;i<m;i++){
            for(int j=0;j<=amount;j++){
                if(j==0)
                    DP[i][j]=0;
                else{
                    if(i>0)
                        DP[i][j]=DP[i-1][j];
                    else
                        DP[i][j]=INT_MAX;
                    if(j>=coins[i] && DP[i][j-coins[i]]!=INT_MAX){
                        DP[i][j]=min(DP[i][j],1+DP[i][j-coins[i]]);
                        //cout << DP[i][j]<<"   ";
                    }                        
                 }
            }                
        }
        /*
        for(int i=0;i<m;i++){
            for(int j=0;j<=amount;j++)
                cout << DP[i][j] << " ";
            cout << endl;
        }*/
        return DP[m-1][amount]!=INT_MAX?DP[m-1][amount]:-1;
    }
};
