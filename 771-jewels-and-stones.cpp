class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<bool> isSpec(256, 0);
        
        for(int i=0;i<J.length(); i++){
            isSpec[J[i]]=1;
        }
        int ans = 0;
        for(int i=0;i<S.length(); i++){
            ans+=isSpec[S[i]];
        }
        
        return ans;
    }
};
