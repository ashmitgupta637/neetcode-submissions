class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ; 
        set<vector<int>>  ans ; 
        for(int i = 0; i < nums.size() ; i++) {
            
            if(i > 0 && nums[i] == nums[i-1]) {
                continue ; 
            } 
            unordered_set<int> hashmap ;
             
            int target   = -nums[i] ; 
            for(int j = i+1 ; j < nums.size() ; j++) {
                int compliment  = target  -  nums[j] ; 
                if(hashmap.count(compliment) > 0 ) {
                    ans.insert({nums[i] , nums[j] , compliment}) ; 
                }else {
                    hashmap.insert(nums[j]) ;
                }
            }
        }
        return vector<vector<int>>(ans.begin() , ans.end())  ; 
    }
};
