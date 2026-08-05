class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ; 
        if(n == 0) return 0 ; 
        int total = 0 ;  
        for(int i =  0 ; i< n ;i++){
            int left = height[i] ; 
            int right = height[i]  ; 

            for(int j = 0 ; j < i; j++){
                left = max(left , height[j]) ; 
            }

            for(int j = i ; j < n ; j++){
                right = max(right , height[j]) ; 
            }

            total+= min(left , right) - height[i]  ; 

        }

        return total ; 
    }
};
