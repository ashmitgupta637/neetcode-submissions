class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return false;

        unordered_map<int, int> freq;
        int initial_limit = min(n - 1, k);

        // Build initial window of size min(n, k + 1)
        for (int i = 0; i <= initial_limit; i++) {
            freq[nums[i]]++;
        }

        // Check for duplicates in initial window
        for (auto it : freq) {
            if (it.second > 1) return true;
        }

        // Slide window through remaining elements
        for (int i = k + 1; i < n; i++) {
            int ridx = i - k - 1;
            int addidx = i;

            freq[nums[ridx]]--;
            freq[nums[addidx]]++;

            if (freq[nums[addidx]] > 1) {
                return true;
            }
        }

        return false;
    }
};

