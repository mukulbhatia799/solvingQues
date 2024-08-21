class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return findAns(0, n - 1, s, dp);
    }

    int findAns(int i, int j, string& s, vector<vector<int>>& dp) {
        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];

        char firstLetter = s[i];
        int answer = 1 + findAns(i + 1, j, s, dp);
        for (int k = i + 1; k <= j; k++) {
            if (s[k] == firstLetter) {
                int temp = findAns(i, k - 1, s, dp) + findAns(k + 1, j, s, dp);
                answer = min(answer, temp);
            }
        }
        return dp[i][j] = answer;
    }
};