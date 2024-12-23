#include <iostream>
#include <vector>

using namespace std;

bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case: when there's only one number, the current player takes it
    for (int i = 0; i < n; ++i) {
        dp[i][i] = nums[i];
    }

    // Fill the DP table
    for (int length = 2; length <= n; ++length) { // length of the subarray
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1; // end index of the subarray
            dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
    }

    // If the score difference is non-negative, Player 1 can win
    return dp[0][n - 1] >= 0;
}

int main() {
    vector<int> nums = {1, 5, 2}; // Example input
    if (PredictTheWinner(nums)) {
        cout << "Player 1 can win!" << endl;
    } else {
        cout << "Player 1 cannot win." << endl;
    }
    return 0;
}


/*

OUTPUT:

Player 1 cannot win.

*/
