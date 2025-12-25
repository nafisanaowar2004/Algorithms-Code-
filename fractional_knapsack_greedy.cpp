#include <iostream>
#include <algorithm> // for swap
using namespace std;

int main() {
    int n;
    double capacity;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    double value[100], weight[100], ratio[100];
    double taken[100] = {0};


    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> value[i] >> weight[i];
        ratio[i] = value[i] / weight[i];
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(value[i], value[j]);
                swap(weight[i], weight[j]);
            }
        }
    }

    double totalValue = 0.0;
    double remaining = capacity;


    for (int i = 0; i < n; i++) {
        if (remaining == 0)
            break;

        if (weight[i] <= remaining) {

            taken[i] = 1.0;
            remaining -= weight[i];
            totalValue += value[i];
        } else {

            taken[i] = remaining / weight[i];
            totalValue += value[i] * taken[i];
            remaining = 0;
        }
    }

    cout << "\nItems taken in the knapsack:\n";
    cout << "--------------------------------\n";
    cout << "Item\tWeight\tValue\tTaken(%)\n";
    for (int i = 0; i < n; i++) {
        if (taken[i] > 0) {
            cout << i + 1 << "\t" << weight[i] << "\t" << value[i]
                 << "\t" << taken[i] * 100 << "%\n";
        }
    }

    cout << "\nMaximum value in Knapsack = " << totalValue << endl;

    return 0;
}
