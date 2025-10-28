#include <iostream>
using namespace std;

void PrintPattern(int n, int row=1)
 {
    if (row > n) return;
    int spaces = n - row;
    for (int i = 1; i <= row; i++) 
	cout << row - i + 1 << " ";
    cout << endl;
    PrintPattern(n, row + 1);
}

int main() {
    int n;
    cout <<"Enter number:";
    cin >> n;
    PrintPattern(n);
    return 0;
}

