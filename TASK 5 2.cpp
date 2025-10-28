
#include <iostream>
using namespace std;

class LNode {
public:
    int val;
    LNode *next;
    LNode(int v) : val(v), next(NULL) {}
};

class LinkedStackInt 
{
    LNode *top;
public:
    LinkedStackInt() : top(NULL) {}
    bool empty()
	 { 
	 return top == NULL; 
	 }
    void push(int v) 
	{
        LNode *n = new LNode(v);
        n->next = top;
        top = n;
    }
    int pop()
	 {
        if (!top) return -1;
        int v = top->val;
        LNode *tmp = top;
        top = top->next;
        delete tmp;
        return v;
    }
    ~LinkedStackInt()
	 {
        while (!empty()) pop();
    }
};


void ChangeLocation_iterative_linked(char *Array, int b1, int b2)
 {
    LinkedStackInt st;
    st.push(b1);
    st.push(b2);
    while (!st.empty()) 
	{
        int r = st.pop();
        int l = st.pop();
        if (l >= r)
		 continue;
        
        char tmp = Array[l - 1];
        Array[l - 1] = Array[r - 1];
        Array[r - 1] = tmp;
        st.push(l + 1);
        st.push(r - 1);
    }
}


void PrintPattern_linked(int n) 
{
    LinkedStackInt st;
    st.push(1);
    LinkedStackInt out;
    while (!st.empty())
	 {
        int row = st.pop();
        out.push(row);
        if (row + 1 <= n) st.push(row + 1);
    }
    while (!out.empty()) 
	{
        int row = out.pop();
        for (int k = row; k >= 1; --k)
		 {
            cout << k;
            if (k > 1) cout << " ";
        }
        cout << '\n';
    }
}


int main() {
    cout << " Demo: Linked-list-based stack iterative solutions\n";

    
    char arr1[] = {'C','O','M','P','U','T','E','R'};
    cout << "Before ChangeLocation: ";
    for (char c : arr1) cout << c << ' ';
    cout <<"endl";
    ChangeLocation_iterative_linked(arr1, 3, 7);
    cout << "After ChangeLocation (iterative using linked stack): ";
    for (char c : arr1) cout << c << ' ';
    cout << "endl";

    
    cout << "PrintPattern iterative (n=4):\n";
    PrintPattern_iterative_linked(4);

    return 0;
}

