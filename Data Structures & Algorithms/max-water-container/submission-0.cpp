class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size() ; 
        int maxwater = 0 ; 
        int left = 0 ; 
        int right = n-1 ; 

        while(left < right) {
            int area = min(heights[left] , heights[right]) * (right -left ) ;
            maxwater = max(area , maxwater) ;  
            if(heights[right] > heights[left]) {
                left++ ;

            }else {
                right-- ;
            }
        }
        return maxwater ; 
    }
};
