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
            cout<<"����ϵ�� a b c��";
            cin>>a>>b>>c;
            if(a==0)
                cout<<"a����Ϊ�㣬������";
        }
        cout<<"----------------------------"<<endl;
        cout<<"|       1-ָ���β�         |"<<endl;
        cout<<"|       2-�����β�         |"<<endl;
        cout<<"|     3-�ṹ�������β�     |"<<endl;
        cout<<"|      4-���ؽṹ��        |"<<endl;
        cout<<"|       9-�ı�ϵ��         |"<<endl;
        cout<<"|       0-�˳�����         |"<<endl;
        cout<<"----------------------------"<<endl<<endl;
        cout<<"��������Ӧ�����֣�";
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
            cout<<endl<<"��������Ӧ�����֣�";
        }
        cout<<endl;
    }
    return 0;
}
