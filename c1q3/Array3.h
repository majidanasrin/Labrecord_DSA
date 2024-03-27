#include<iostream>
#include<ostream>

using namespace std;
template <class T>
    class Array{
	int LB,UB,mid;
	T A[100];
	T B[100];
	public:
  	Array();
  	Array(int,int,T[]);
	void insert_at_end(T);
    void rotateClockwise(int);
	void rotateAntiClockwise(int);
	void printDistinctElements();
	void generateFrequencyTable();
	void display_array();

    template <class F>
  	friend ostream& operator<<(ostream&, Array<F> );

    };