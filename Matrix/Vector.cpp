#include <iostream>
#include <math.h>
#include "Vector.h"
#define PI 3.1415926
using namespace std;

Vector::Vector(int n,const double *v)      //构造函数
{
    if(n<=0)
    {
        N=0;
        Vec=NULL;
        return;
    }
    Vec=new double[n];
    for(int i=0; i<n; i++)
        Vec[i]=(v!=NULL?v[i]:0);
    N=n;
}

Vector::Vector(const Vector &x)            //深拷贝构造函数
{
    Vec=new double[x.N];
    for(int i=0; i<x.N; i++)
        Vec[i]=x.Vec[i];
    N=x.N;
}

Vector:: ~Vector()                          //析构函数
{
    if(Vec!=NULL)
        delete [] Vec;
}

Vector & Vector::operator=(const Vector &v)   //深赋值运算符函数
{
    if(&v!=this)
    {
        if(Vec)
            delete [] Vec;
        Vec=new double[v.N];
        for(int i=0; i<v.N; i++)
            Vec[i]=v.Vec[i];
        N=v.N;
    }
    return *this;
}

double Vector::GetData(int n) const            //读取向量数据
{
    return Vec[n-1];
}

int Vector::GetN() const                 //读取向量维数
{
    return N;
}

void Vector::Display()                                             //展示函数
{
    if(N<=0)
        cout<<"()"<<endl;
    else
    {
        cout<<"(";
        for(int i=0; i<N-1; i++)
        {
            cout<<Vec[i];
            cout<<",";
        }
        cout<<Vec[N-1];
        cout<<")";
        cout<<endl;
    }
}
