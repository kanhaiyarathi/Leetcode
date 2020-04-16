class Solution {
public:
    bool checkValidString(string s) {
        int n =s.length();
        if(n==0)
            return 1;
        int DP[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                DP[i][j]=0;
        }
        
        for(int len=1;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j = i+len-1;
                if(len==1){
                    if(s[i]=='*')
                        DP[i][j]=1;
                    else
                        DP[i][j]=0;
                }else{
                    if(s[i]==')' || s[j]=='(')
                        DP[i][j]=0;
                    else{
                        if(len==2){
                            DP[i][j]=1;
                        }else{                            
                            DP[i][j]=DP[i+1][j-1];
                            if(s[i]=='*'){
                                DP[i][j]|=DP[i+1][j];
                            }
                            for(int k=i+1;k<j;k++){
                                if(s[k]==')'||s[k]=='*')
                                    DP[i][j] |=(DP[i][k]&DP[k+1][j]);
                            }
                            
                        }
                    }
                }
            }
        }
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout <<DP[i][j] << "    ";
            cout << endl;
        }*/
        return DP[0][n-1];
    }
};
