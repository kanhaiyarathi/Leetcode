class Solution { 
public:
    bool overlap(vector<int> I1, vector<int> I2){
        if(I1[1] >= I2[0])
            return 1;
        return 0;
    }
    
    vector<vector<int>> mergeInterval(vector<vector<int>>& intervals){
        vector<vector<int>> ans;
        int n = intervals.size();
        
        for(int i=0;i<n;i++){
            int last = ans.size()-1;
            if(i!=0 && overlap(ans[last],intervals[i])){                
                ans[last][1] =max(ans[last][1], intervals[i][1]);
            }else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i= 0;
        while(i<n && intervals[i][0]<newInterval[0]){
            i++;
        }
        intervals.insert(intervals.begin()+i, newInterval);
        return mergeInterval(intervals);
        
    }
};
