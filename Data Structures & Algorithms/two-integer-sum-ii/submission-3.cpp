class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n =  numbers.size() ; 
        int left = 0  ; 
        int right = n-1 ; 

        while(left < right) {
            int remaining = target - numbers[left] ; 
            if(numbers[right] == remaining ) {
                return {left+1 , right+1} ; 
            }
            if(remaining  < numbers[right]) {
                right-- ;
            }
            if(remaining > numbers[right]) {
                left++ ; 
            }
        }
        return  {} ; 

    }
};
