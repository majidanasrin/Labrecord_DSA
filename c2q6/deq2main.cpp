#include "deq2.cpp"

template<typename T>
void handleMenu() {
    LinkedListDEQUEUE<T> dequeue;
    char choice;
    T value;
    int position;

    do {
        cout << "\n------- Menu -------" << endl;
        cout << "a. Insert elements to the Front of the queue" << endl;
        cout << "b. Insert elements to the Rear of the queue" << endl;
        cout << "c. Delete elements from the Front of the queue" << endl;
        cout << "d. Delete elements from the Rear of the queue" << endl;
        cout << "e. Display" << endl;
        cout << "f. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a': {
                cout << "Enter value to insert at front: ";
                cin >> value;
                dequeue.insertFront(value);
                break;
            }
            case 'b': {
                cout << "Enter value to insert at rear: ";
                cin >> value;
                dequeue.insertRear(value);
                break;
            }
            case 'c': {
                if (!dequeue.isEmpty()) {
                    cout << "Deleted value from front: " << dequeue.deleteFront() << endl;
                } else {
                    cerr << "Underflow... The queue is empty." << endl;
                }
                break;
            }
            case 'd': {
                if (!dequeue.isEmpty()) {
                    cout << "Deleted value from rear: " << dequeue.deleteRear() << endl;
                } else {
                    cerr << "Underflow... The queue is empty." << endl;
                }
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
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'f');
}

int main() {
    char type;
    cout << "Enter the data type of the Linked List (x=int, y =  double, z = char): ";
    cin >> type;

    switch (type) {
        case 'x':
        handleMenu<int>();
            break;
        case 'y':
            handleMenu<double>();
            break;
        case 'z':
            handleMenu<char>();
            break;
        default:
            cout << "Invalid data type.try again." << endl;
    }

    return 0;
}