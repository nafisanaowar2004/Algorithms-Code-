#include <iostream>
#include <string>
using namespace std;

void search(const string& pat, const string& txt) {
    int M = pat.size();
    int N = txt.size();

    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++) {
            if (txt[i + j] != pat[j]) {
                break;
            }
        }

        if (j == M) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    string text, pattern;

    cout << "Enter the text: ";
    cin >> text;

    cout << "Enter the pattern: ";
    cin >> pattern;

    search(pattern, text);

    return 0;
}
