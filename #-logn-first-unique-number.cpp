class FirstUnique {
public:
    
    unordered_map<int, list<int>::iterator> temp;
    list<int> dll;
    list<int> def;
    list<int>::iterator defaultIt;
    
    FirstUnique(vector<int>& nums) {
        def.push_back(-1);
        defaultIt = def.begin();
        
        for(int i=0;i<nums.size();i++)
            add(nums[i]);
    }
    
    int showFirstUnique() {
        if(dll.size()==0)
            return -1;
        return dll.front();
    }
    
    void add(int value) {
        if(temp.find(value)==temp.end()){
            dll.push_back(value);
            list<int>::iterator toPut = dll.end();
            --toPut;
            temp[value] = toPut;
        }else{
            if(temp[value] != defaultIt){
                list<int>::iterator point= temp[value];
                dll.erase(point);
                temp[value] = defaultIt;
            }                        
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
