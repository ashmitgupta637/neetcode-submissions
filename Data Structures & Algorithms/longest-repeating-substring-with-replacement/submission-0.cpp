class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> count(26, 0);

        int left = 0;
        int maxCount = 0;
        int ans = 0;

        for(int right = 0; right < s.length(); right++) {

            count[s[right] - 'A']++;

            // maximum frequency character in current window
            maxCount = max(maxCount, count[s[right] - 'A']);

            // window invalid
            while((right - left + 1) - maxCount > k) {

                count[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
