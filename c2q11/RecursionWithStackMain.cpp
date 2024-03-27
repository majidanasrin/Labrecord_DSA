
#include "RecursionWithStack.cpp"

int main() {
    FactorialCalculator calculator;
    int x;
    std::cout<<"Enter the number  to determine  the factorial : ";
    std::cin>>x;
    std::cout << calculator.factorialWithStack(x) << std::endl; 
    return 0;
}





