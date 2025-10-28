#include <iostream>
using namespace std;

class Node {
public:
    int BookID;
    string Title;
    string Author;
    Node* next;
    Node* prev;

    Node(int id, string title, string author) {
        BookID = id;
        Title = title;
        Author = author;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void addAtBeginning(int id, string title, string author)
	 {
        Node* newNode = new Node(id, title, author);

        if (head == NULL) 
		{
            head = tail = newNode;
        } 
        else
		 {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addAtEnd(int id, string title, string author)
	 {
        Node* newNode = new Node(id, title, author);

        if (tail == NULL)
		 {
            head = tail = newNode;
        } 
        else 
		{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void addAtPosition(int pos, int id, string title, string author)
	 {
        if (pos <= 1 || head == NULL)
		 {
            addAtBeginning(id, title, author);
            return;
        }

        Node* newNode = new Node(id, title, author);
        Node* temp = head;
        int count = 1;

        while (temp->next != NULL && count < pos - 1) 
		{
            temp = temp->next;
            count++;
        }

        if (temp->next == NULL)
		 {
            addAtEnd(id, title, author);
            delete newNode;  
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteByID(int id) 
	{
        if (head == NULL)
		 {
            cout << "Library is empty!\n";
            return;
        }

        Node* temp = head;
        while (temp && temp->BookID != id)
		 {
            temp = temp->next;
        }

        if (temp == NULL)
		 {
            cout << "Book ID not found!\n";
            return;
        }

        if (temp == head)
            head = head->next;
        if (temp == tail)
            tail = tail->prev;

        if (temp->prev)
            temp->prev->next = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;

        delete temp;
    }

    void displayForward()
	 {
        Node* temp = head;
        cout << "\nBooks in forward order:\n";
        while (temp != NULL)
		 {
            cout << "BookID: " << temp->BookID  << ", Title: " << temp->Title << ", Author: " << temp->Author << endl;
            temp = temp->next;
        }
    }

    void displayBackward()
	 {
        Node* temp = tail;
        cout << "\nBooks in reverse order:\n";
        while (temp != NULL) 
		{
            cout << "BookID: " << temp->BookID 
                 << ", Title: " << temp->Title 
                 << ", Author: " << temp->Author << endl;
            temp = temp->prev;
        }
    }
};

int main()
 {
    DoublyLinkedList library;

    library.addAtBeginning(1, "OOP", "Bjarne");
    library.addAtEnd(2, "DSA", "Goodrich");
    library.addAtPosition(2, 3, "Algorithms", "CLRS");

    library.displayForward();
    library.displayBackward();

    cout << "\nDeleting Book with ID 2";
    library.deleteByID(2);

    library.displayForward();
    library.displayBackward();

    return 0;
}

