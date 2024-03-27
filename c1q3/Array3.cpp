#include "Array3.h"

template <class T>
Array<T>::Array(){
	LB=1;
	UB=0;
	mid = 0;
}

template <class T>
Array<T>::Array(int LB,int UB,T x[]){
 int i = LB;
 while(i<=UB){
	A[i]=x[i];
	i++;
 }
}

template <class T>
void Array<T>::insert_at_end(T key){
	UB=UB+1;
	A[UB]=key;
}

template <class T>
void Array<T>::rotateClockwise(int k) {
    int n = UB - LB + 1;
    k = k % n;
    if (k < 0) {
        k += n;
    }
    T* temp = new T[n];

    for (int i = 0; i < n; ++i) {
        temp[(i + k) % n] = A[i];
    }

    for (int i = 0; i < n; ++i) {
        A[i] = temp[i];
    }

    delete[] temp;
}

template <class T>
void Array<T>::rotateAntiClockwise(int k) {
    int n = UB - LB + 1;
    k = k % n;
    if (k < 0) {
        k += n;
    }
    T* temp = new T[n];

    for (int i = 0; i < n; ++i) {
        temp[i] = A[(i + k) % n];
    }

    for (int i = 0; i < n; ++i) {
        A[i] = temp[i];
    }

    delete[] temp;
}

template <class T>
void Array<T>::printDistinctElements() {
    int n = UB - LB + 1 ;
    for (int i = 0; i < n; ++i) {
        bool isDistinct = true;
        for (int j = 0; j < i; ++j) {
            if (A[i] == A[j]) {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct) {
            cout << A[i] << " ";
        }
    }
    cout << endl;
}

template <class T>
void Array<T>::generateFrequencyTable() {
     int n = UB - LB + 1 ;
    cout << "Distinct Elements: ";
    for (int i = 0; i < n; ++i) {
        bool isDistinct = true;
        for (int j = 0; j < i; ++j) {
            if (A[i] == A[j]) {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct) {
            cout << A[i] << " ";
        }
    }
    cout << endl;
}

template<class T>
void Array<T>::display_array(){
        if ((UB -LB + 1) == 0) {
            cout << "Array is empty.\n";
            return;
        }
        cout << "Elements in the array: ";
        for (int i = LB; i <= UB; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
}

//ostream
template <class F>
ostream& operator << (ostream& os,Array<F> M){
	int i;
	os<<endl;
	for (i=M.LB;i<=M.UB;i++){
		os<<M.A[i]<<" ";
	}
	os<<endl;
	return os;
}