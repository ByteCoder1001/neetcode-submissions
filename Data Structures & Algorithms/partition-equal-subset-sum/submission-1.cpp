class Solution {
public:

    bool recurse(vector<int>& nums, int index, int target, vector<vector<int>> &dp){
        if(target == 0){
            return true;
        }
        if(index < 0 || target < 0) return false;
        if(dp[index][target] != -1) return dp[index][target];
        bool yes = recurse(nums, index-1, target-nums[index],dp);
        bool no = recurse(nums, index-1, target,dp);

        return dp[index][target] = yes || no ;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums){
            sum+=i;
        }
        if(sum%2 == 1) return false;

        int target = sum/2;

        vector<vector<int>> dp(nums.size(),vector<int> (target+1, -1));

        return recurse(nums,nums.size()-1,target,dp);

    }
};
