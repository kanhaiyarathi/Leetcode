class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;
        for(int i=0;i<n;i++)
            if(nums[i]==0)
                nums[i]=-1;
        
        map<int, int> temp;
        int currSum = 0;
        
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            if(currSum==0){
                maxlen = i+1;
            }else{
                if(temp.find(currSum)!=temp.end()){
                    maxlen = max(maxlen, i-temp[currSum]);    
                }else
                    temp[currSum] = i;    
            }
        }
        
        return maxlen;
    }
};
