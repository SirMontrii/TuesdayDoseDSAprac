#include<iostream>
#include<map>
using namespace std;

class Node {

    public:
    int data;
    Node* next;
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};

void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d , Node* &head) {
    Node* temp = new Node(d);
    if (tail == nullptr) {
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    if (head == nullptr) {
        head = tail;
    }
}

void print(Node* &head) {
    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;
    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
void insertAtPosition(Node* &tail, Node* & head, int position, int d) {
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }
    Node* temp  = head;
    int cnt = 1;
    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }
    if(temp -> next == NULL) {
        insertAtTail(tail,d ,head);
        return ;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}
void deleteNode(int position, Node* & head) { 
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}
int main() {
     Node* head = nullptr;
    Node* tail = nullptr;
    int ch;
    int data;
    int position;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Insert element at head" << endl;
        cout << "2. Insert element at tail" << endl;
        cout << "3. Insert element at particular position" << endl;
        cout << "4. Delete element at particular position" << endl;
        cout << "5. Print the list" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                insertAtHead(head, data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                if (head == nullptr) {
                    head = new Node(data);
                    tail = head;
                } else {
                    insertAtTail(tail, data , head);
                }
                break;
            case 3:
                cout << "Enter position: ";
                cin >> position;
                cout << "Enter data: ";
                cin >> data;
                insertAtPosition(tail, head, position, data);
                break;
            case 4:
                cout << "Enter position: ";
                cin >> position;
                deleteNode(position, head);
                break;

            case 5:
                print(head);
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    
    return 0;
}