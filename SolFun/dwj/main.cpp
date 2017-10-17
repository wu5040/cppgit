#include <iostream>
#include <stdio.h>
#include <cmath>
#include "f.h"
using namespace std;

int main()
{
    int n=9,flag;
    double a,b,c,x1,x2;
    struct result s;
    while(n==9)
    {
        a=0;
        while(a==0)
        {
            cout<<"输入系数 a b c：";
            cin>>a>>b>>c;
            if(a==0)
                cout<<"a不能为零，请重新";
        }
        cout<<"----------------------------"<<endl;
        cout<<"|       1-指针形参         |"<<endl;
        cout<<"|       2-引用形参         |"<<endl;
        cout<<"|     3-结构体引用形参     |"<<endl;
        cout<<"|      4-返回结构体        |"<<endl;
        cout<<"|       9-改变系数         |"<<endl;
        cout<<"|       0-退出程序         |"<<endl;
        cout<<"----------------------------"<<endl<<endl;
        cout<<"请输入相应的数字：";
        while(scanf("%d",&n)==1)
        {
            if(n==1)
            {
                flag=solver1(a,b,c,&x1,&x2);
                show(flag,x1,x2);
            }
            else if(n==2)
            {
                flag=solver2(a,b,c,x1,x2);
                show(flag,x1,x2);
            }
            else if (n==3)
            {
                flag=solver3(a,b,c,s);
                show(flag,s.x1,s.x2);
            }
            else if (n==4)
            {
                flag=solver4(a,b,c,s);
                show(flag,s.x1,s.x2);
            }
            else
                break;
            cout<<endl<<"请输入相应的数字：";
        }
        cout<<endl;
    }
    return 0;
}
