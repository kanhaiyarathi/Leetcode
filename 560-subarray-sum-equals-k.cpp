class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();   
        map<int, int> temp;
        int currSum = 0, ans =0;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            if(currSum==k){
                ans++;
            }
            if(temp.find(currSum-k)!=temp.end()){
                ans+=temp[currSum-k];
            }
            if(temp.find(currSum)==temp.end()){
                temp[currSum]=1;
            }else
                temp[currSum]++;
        }
        return ans;
    }
};
