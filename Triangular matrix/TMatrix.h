//
//  TMatrix.h
//  Triangular matrix

#ifndef __Triangular_matrix__TMatrix__
#define __Triangular_matrix__TMatrix__

#include <iostream>

class TMatrix {
private:
    int N, K;
    double *V;
    int v_index(const int i, const int j) const { return i+(2*N-j-1)*j/2; }
    
public:
    TMatrix() { N=0; K=0; V=NULL; }
    TMatrix(int N);
    ~TMatrix() { delete[] V; }
    void print();
    int get(const int i, const int j) const { return i>=j ? V[v_index(i, j)] : 0; }
    void set(int i, int j, int val) { if (i >= j) V[v_index(i, j)] = val; }
    TMatrix &operator= (const TMatrix&);
    TMatrix operator+ (const TMatrix&);
    TMatrix operator- (const TMatrix&);
    TMatrix operator* (const TMatrix&);
    TMatrix operator* (const int);
    TMatrix operator/ (const TMatrix&);
};

#endif /* defined(__Triangular_matrix__TMatrix__) */
