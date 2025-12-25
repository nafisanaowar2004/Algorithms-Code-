#include <bits/stdc++.h>
using namespace std;
void insertion(int arr[], int n);
void print(int arr[], int n);
int main() {
int n;
cout << "Enter number of elements: ";
cin >> n;
int arr[n];
cout << "Enter elements: ";
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
insertion(arr, n);
cout << "Sorted elements: ";
print(arr, n);
}
void insertion(int arr[], int n) {
for (int i = 1; i < n; i++) {
int key = arr[i];
int j = i - 1;
while (j >= 0 && arr[j] > key) {
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}

}
void print(int arr[], int n) {
for (int i = 0; i < n; i++) {
cout << arr[i] << " ";
}
cout << endl;
}
