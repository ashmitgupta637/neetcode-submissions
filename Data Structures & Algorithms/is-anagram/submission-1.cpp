class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> freq1 ; 
        map<char ,  int> freq2 ; 
        if(s.length() != t.length()) {
            return false; 
        }
        for(int i =0 ; i < s.length() ; i++){
            freq1[s[i]]++ ; 

        }
        for(int i =0 ; i < t.length() ; i++){
            freq2[t[i]]++ ; 
            
        }
        if(freq1 == freq2) {
            return true  ; 
        }
        return false ; 
    }
};