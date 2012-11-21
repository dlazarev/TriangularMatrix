//
//  TMatrix.cpp
//  Triangular matrix

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "TMatrix.h"

using namespace std;

TMatrix::TMatrix(int _n)
{
    // if UPLO = `U', a[i][j] is stored in AP(i+j(j-1)/2) for i<=j; (1 <= i,j <=N)
    // if UPLO = `L', a[i][j] is stored in AP( i+(2n-j)(j-1)/2) for i>=j; (1 <= i,j <=N)
    //

    N = _n;
    K = N * (N+1)/2;
    
    V = new double[K];
    
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            if (i >= j) {
                V[v_index(i, j)] = random() % 23 + 1;
            } else V[v_index(i, j)] = 0;
}

void TMatrix::print()
{
    int i, j;

    for (i=0; i < N; i++) {
        for (j=0; j < N; j++)
            if (i >= j)
                cout << setw(3) << V[v_index(i, j)] << " ";
            else cout << "  0 ";
    
        cout << endl;
    }
    cout << endl;

}

TMatrix &TMatrix::operator=( const TMatrix &rhs )
{
    delete[] V;

    N = rhs.N;
    K = rhs.K;

    V = new double[K];
    
    for (int i=0; i<K; i++)
        V[i] = rhs.V[i];
    return *this;
}

TMatrix TMatrix::operator+(const TMatrix& a)
{
    TMatrix c(N);
    for (int i=0; i<K; i++)
        c.V[i] = this->V[i] + a.V[i];
    return c;
}

TMatrix TMatrix::operator-(const TMatrix& a)
{
    TMatrix c(N);
    for (int i=0; i<K; i++)
        c.V[i] = V[i] - a.V[i];
    return c;
}

TMatrix TMatrix::operator*(const TMatrix& a)
{
    TMatrix c(N);
    int v;

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) {
            c.set(i, j, 0);
            v = 0;
            for (int r=0; r<N; r++) {
                v += this->get(i, r) * a.get(r, j);
            }
            c.set(i, j, v);
        }
    return c;
}

TMatrix TMatrix::operator*(const int a)
{
    TMatrix c(N);
    
    for (int i=0; i<K; i++) c.V[i] = this->V[i] * a;
    return c;
}

TMatrix TMatrix::operator/(const TMatrix& a)
{
    TMatrix c(N);
    for (int i=0; i<K; i++)
        if (a.V[i] == 0) c.V[i] = 999;
        else c.V[i] = V[i] / a.V[i];
    return c;
}
