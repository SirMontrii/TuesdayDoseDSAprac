#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        this->data = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAtPosition(int position, int value) {
        if (position < 0) {
            cout << "Invalid position." << endl;
            return;
        }
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* current = head;
        int index = 0;
        while (current && index < position - 1) {
            current = current->next;
            index++;
        }
        if (!current) {
            cout << "Position out of bounds." << endl;
            delete newNode;
            return;
        }
        newNode->next = current->next;
        if (current->next) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    void deleteNode(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                if (current == head) {
                    head = current->next;
                    if (head) {
                        head->prev = NULL;
                    }
                } else if (current == tail) {
                    tail = current->prev;
                    if (tail) {
                        tail->next = NULL;
                    }
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Value not found in the list." << endl;
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList myList;

    int choice;
    int value, position;

    cout << "Enter initial values for the doubly linked list (enter -1 to stop):" << endl;
    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        myList.insertAtEnd(value);
    }

    do {
        cout<<endl;
        cout << "Menu:" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert at Specific Position" << endl;
        cout << "4. Delete Node by Value" << endl;
        cout << "5. Display List" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Value to insert at the beginning: ";
                cin >> value;
                myList.insertAtBeginning(value);
                break;

            case 2:
                cout << "Value to insert at end: ";
                cin >> value;
                myList.insertAtEnd(value);
                break;

            case 3:
                cout << "Enter position you want to insert: ";
                cin >> position;
                cout << "Value you want to enter: " << endl;
                cin >> value;
                myList.insertAtPosition(position, value);
                break;

            case 4:
                cout << "Value to delete: ";
                cin >> value;
                myList.deleteNode(value);
                break;

            case 5:
                cout << "List: ";
                myList.display();
                break;

            case 0:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again...." << endl;
        }
    } while (choice != 0);

    return 0;
}
