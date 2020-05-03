class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(256,0);
        for(int i=0;i<magazine.size();i++){
            count[magazine[i]]++;
        }
        
        for(int i=0;i<ransomNote.size();i++){
            if(count[ransomNote[i]]==0)
                return 0;
            count[ransomNote[i]]--;
        }
        
        return 1;
    }
};
