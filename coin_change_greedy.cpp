#include <bits/stdc++.h>
using namespace std;
int coinChange(int coin[],int n,int amount){
sort(coin,coin+n,greater<int>());

int count=0;

for(int i=0;i<n; i++){
if(amount==0){
break;
}
int take = amount / coin[i];
count += take;
amount -= take * coin[i];
}

if (amount != 0){
return -1;
}
return count;

}

int main() {
int coins[] = {1, 5, 10};
int n = 3;
int amount;

cout << "Enter amount: ";
cin >> amount;

int result = coinChange(coins, n, amount);

if (result != -1)
cout << "Minimum number of coins : " << result << endl;
else
cout << "Exact change is not possible with given denominations." << endl;

return 0;
}
