#include <iostream>
using namespace std;

class Customer 
{
public:
    int ID, tickets;
    string name;
    Customer *next;
    Customer(int i, string n, int t) : ID(i), name(n), tickets(t), next(NULL) {}
};

class Queue 
{
    Customer *front, *rear;
public:
    Queue() : front(NULL), rear(NULL) {}

    void enqueue(int id, string name, int t)
	 {
        Customer *c = new Customer(id, name, t);
        if (!rear) front = rear = c;
        else
		 {
            rear->next = c;
            rear = c;
        }
    }

    void dequeue() 
	{
        if (!front)
		 { cout << "Queue empty!";
		  return;
		  }
        Customer *temp = front;
        front = front->next;
        if (!front) rear = NULL;
        delete temp;
    }

    void display() 
	{
        Customer *temp = front;
        while (temp) 
		{
            cout << "ID: " << temp->ID << ", Name: " << temp->name
                 << ", Tickets: " << temp->tickets << endl;
            temp = temp->next;
        }
    }
};

int main()
 {
    Queue q;
    q.enqueue(1, "Ali", 2);
    q.enqueue(2, "Sara", 4);
    q.enqueue(3, "Ahmed", 1);

    cout << "Queue:\n";
    q.display();

    cout << "\nAfter serving one customer:";
    q.dequeue();
    q.display();
    return 0;
}

