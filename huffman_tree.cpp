#include <iostream>
#include <cstring>
using namespace std;

#define MAX 256

struct Node {
    char ch;
    int freq;
    int left;
    int right;
};

void findTwoMin(Node nodes[], int n, bool used[], int &min1, int &min2) {
    min1 = -1;
    min2 = -1;

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        if (min1 == -1 || nodes[i].freq < nodes[min1].freq) {
            min2 = min1;
            min1 = i;
        } else if (min2 == -1 || nodes[i].freq < nodes[min2].freq) {
            min2 = i;
        }
    }
}


void printCodes(Node nodes[], int root, string code) {
    if (root == -1) return;


    if (nodes[root].left == -1 && nodes[root].right == -1) {
        cout << nodes[root].ch << " : " << code << endl;
        return;
    }

    printCodes(nodes, nodes[root].left, code + "0");
    printCodes(nodes, nodes[root].right, code + "1");
}

int main() {

    char text[] = "HELLO HUFFMAN";


    int freq[MAX] = {0};
    for (int i = 0; text[i] != '\0'; i++)
        freq[(unsigned char)text[i]]++;

    Node nodes[MAX];
    bool used[MAX] = {0};
    int n = 0;


    for (int i = 0; i < MAX; i++) {
        if (freq[i] > 0) {
            nodes[n].ch = (char)i;
            nodes[n].freq = freq[i];
            nodes[n].left = -1;
            nodes[n].right = -1;
            n++;
        }
    }

    int totalNodes = n;

    while (true) {
        int min1, min2;
        findTwoMin(nodes, totalNodes, used, min1, min2);
        if (min2 == -1) break;

        nodes[totalNodes].ch = '\0';
        nodes[totalNodes].freq = nodes[min1].freq + nodes[min2].freq;
        nodes[totalNodes].left = min1;
        nodes[totalNodes].right = min2;


        used[min1] = true;
        used[min2] = true;
        used[totalNodes] = false;

        totalNodes++;
    }


    int root = -1;
    for (int i = 0; i < totalNodes; i++)
        if (!used[i]) { root = i; break; }

    cout << "Huffman Codes:\n";
    printCodes(nodes, root, "");

    return 0;
}
