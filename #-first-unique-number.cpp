//add funtion is O(n) which is not an optimal solution.
class FirstUnique {
public:
    queue<int> unique;
    
    unordered_map<int, int> freq;
    
    FirstUnique(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            add(nums[i]);      
    }
    
    int showFirstUnique() {
        if(unique.size()!=0)
            return unique.front();
        return -1;
    }
    
    void add(int value) {
        if(freq.find(value)==freq.end()){
            unique.push(value);            
            freq[value]=1;
        }else{
            freq[value]++;
            while(!unique.empty() && freq.find(unique.front())!=freq.end() && freq[unique.front()]>1)
                unique.pop();    
        }        
    }
    
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
