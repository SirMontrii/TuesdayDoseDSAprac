// #include <iostream>
// using namespace std;

// template <class T>
// class Stack {
//     T *S;
//     int capacity;
//     int t;

// public:
//     Stack(int n) {
//         capacity = n;
//         t = -1;
//         S = new T[n];
//     }

//     void push(T e) {
//         if (t == capacity - 1) {
//             cout << "Stack Full....";
//             return;
//         } else {
//             t = t + 1;
//             S[t] = e;
//         }
//     }

//     T pop() {
//         if (t == -1) {
//             cout << "Underflow....";
//             return T();
//         } else {
//             T e = S[t];
//             t--;
//             return e;
//         }
//     }

//     T top() {
//         if (t == -1) {
//             cout << "Stack is empty. No top element." << endl;
//             return T();
//         } else {
//             return S[t];
//         }
//     }

//     bool isEmpty() {
//         return t == -1;
//     }

//     bool isFull() {
//         return t == capacity - 1;
//     }

//     void display() {
//         if (isEmpty()) {
//             cout << "Stack is empty." << endl;
//         } else {
//             cout << "Stack elements (from top to bottom): ";
//             for (int i = t; i >= 0; i--) {
//                 cout << S[i] << " ";
//             }
//             cout << endl;
//         }
//     }

//     ~Stack() {
//         delete[] S;
//     }
// };

// int main() {
//     int ch, capacity;
//     cout << "Enter the capacity of the stack: ";
//     cin >> capacity;
//     Stack<int> stack(capacity);

//     while (true) {
//         cout << "\n1. Push an element" << endl;
//         cout << "2. Pop an element" << endl;
//         cout << "3. Display stack" << endl;
//         cout << "4. Get top element" << endl;
//         cout << "5. Check if empty" << endl;
//         cout << "6. Check if full" << endl;
//         cout << "0. Exit" << endl;
//         cout << "Enter your choice: ";
//         cin >> ch;

//         switch (ch) {
//             case 1:
//                 int d;
//                 cout << "Enter the element: ";
//                 cin >> d;
//                 stack.push(d);
//                 break;

//             case 2:
//                 if (!stack.isEmpty()) {
//                     int elem = stack.pop();
//                     cout << "Popped element: " << elem << endl;
//                 } else {
//                     cout << "Stack is empty." << endl;
//                 }
//                 break;

//             case 3:
//                 stack.display();
//                 break;

//             case 4:
//                 if (!stack.isEmpty()) {
//                     int topElem = stack.top();
//                     cout << "Top element: " << topElem << endl;
//                 } else {
//                     cout << "Stack is empty." << endl;
//                 }
//                 break;

//             case 5:
//                 if (stack.isEmpty()) {
//                     cout << "Stack is empty." << endl;
//                 } else {
//                     cout << "Stack is not empty." << endl;
//                 }
//                 break;

//             case 6:
//                 if (stack.isFull()) {
//                     cout << "Stack is full." << endl;
//                 } else {
//                     cout << "Stack is not full." << endl;
//                 }
//                 break;

//             case 0:
//                 cout << "Exiting program." << endl;
//                 return 0;

//             default:
//                 cout << "Invalid choice. Please try again." << endl;
//         }
//     }

//     return 0;
// }

#include <iostream>
using namespace std;

template <class T>
class Stack {
    T *S;
    int capacity;
    int t;

public:
    Stack(int n) {
        capacity = n;
        t = -1;
        S = new T[n];
    }

    void push(T e) {
        if (t == capacity - 1) {
            cout << "Stack Full....";
            return;
        } else {
            t = t + 1;
            S[t] = e;
        }
    }

    T pop() {
        if (t == -1) {
            cout << "Underflow....";
            return T();
        } else {
            T e = S[t];
            t--;
            return e;
        }
    }

    T top() {
        if (t == -1) {
            cout << "Stack is empty. No top element." << endl;
            return T();
        } else {
            return S[t];
        }
    }

    bool isEmpty() {
        return t == -1;
    }

    bool isFull() {
        return t == capacity - 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements (from top to bottom): ";
            for (int i = t; i >= 0; i--) {
                cout << S[i] << " ";
            }
            cout << endl;
        }
    }

    void prefix(T e) {
        if (isFull()) {
            cout << "Stack Overflow. Cannot add prefix." << endl;
            return;
        }

        T result = e + pop();
        push(result);
    }

    void postfix(T e) {
        if (isFull()) {
            cout << "Stack Overflow. Cannot add postfix." << endl;
            return;
        }

        T result = pop() + e;
        push(result);
    }

    ~Stack() {
        delete[] S;
    }
};

int main() {
    int ch, capacity;
    cout << "Enter the capacity of the stack: ";
    cin >> capacity;
    Stack<int> stack(capacity);

    while (true) {
        cout << "\n1. Push an element" << endl;
        cout << "2. Pop an element" << endl;
        cout << "3. Display stack" << endl;
        cout << "4. Get top element" << endl;
        cout << "5. Check if empty" << endl;
        cout << "6. Check if full" << endl;
        cout << "7. Add prefix" << endl;
        cout << "8. Add postfix" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                int d;
                cout << "Enter the element: ";
                cin >> d;
                stack.push(d);
                break;

            case 2:
                if (!stack.isEmpty()) {
                    int elem = stack.pop();
                    cout << "Popped element: " << elem << endl;
                } else {
                    cout << "Stack is empty." << endl;
                }
                break;

            case 3:
                stack.display();
                break;

            case 4:
                if (!stack.isEmpty()) {
                    int topElem = stack.top();
                    cout << "Top element: " << topElem << endl;
                } else {
                    cout << "Stack is empty." << endl;
                }
                break;

            case 5:
                if (stack.isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;

            case 6:
                if (stack.isFull()) {
                    cout << "Stack is full." << endl;
                } else {
                    cout << "Stack is not full." << endl;
                }
                break;

            case 7:
                if (!stack.isEmpty()) {
                    int e;
                    cout << "Enter the element for prefix addition: ";
                    cin >> e;
                    stack.prefix(e);
                } else {
                    cout << "Stack is empty. Cannot add prefix." << endl;
                }
                break;

            case 8:
                if (!stack.isEmpty()) {
                    int e;
                    cout << "Enter the element for postfix addition: ";
                    cin >> e;
                    stack.postfix(e);
                } else {
                    cout << "Stack is empty. Cannot add postfix." << endl;
                }
                break;

            case 0:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
