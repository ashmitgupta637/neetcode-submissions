class Solution {
public:

    bool matches(vector<int>& s1Map, vector<int>& s2Map){
        for(int i = 0; i < 26; i++){
            if(s1Map[i] != s2Map[i]){
                return false;
            }
        }
        return true;
    }


    bool checkInclusion(string s1, string s2) {

        if(s1.length() > s2.length()){
            return false;
        }

        vector<int> s1Map(26,0);
        vector<int> s2Map(26,0);


        // first window + s1 frequency
        for(int i = 0; i < s1.length(); i++){

            s1Map[s1[i] - 'a']++;

            s2Map[s2[i] - 'a']++;
        }


        // sliding window
        for(int i = 0; i < s2.length() - s1.length(); i++){

            if(matches(s1Map, s2Map)){
                return true;
            }


            // add new character
            s2Map[s2[i + s1.length()] - 'a']++;


            // remove old character
            s2Map[s2[i] - 'a']--;
        }


        // check last window
        return matches(s1Map, s2Map);
    }
};