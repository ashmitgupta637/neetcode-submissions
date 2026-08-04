class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size() ; 
        int left   = 0 ; 
        int right =  n-1; 
        while(left <= right) {
            int rem = target - nums[left] ; 
            if(nums[right] == rem) {
                return {left+1, right+1} ; 
            }
            else if(nums[right]  > rem ){
                right--     ; 

            }else{
                left++ ; 
            }
        }
        return {} ; 
    }
};
