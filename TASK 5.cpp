
#include <iostream>
using namespace std;

class ArrayStackInt {
    int *arr;
    int top;
    int cap;
public:
    ArrayStackInt(int capacity = 100) : top(-1), cap(capacity)
	 {
        arr = new int[cap];
    }
    bool empty() 
	{
	 return top == -1;
	  }
    bool full()
	 { 
	 return top == cap - 1;
	  }
    void push(int v)
	 {
	  if (!full())
	   arr[++top] = v;
	   else { 
	   cout<<"overflow";
	   }
	    }
    int pop()
	 {
	  if (!empty())
	   return arr[top--];
	  return -1; }
    int peek() 
	{
	 if (!empty())
	 return arr[top];
	  return -1; 
	  }
    ~ArrayStackInt()
	{
	 delete[] arr;
	  }
};


void ChangeLocation_array(char *Array, int b1, int b2) 
{
    ArrayStackInt st(1000); 
    
    st.push(b1);
    st.push(b2);
    while (!st.empty())
	 {
        int r = st.pop();
        int l = st.pop();
        if (l >= r) continue;
        
        char tmp = Array[l - 1];
        Array[l - 1] = Array[r - 1];
        Array[r - 1] = tmp;
        
        st.push(l + 1);
        st.push(r - 1);
    }
}


void PrintPattern_iterative_array(int n)
 {
    ArrayStackInt st(1000);
    st.push(1);
    ArrayStackInt out(1000); 
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


int main() 
{
    cout << "Demo: Array-based stack iterative solutions\n";

    
    char arr1[] = {'C','O','M','P','U','T','E','R'};
    cout << "Before ChangeLocation: ";
    for (char c : arr1) cout << c << ' ';
   cout <<endl;
    ChangeLocation_iterative_array(arr1, 3, 7);
    cout << "After ChangeLocation (iterative using array stack): ";
    for (char c : arr1) cout << c << ' ';
    cout <<endl;

    
    cout << "PrintPattern iterative (n=4):\n";
    PrintPattern_iterative_array(4);

    return 0;
}

