class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> freq ; 
         
        for(int i = 0 ; i < nums.size() ; i++) {
            freq[nums[i]]++ ; 
        }
        vector<int> sorted; 
        vector<pair<int,int>> v(freq.begin(), freq.end());
        sort(v.begin(), v.end(), [](auto &a, auto &b){

        return a.second > b.second;   // value ke basis pe sort
        });

        for(int i = 0 ; i < k ; i++) {
            sorted.push_back(v[i].first) ;
        }
        return sorted ; 
    }
};
