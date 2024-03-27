#include "Deq.cpp"

template<typename T>
void handleMenu(Dequeue<T>& dequeue) {
    char choice;
    T value;

    do {
        cout << "\n------- Menu -------" << endl;
        cout << "a. Insert elements to the Front of the queue" << endl;
        cout << "b. Insert elements to the Rear of the queue" << endl;
        cout << "c. Delete elements from Front of the queue" << endl;
        cout << "d. Delete elements from Rear of the queue" << endl;
        cout << "e. Display" << endl;
        cout << "f. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a': {
                cout << "Enter value to add to Front of dequeue: ";
                cin >> value;
                dequeue.insertFront(value);
                break;
            }
            case 'b': {
                cout << "Enter value to add to Rear of dequeue: ";
                cin >> value;
                dequeue.insertRear(value);
                break;
            }
            case 'c': {
                dequeue.deleteFront();
                break;
            }
            case 'd': {
                dequeue.deleteRear();
                break;
            }
            case 'e': {
                dequeue.display();
                break;
            }
            case 'f': {
                cout << "Exiting..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. try again." << endl;
        }
    } while (choice != 'f');
}

int main() {
    int capacity;
    cout << "Enter the capacity of the Deque: ";
    cin >> capacity;

    Dequeue<int> dequeueInt(capacity);
    Dequeue<double> dequeueDouble(capacity);
    Dequeue<char> dequeueChar(capacity);
    int data;
    cout << "Enter the data type of the Linked List\n  (x = int, y = double, z  = char): ";
    cin >> data;

    switch (data) {
        case 'x' :
            handleMenu(dequeueInt);
            break;
        case 'y' :
            handleMenu(dequeueDouble);
            break;
        case 'z' :
            handleMenu(dequeueChar);
            break;
        default:
            cout << "Invalid data type....  try again." << endl;
    }

    return 0;
}