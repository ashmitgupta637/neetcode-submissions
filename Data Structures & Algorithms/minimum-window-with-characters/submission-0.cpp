class Solution {
public:
    string minWindow(string s, string t) {
        string minstr = "" ;  
        int minLen = INT_MIN ; 
        unordered_map<char , int> freqt ; 

        for(char c: t) {
            freqt[c]++ ;
        }
        for(int i = 0 ;i < s.length() ; i++){
            
            for(int j = i ; j < s.length() ; j++ ) {
                string substr = s.substr(i , j-i+1) ;
                unordered_map<char , int > substring ; 
                for(char c : substr) {
                    substring[c]++ ; 

                } 
                bool isvalid = true  ; 
                for(auto const& [key , val] : freqt) {
                    if(substring[key] < val) {
                        isvalid = false ; 
                        break ; 
                    }
                }
                if(isvalid && minLen > substr.length() ) {
                    minLen = substr.length() ; 
                    minstr  = substr ;  
                }
            }
            
        }
        return minstr ; 
    }
};
