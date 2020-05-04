class Solution {
public:
    int findComplement(int num) {
        long long ans = 0, powe = 1;
        do{
            bool bit = 1-(num%2);
            ans = ans + powe*bit;
            powe=2*powe;            
            num=num/2;
        }while(num!=0);
        return ans;
    }
};
