#include <iostream>
using namespace std;

void ChangeLocation(char *Array,int b1,int b2) 
{
    if (b1 >= b2) 
	return; 
    swap(Array[b1 - 1], Array[b2 - 1]); 
    ChangeLocation(Array, b1 + 1, b2 - 1); 
}

int main() 
{
    char arr[]={'C','O','M','P','U','T','E','R'};
    int b1=3,b2=7;
    ChangeLocation(arr,b1,b2);
    cout << "After change: ";
    for (char c :  arr) cout << c;
    cout << endl;
    return 0;
}

