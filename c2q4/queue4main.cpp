#include "queue4.cpp"

template<typename T>
void handleMenu() {
    LinkedListQueue<T> queue;
    char choice;
    T value;
    int position;

    do {
        cout << "\n------- Menu -------" << endl;
        cout << "a. Insert elements to the Rear of the queue" << endl;
        cout << "b. Delete elements from the Front of the queue" << endl;
        cout << "c. IS EMPTY" << endl;
        cout << "d. Display" << endl;
        cout << "e. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a': {
                T value;
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            }
            case 'b': {
                if (!queue.isEmpty()) {
                    cout << "Dequeued value: " << queue.dequeue() << endl;
                } else {
                    cerr << "Underflow.... The queue is empty." << endl;
                }
                break;
            }
            case 'c': {
                cout << (queue.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            }
            case 'd': {
                queue.display();
                break;
            }
            case 'e': {
                cout << "Exiting." << endl;
                break;
            }
            default:
                cout << "Please try again.Invalid choice. " << endl;
        }
    } while (choice != 'e');
}

int main() {
    char type;
    cout << "Enter the data type of the Linked List \n (x = int, y= double, z = char): ";
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
            cout << " Please try again ,Invalid data type." << endl;
    }

    return 0;
}