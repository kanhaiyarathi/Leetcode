class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level=1;
        int levElem = 1;
        int totalElem =1;
        vector<int> ans;
        while(label>totalElem){
            levElem*=2;
            totalElem+=levElem;
            level++;
        }
        
        int oppoLabel = (totalElem-levElem)+(totalElem-label)+1;
        oppoLabel=oppoLabel/2;
        
        while(label!=0 || oppoLabel!=0){
            if(label!=0)
                ans.push_back(label);
            label=(label/2)/2;
            if(oppoLabel!=0)
                ans.push_back(oppoLabel);
            oppoLabel = (oppoLabel/2)/2;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
