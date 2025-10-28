#include <iostream>
using namespace std;

class Feature {
public:
    string Name;
    Feature(string n) : Name(n) {}
    virtual void analyze() = 0;
    virtual ~Feature() {}
};

class LandFeature : public Feature {
public:
    LandFeature(string n) : Feature(n) {}
    void analyze()
	 { 
	   cout << "Land Feature detected: " << Name << endl;
	  }
};

class WaterFeature : public Feature {
public:
    WaterFeature(string n) : Feature(n) {}
    void analyze()
	 {
	 cout << "Water Feature detected: " << Name << endl; 
	 }
};

class Node {
public:
    int FeatureID;
    Feature *f;
    Node *next;
    Node(int id, Feature *feat) : FeatureID(id), f(feat), next(NULL) {}
};

class SinglyLinkedList {
    Node *head;
public:
    SinglyLinkedList() : head(NULL) {}

    void insertAtEnd(int id, Feature *f)
	 {
        Node *newNode = new Node(id, f);
        if (!head) head = newNode;
        else 
		{
            Node *temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void deleteByID(int id)
	 {
        if (!head) return;
        if (head->FeatureID == id)
		 {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *temp = head;
        while (temp->next && temp->next->FeatureID != id)
            temp = temp->next;
        if (temp->next)
		 {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    void displayAll()
	 {
        Node *temp = head;
        while (temp)
		 {
            cout << "Feature ID: " << temp->FeatureID << " -> ";
            temp->f->analyze();
            temp = temp->next;
        }
    }

    void reverseList() 
	{
        Node *prev = NULL, *curr = head, *next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    ~SinglyLinkedList()
	 {
        Node *temp;
        while (head) 
		{
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() 
{
    SinglyLinkedList list;
    list.insertAtEnd(1, new LandFeature("Forest"));
    list.insertAtEnd(2, new WaterFeature("River"));
    list.insertAtEnd(3, new LandFeature("Mountain"));
    list.insertAtEnd(4, new WaterFeature("Ocean"));

    cout << "Original List:\n";
    list.displayAll();

    cout << "\nAfter Deleting Feature ID 2:";
    list.deleteByID(2);
    list.displayAll();

    cout << "\nAfter Reversing:";
    list.reverseList();
    list.displayAll();
    
    return 0;
}

