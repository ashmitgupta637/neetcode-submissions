class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea = 0 ; 
        stack<int> st ;  
        int  n = heights.size() ; 

        for(int i = 0; i <= n ; i++) {
            int currht ; 
            if(i == n ) {
                currht = 0 ; 
            }
            else{
                currht = heights[i] ; 
            }
            while(!st.empty() && currht < heights[st.top()]) {
                int height  = heights[st.top()] ; 
                st.pop() ; 
                int width ; 

                if(st.empty()) {
                    width = i ; 
                }else{
                    width = i - st.top() -1 ; 

                }

                maxarea = max(maxarea , height*width)  ; 
            }
            st.push(i) ; 

        }
        return maxarea ; 
    }
};
