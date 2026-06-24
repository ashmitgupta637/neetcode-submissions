class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int cnt = 0 ; 
        vector<int> res; 
        for(int i = 0 ; i < temperatures.size() ; i++) {
            bool found  = false ; 
            for(int j =  i+1 ; j < temperatures.size() ; j++) {
                cnt++ ; 
                if(temperatures[i] < temperatures[j]) {
                    res.push_back(cnt) ; 
                    cnt =  0 ; 
                    found = true   ; 
                    break ;

                    
                }
            } 
            if(found == false) {
                res.push_back(0) ; 
            }
            cnt  = 0 ;
        }
        return res; 
    }
};
