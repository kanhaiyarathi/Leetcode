class Solution {
public:
    int climbStairs(int n) {
        int n1 = 1;
        int n2 = 2;
        if(n<=2)
            return n;
        int n3;
        for(int i=3;i<=n;i++){
            n3 = n1 + n2;       
            n1 = n2;
            n2 = n3;            
        }
        return n3;
    }
};
