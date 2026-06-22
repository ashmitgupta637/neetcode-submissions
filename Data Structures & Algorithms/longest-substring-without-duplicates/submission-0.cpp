class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 1) {
            return 1 ; 

        }
        if(s == "" || s.length() == 0 ) {
            return 0 ; 
        }
        int n = s.length() ; 
        int ans = 0 ; 

        int left  = 0  ; 
        int right  = 0 ; 
        unordered_set<int> hashmap  ; 
        while(right< n) {
            char c  = s[right] ; 
            while(hashmap.count(c) > 0) {
                hashmap.erase(s[left]) ; 
                left++ ; 
            }
            hashmap.insert(c) ;
            
            ans = max(ans , right-left+1) ; 
            right++ ; 
            
        } 
        return ans ;
    }
};
