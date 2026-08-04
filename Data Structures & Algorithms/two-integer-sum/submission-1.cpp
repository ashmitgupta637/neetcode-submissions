class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // number -> index store karne ke liye
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            
            int complement = target - nums[i];

            // agar complement pehle mil chuka hai
            if(mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            // current number aur uska index store karo
            mp[nums[i]] = i;
        }

        return {};
    }
};
