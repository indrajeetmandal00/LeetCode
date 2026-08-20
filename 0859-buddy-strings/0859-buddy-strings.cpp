class Solution {
public:
    bool checkFreq(string &s){
        vector<int>v(26,0);

        for(char &ch:s){
            v[ch-'a']++;
            
            if(v[ch-'a']>1) return true;
        }
        return false;
    }
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()) return false;

        if(s==goal){
            return checkFreq(s);
        }

        vector<int>indices;
        for(int i=0;i<s.length();i++){
            if(s[i]!=goal[i]){
                indices.push_back(i);
            }
        }

        if(indices.size()!=2) return false;

        swap(s[indices[0]],s[indices[1]]);
        return s==goal;
    }
};