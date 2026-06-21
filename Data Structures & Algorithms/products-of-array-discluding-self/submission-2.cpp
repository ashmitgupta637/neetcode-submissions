class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pre = 1;
        int post = 1;
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                ans[i] = 1;
            } else {
                pre = pre * nums[i - 1];
                ans[i] = pre;
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == nums.size() - 1) {
                ans[i] = ans[i] * post;
            } else {
                post = post * nums[i + 1];
                ans[i] = ans[i] * post;
            }
        }
        return ans;
    }
};
