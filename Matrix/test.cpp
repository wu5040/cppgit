#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    double a[9]={1,3,45,6,7,3,43,3,4};
    Matrix m1,m2(0,0),m3(3,3,a);
    m1.Show();
    m2.Show();
    m3.Show();
    return 0;
}
