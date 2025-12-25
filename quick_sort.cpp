#include <bits/stdc++.h>
using namespace std;
int Array(int arr[], int low, int high) {
int last_element = arr[high];
int i = low - 1;
for (int j = low; j < high; j++) {
if (arr[j] < last_element) {
i++;
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
}
int temp = arr[i + 1];
arr[i + 1] = arr[high];
arr[high] = temp;
return (i + 1);
}
void quickSort(int arr[], int low, int high) {
if (low < high) {
int pi = Array(arr, low, high);
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}
void printArray(int arr[], int n) {
for (int i = 0; i < n; i++)

cout << arr[i] << " ";
cout << endl;
}
int main() {
int n;
cout << "Enter number of elements: ";
cin >> n;
int arr[n];
cout << "Enter elements: ";
for (int i = 0; i < n; i++)
cin >> arr[i];
quickSort(arr, 0, n - 1);
cout << "Sorted elements: ";
printArray(arr, n);
return 0;
}
