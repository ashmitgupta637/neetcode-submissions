class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> count  ; 

        for(int n : nums) {
            count[n]++ ; 
        }

        priority_queue<pair<int , int> , vector<pair<int, int>>, greater<pair<int , int>>> heap ; 

        for(auto it : count) {
            heap.push({it.second , it.first}) ; 
            if(heap.size() > k ) {
                heap.pop() ; 
            }
        }
        vector<int> ans  ; 
        while(!heap.empty()){
            ans.push_back(heap.top().second);       
            heap.pop() ;  
        }
        return ans  ; 
    }
};
