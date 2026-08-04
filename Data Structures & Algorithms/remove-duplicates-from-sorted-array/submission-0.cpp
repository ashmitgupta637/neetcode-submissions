class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(); 
        set<int> visited ; 
        int i =0 ; 
        int k =  0 ; 
        while(i < n){
            if(!visited.count(nums[i])){
                visited.insert(nums[i]) ; 
                k++ ; 
                i++ ; 
            }else{
                i++; 
            }
        }
        vector<int> arr ; 
        for(int val : visited){
            arr.push_back(val) ; 
        }
        nums= arr ; 
        return k ; 
    }
};