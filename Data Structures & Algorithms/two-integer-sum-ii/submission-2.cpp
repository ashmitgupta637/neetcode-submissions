class Solution {
public:
    int binarysearch(int low ,  int remaining , vector<int> &num) {
        int high = num.size()-1 ; 
        while(low <= high) {
            int mid  = low +  (high- low )/2 ; 
            if(num[mid] == remaining ) {
                return mid ; 
            }
            else if(num[mid] < remaining) {
                low = mid +1 ; 
            }
            else{
                high = mid -1  ; 
            }
            
        }
        return -1 ; 
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int found = 0 ; 
        vector<int> ans ;  
        int n = numbers.size() ; 
        for(int i = 0 ; i < n  ; i++) {
            int remaining =  target - numbers[i]  ; 
            found = binarysearch(i+1 , remaining , numbers); 
            if(found != -1 ) {
                ans.push_back(i+1) ; 
                ans.push_back(found+1) ; 

            }
        }
        return ans ; 
        
        
    }
};
