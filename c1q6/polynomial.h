


#include <iostream>
using namespace std;

struct Term {
    int coefficient;
    int exponent;
    Term* next;
    Term(int coef, int exp) : coefficient(coef), exponent(exp), next(nullptr) {}
};

class Polynomial {
private:
    Term* head;

public:
    Polynomial();
    ~Polynomial();
    void addTerm(int coef, int exp);
    void display();
    Polynomial add(Polynomial& other);
    Polynomial multiply(Polynomial& other);
};

Polynomial getPolynomial();


