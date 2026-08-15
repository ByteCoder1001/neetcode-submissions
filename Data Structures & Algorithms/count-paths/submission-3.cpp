class Solution {
public:

    int uniquePaths1(int m, int n, vector<vector<int>>& dp) {

        if(m==1 && n==1){
            return 1;
        }

        if(dp[m][n] != -1) return dp[m][n];

        int x = 0, y = 0;

        if(m-1>=0){
            x = uniquePaths1(m-1,n,dp);
        }

        if(n-1>=0){
            y = uniquePaths1(m,n-1,dp);
        }

        return dp[m][n] = x+y;
    }

    int uniquePaths(int m, int n){
        vector<vector<int>> dp(105, vector<int>(105, -1));
        return uniquePaths1(m,n,dp);
    }

    

    
};
