#include <bits/stdc++.h>
using namespace std;
struct Job {
char id;
int deadline;
int profit;
};
bool cmp(Job a, Job b) {
return a.profit > b.profit;
}
void jobSequencing(Job jobs[], int n) {
sort(jobs, jobs + n, cmp);
int maxDeadline = 0;
for (int i = 0; i < n; i++) {
maxDeadline = max(maxDeadline, jobs[i].deadline);
}
vector<char> slot(maxDeadline + 1, '-');
int totalProfit = 0;
for (int i = 0; i < n; i++) {
for (int t = jobs[i].deadline; t >= 1; t--) {
if (slot[t] == '-') {
slot[t] = jobs[i].id;
totalProfit += jobs[i].profit;
break;
}
}
}

cout << "Selected Jobs: ";
for (int i = 1; i <= maxDeadline; i++) {
if (slot[i] != '-') {
cout << slot[i] << " ";
}
}
cout << "\nTotal Profit: " << totalProfit << endl;
}
int main() {
Job jobs[] = {
{'A', 2, 100},
{'B', 1, 19},
{'C', 2, 27},
{'D', 1, 25},
{'E', 3, 15}
};
int n = sizeof(jobs) / sizeof(jobs[0]);
jobSequencing(jobs, n);
return 0;
}
