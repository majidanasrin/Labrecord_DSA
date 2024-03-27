#include "Stack.h"

template<class T>
Stack<T>::Stack(){
    top = -1;
    size = 50;
}

template<class T>
void Stack<T>::create_stack(){
    char ans = 'y';
    T key;
    do{
        cout<<"Enter value: "<<endl;
        cin>>key;
        this->push(key);
        cout<<"Would you like to add an element(y/n): "<<endl;
        cin>>ans;
    }
    while(ans=='y');

}

template<class T>
void Stack<T>::display_stack(){
    if(this->isEmpty()) {
        cout<<"Stack is Empty."<<endl;
        return;
    }

    for(int i = 0;i <= this->top; i++){
        cout<<this->s[top - i]<<endl;
    }
}

template<class T>
void Stack<T>::push(T key){
    if(!isFull()){
        top = top+1;
        s[top] = key;
    }
    else{
        cout<<"Stack overflow"<<endl;
    }
}

template<class T>
void Stack<T>::pop(){
    if (!isEmpty()){
        top = top-1;
    }
    else{
        cout<<"Stack underflow"<<endl;
    }
}

template<class T>
bool Stack<T>::isEmpty(){
    return(top == -1);
}

template<class T>
bool Stack<T>::isFull(){
    return (top == size);
}