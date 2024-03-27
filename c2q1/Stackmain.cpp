#include "Stack.cpp"

template<typename T>
void menu(Stack<T>& stack) {
    char choice;
    T element;

    do {
        cout << "\nMENU:\n";
        cout << "a. push\n";
        cout << "b. pop\n";
        cout << "c. is the stack empty? \n";
        cout << "d. is the stack full? \n";
        cout << "e. check underflow \n";
        cout << "f. check overflow \n";
        cout << "g. Display\n";
        cout << "h. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a':
                cout << "Push an element to stack."<<endl;
                cin >> element;
                stack.push(element);
                break;
            case 'b':
                cout << "pop an element from stack."<<endl;
                stack.pop();
                break;
            case 'c':
                cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
                break;
            case 'd':
                cout << "Is stack full? " << (stack.isFull() ? "Yes" : "No") << endl;
                break;
            case 'e':
                cout << "check stack underflow" << (stack.isEmpty() ? "Yes" : "No") << endl;
                break;
            case 'f':
                cout << "check stack overflow " << (stack.isFull() ? "Yes" : "No") << endl;
                break;
            case 'g':
                cout <<"Display stack"<<endl;
                stack.display_stack();
                break;
            case 'h':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 'h');


}

int main() {
    Stack<int> stackInt;
    Stack<double> stackDouble;
    Stack<char> stackChar;
    int data;

    cout << "Choose the data type for the stack:" << endl;
    cout << "1. Integer, 2. Double, 3. Char " << endl;
    cin >> data;

    switch (data) {
        case 1 :
            menu(stackInt);
            break;
        case 2 :
            menu(stackDouble);
            break;
        case 3 :
            menu(stackChar);
            break;
        default:
            cout << "Invalid choice. Exiting..." << endl;
    }

    return 0;
}