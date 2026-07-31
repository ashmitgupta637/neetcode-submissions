class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() ; 
        int candi  = 0 ; 
        int cnt = 0  ;
        for(int i = 0 ; i < n ; i++){
            if(cnt == 0 ) candi = nums[i] ; 

            if(candi == nums[i]) {
                cnt++ ; 
            }else {
                cnt-- ; 
            }
        }

        return candi  ; 
    }
};