class Solution {
public:

    int lcs(string &text1, string &text2, int m, int n, vector<vector<int>> &dp){
        if(m==0 || n == 0){
            return 0;
        }

        if(dp[m][n]!=-1){
            return dp[m][n];
        }

        if(text1[m-1] == text2[n-1]){
            return 1 + lcs(text1,text2,m-1,n-1,dp);
        }

        int x,y;

        x = lcs(text1,text2,m,n-1,dp);
        y = lcs(text1,text2,m-1,n,dp);

        return dp[m][n] = max(x,y);
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(1005,vector<int>(1005,-1));
        return lcs(text1,text2,text1.size(),text2.size(),dp);
    }
};
