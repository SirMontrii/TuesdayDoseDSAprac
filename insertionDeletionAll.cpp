#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value){
        this->data = value;
        this -> next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } 
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAtPosition(int position, int value) {
        if (position < 0) {
            cout << "Invalid position." << endl;
            return;
        }
        Node* newNode = new Node(value);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
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
        current->next = newNode;
    }

    void deleteNode(int value) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
        cout << "please enter the correct value. This value doesn't exist...." << endl;
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
    LinkedList myList;

    int choice;
    int value, position, preValue;

    cout<<"Taking linkedlist from the user: "<<endl;
    cout<<"Enter -1 after the input"<<endl;
    while(true){
        cin>>value;
        if(value == -1){
            break;
        }
        myList.insertAtEnd(value);
    }

    do {
        cout << "Menu:"<<endl;
        cout << "1. Insert at Beginning"<<endl;
        cout << "2. Insert at End"<<endl;
        cout << "3. Insert at Specific Position"<<endl;
        cout << "4. Delete Node by Value"<<endl;
        cout << "5. Display List"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Value to insert at the beginning ";
                cin >> value;
                myList.insertAtBeginning(value);
                break;

            case 2:
                cout << "Value to insert at end: ";
                cin >> value;
                myList.insertAtEnd(value);
                break;

            case 3:
                cout << " Enter position you want to insert: ";
                cin >> position;
                cout<<" Value you want to enter: "<<endl;
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
                cout << "Exiting program."<<endl;
                break;

            default:
                cout << "Invalid choice. Please try again...."<<endl;
        }
    } while (choice != 0);

    return 0;
}