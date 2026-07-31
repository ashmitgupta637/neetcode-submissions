class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // mp = { key1 : [s1  , s2] , key2 :[s3, s5]} --> it(key1 -->key2) ; 
        // vector<vector<string>> ans ; 
        // ans.push_back(it.second)
        // ans = [[s1  , s2] , [s3, s5]  ]   <<--- ans ; 

        unordered_map<string , vector<string>> mp ; 
        for(string s : strs) {
            vector<int> freq(26 , 0) ;
            
            for(char c  : s){
                freq[c - 'a']++ ; 
            }

            string key  = "" ; 
            for(int i = 0 ; i < freq.size() ; i++){
                key += to_string(freq[i]) +'x' ; 
            }

            mp[key].push_back(s) ; 

        }

        vector<vector<string>> ans  ; 

        for(auto it  :  mp) {
            ans.push_back(it.second) ; 
        }

        return ans  ; 

    }
};
