#include <iostream>
#include <cmath>

using namespace std;

double delta(double a,double b,double c)
{
	return b*b-4*a*c;
}

//指针形参
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

//引用形参
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

//定义结构体
struct result
{
	double x1,x2;
};

//结构体引用形参
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

//返回结构体

struct result solver(double a,double b,double d)
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
			t=solver(a,b,d);
			if(d>0)
				return 2;
			else
				return 1;
		}
}

//结果输出函数
void show(int flag,double x1,double x2)
{
	if(x1==-0)
		x1=-x1;
	if(x2==-0)
		x2=-x2;
	if(flag==0)
		cout<<"该方程无实根。"<<endl;
	else if(flag==1)
		cout<<"该方程有重根 x1 = x2 = "<<x1<<endl;
	else
		cout<<"该方程的根为 x1 = "<<x1<<", x2 = "<<x2<<endl;
}

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
			while(cin>>n)
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
