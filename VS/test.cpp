#include "Vector.h"
#include "String.h"
int main()
{
    double a[4]={1,2,3,4};
    char b[]="abcdefg";
    Vector<double> v(4,a);
    String s(7,b);
    cout<<v<<endl;
    cout<<v[1]<<endl;
    cout<<s<<endl;
    cout<<s[2]<<endl;
    return 0;
}
