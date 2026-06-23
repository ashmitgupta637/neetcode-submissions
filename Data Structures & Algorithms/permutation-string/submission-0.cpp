class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char , int> freq ; 
        for(char c : s1) {
            freq[c]++ ; 
        } 
        int n = s1.length() ; 

        int left  = 0 ; 
        int right = 0 ; 
        unordered_map<char , int> freq2 ;
        for(int right = 0  ; right < s2.length() ; right++) {
            freq2[s2[right]]++ ; 
            if(right-left+1  >n) {
                freq2[s2[left]]-- ; 
                if(freq2[s2[left]] == 0 ) {
                    freq2.erase(s2[left] ) ; 

                }
                left++ ;
            } 
             
            if(freq2 ==  freq) {
                return true ; 
            }
        }
        return false  ;
        

        

    }
};
