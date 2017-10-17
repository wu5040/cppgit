#include <iostream>
#include <cmath>
#include "f.h"
using namespace std;
double delta(double a,double b,double c)
{
    return b*b-4*a*c;
}

//ָ���β�
int solver1(double a,double b,double c,double *x1,double *x2)
{
    double d=delta(a,b,c);
    if(d<0)
        return 0;
    d=sqrt(d);
    *x1=(-b-d)/(2*a);
    *x2=(-b+d)/(2*a);
    if(d>0)
        return 2;
    else
        return 1;
}

//�����β�
int solver2(double a,double b,double c,double &x1,double &x2)
{
    double d=delta(a,b,c);
    if(d<0)
        return 0;
    d=sqrt(d);
    x1=(-b-d)/(2*a);
    x2=(-b+d)/(2*a);
    if(d>0)
        return 2;
    else
        return 1;
}

//�ṹ�������β�
int solver3(double a,double b,double c,result &s)
{
    double d=delta(a,b,c);
    if(d<0)
        return 0;
    else
    {
        d=sqrt(d);
        s.x1=(-b-d)/(2*a);
        s.x2=(-b+d)/(2*a);
        if(d>0)
            return 2;
        else
            return 1;
    }
}

//���ؽṹ��

struct result solver(double a,double b,double c,double d)
{
    struct result r;
    d=sqrt(d);
    r.x1=(-b-d)/(2*a);
    r.x2=(-b+d)/(2*a);
    return r;
}
int solver4(double a,double b,double c,result &t)
{
    double d=delta(a,b,c);
    if(d<0)
        return 0;
    else
    {
        t=solver(a,b,c,d);
        if(d>0)
            return 2;
        else
            return 1;
    }
}

//����������
void show(int flag,double x1,double x2)
{
    if(x1==-0)
        x1=-x1;
    if(x2==-0)
        x2=-x2;
    if(flag==0)
        cout<<"�÷�����ʵ����"<<endl;
    else if(flag==1)
        cout<<"�÷������ظ� x1 = x2 = "<<x1<<endl;
    else
        cout<<"�÷��̵ĸ�Ϊ x1 = "<<x1<<", x2 = "<<x2<<endl;
}
