#include <bits/stdc++.h>
using namespace std;
struct Activity {
int start;
int finish;
};
bool cmp(Activity a, Activity b) {
return a.finish < b.finish;
}
void activitySelection(Activity arr[], int n) {
sort(arr, arr + n, cmp);
cout << "Selected activities (start, finish):" << endl;
int lastFinish = arr[0].finish;
cout << "(" << arr[0].start << ", " << arr[0].finish << ")" << endl;
for (int i = 1; i < n; i++) {
if (arr[i].start >= lastFinish) {
cout << "(" << arr[i].start << ", " << arr[i].finish << ")" << endl;
lastFinish = arr[i].finish;
}
}
}
int main() {
Activity activities[] = {
{1, 2},
{3, 4},
{0, 6},
{5, 7},
{8, 9},

{5, 9}
};
int n = sizeof(activities) / sizeof(activities[0]);
activitySelection(activities, n);
return 0;
}
