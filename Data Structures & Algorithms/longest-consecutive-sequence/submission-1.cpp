class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0 ;  
        int len =  1 ; 
        int maxlen = 1;
        sort(nums.begin() , nums.end() ) ; 
        for(int i = 0 ; i < nums.size()-1 ; i++) {
            if(nums[i+1] - nums[i] ==1) {
                len++ ; 


            }else if(nums[i+1]!= nums[i]){
                len = 1 ; 
            }
            maxlen = max(maxlen , len) ; 
            
        }
        return maxlen  ;

    }
};
