class Solution {
public:
    
    string lshiftS(string s, int amt){
        cout << "lShift:"<<s << "->" << amt  << endl;
        int n = s.length();
        amt = amt%n;
        string firstHalf = "", secondHalf="";
        for(int i=0;i<amt;i++)
            secondHalf+=s[i];
        for(int i=amt;i<n;i++)
            firstHalf+=s[i];
        
        return firstHalf+secondHalf;
    }
    
    string rshiftS(string s, int amt){
       cout << "rShift:"<<s << "->" << amt  << endl;
        int n = s.length();
        amt = amt%n;
        string firstHalf = "", secondHalf="";
        for(int i=0;i<n-amt;i++)
            secondHalf+=s[i];
        for(int i=n-amt;i<n;i++)
            firstHalf+=s[i];
        
        return firstHalf+secondHalf;
        
    }
    
    string stringShift(string s, vector<vector<int>>& shift) {
        int ls = 0, rs =0;
        
        for(int i=0;i<shift.size();i++){
            if(shift[i][0]==0)
                ls+=shift[i][1];
            else
                rs+=shift[i][1];
        }
        if(ls==rs)
            return s;
        else if(ls>rs)
            return lshiftS(s, ls-rs);
        else
            return rshiftS(s,rs-ls);
    }
};
