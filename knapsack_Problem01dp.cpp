#include <iostream>
#include <algorithm>

using namespace std;

void knapsack(int W, int weights[], int values[], int n) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "DP Table:\n";
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }

    cout << "Maximum Profit: " << dp[n][W] << endl;

    int w = W;
    cout << "Selected Items: ";
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i << " ";
            w -= weights[i - 1];
        }
    }
    cout << endl;
}

int main() {
    int n = 4;
    int weights[] = {2, 3, 4, 5};
    int values[] = {3, 4, 5, 6};
    int W = 5;

    knapsack(W, weights, values, n);

    return 0;
