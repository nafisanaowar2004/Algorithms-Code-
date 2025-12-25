#include <bits/stdc++.h>
using namespace std;
long long coinChange(vector<int> &coins, int amount) {
int n = coins.size();
vector<vector<long long>> dp(n + 1, vector<long long>(amount + 1, 0));

for (int i = 0; i <= n; i++) {
dp[i][0] = 1;
}
for (int i = 1; i <= n; i++) {
for (int j = 1; j <= amount; j++) {
if (j >= coins[i - 1]) {
dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
} else {
dp[i][j] = dp[i - 1][j];
}
}
}
return dp[n][amount];
}
int main() {
int n, amount;
cout << "enter number of coins: ";
cin >> n;
vector<int> coins(n);
cout << "Enter coin values: ";
for (int i = 0; i < n; i++) {
cin >> coins[i];
}
cout << "Enter target amount: ";
cin >> amount;
long long ways = coinChange(coins, amount);
cout << "maximum number of ways: " << ways << endl;

return 0;
}
