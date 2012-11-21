//
//  main.cpp
//  Triangular matrix
//

#include <iostream>
#include <stdlib.h>
#include "TMatrix.h"

using namespace std;

int main()
{
    int n = 3;
    double val;
    
    srandom((unsigned int)time(NULL));

    TMatrix a(n);
 /*
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            if (i >= j) {
                cout << "val[" << i << "][" << j <<"]=";
                cin >> val;
                a.set(i, j, val);
            } else a.set(i, j, 0);
        }
*/
  cout << "a matrix: " << endl;
    a.print();

    TMatrix b(n);
    
//    b.print();
    
    TMatrix c;
    c = a * 2;
    c.print();
    
//    TMatrix d;
    
//    d = c/a;
//    d.print();
    
//    TMatrix e = a+b-c+d;
//    e.print();
//    std::cout << "Hello, World!\n";
    return 0;
}

