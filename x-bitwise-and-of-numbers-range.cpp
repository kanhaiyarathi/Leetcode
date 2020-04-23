class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        /* just to make an observvation 
        for(int i=m;i<=n;i++){
            for(int j=31;j>=0;j--)
            {
              bool x = i&(1<<j);  
              cout << x ;
            } 
            cout << endl;
        }*/
        
        for(int i=0;i<32;i++){
            if(m&(1<<i)){
                if(n&(1<<i)){
                    //cout << "both digit 1" << endl;
                    // cout << n-m+1 << "  >=   " << pow(2,i)+1 << endl;
                    if(n-m+1>=pow(2,i)+1){
                        m = m & ~(1<<i);    
                        //cout << m << endl;
                    }                        
                }else
                    m = m & ~(1<<i);
            }    
        }
        return m;
    }
};
