class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char , int> mapT ; 

        for(char c  : t) {
            mapT[c]++ ; 
        }

        int required = mapT.size() ; 
        int create  = 0 ; 

        unordered_map<char , int> substring ; 
        vector<int> ans = {-1 , 0 , 0 } ; 
        int l = 0 ; 
        int r = 0 ; 
    
        while(r < s.length()) {
            char c = s[r] ; 
            substring[c]++ ; 

            if(mapT.count(c) && mapT[c] == substring[c]) {
                create++ ; 
            }
            while(l <= r && create == required) {
                char leftchar = s[l];
                int len = r - l + 1 ; 
                
                
                if(ans[0] == -1 || len < ans[0]) {
                    ans[1] = l ; 
                    ans[2] = r ; 
                    ans[0] = len ;  
                }
                substring[leftchar]-- ; 

                
                if(mapT.count(leftchar) && substring[leftchar] < mapT[leftchar] ) {
                    create-- ;
                }
                l++ ;
            }
            r++ ; 
        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
    }
};