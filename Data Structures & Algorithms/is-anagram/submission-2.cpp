class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false ; 

        vector<int> countchar(26, 0) ; 
        for(int i  = 0 ; i < s.length() ; i++) {
            countchar[s[i] - 'a']++ ; 
            countchar[t[i]-'a']-- ; 

        }
        for(auto count : countchar){
            if(count  != 0){
                return false ; 
            }
        }
        return true ; 

    }
};
