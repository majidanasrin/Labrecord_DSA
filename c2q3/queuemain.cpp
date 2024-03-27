#include "queue.cpp"

template<typename T>
void handleMenu(Queue<T> queue) {

    char choice;
    T value;
    int position;

    do {
        cout << "\n------- Menu -------" << endl;
        cout << "a. Insert elements to the Rear of the queue" << endl;
        cout << "b. Delete elements from the Front of the queue" << endl;
        cout << "c. Is Empty" << endl;
        cout << "d. Is Full" << endl;
        cout << "e. check Underflow" <<endl;
        cout << "f. check overflow" <<endl;
        cout << "g. Display" << endl;
        cout << "h. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a': {
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            }
            case 'b': {
                if (!queue.isEmpty()) {
                    cout << "Dequeued value: " << queue.dequeue() << endl;
                } else {
                    cout << "Underflow: The queue is empty." << endl;
                }
                break;
            }
            case 'c': {
                cout << (queue.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            }
            case 'd': {
                cout << (queue.isFull() ? "Queue is Full" : "Queue is not Full") << endl;
                break;
            }
            case 'e': {
                cout << (queue.isEmpty() ? "Underflow." : "Not Underflow.") << endl;
                break;
            }
            case 'f': {
                cout << (queue.isFull() ? "Overflow" : "Not Overflow") << endl;
                break;
                }
            case 'g': {
                queue.display();
                break;
            }
            case 'h': {
                cout << "Exiting..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'h');
}

int main() {
    int capacity;
    cout << "Enter the capacity of the Queue: ";
    cin >> capacity;

    Queue<int> queueInt(capacity);
    Queue<double> queueDouble(capacity);
    Queue<char> queueChar(capacity);
    int data;
    cout << "Enter the data type of the Linked List (1 for int, 2 for double, 3 for char): ";
    cin >> data;

    switch (data) {
        case 1 :
            handleMenu(queueInt);
            break;
        case 2 :
            handleMenu(queueDouble);
            break;
        case 3 :
            handleMenu(queueChar);
            break;
        default:
            cout << "Invalid data type. Please try again." << endl;
    }

    return 0;
}