#include <iostream>
#include <cmath>

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

//����ṹ��
struct result
{
	double x1,x2;
};

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
					cout<<endl<<"��������Ӧ�����֣�";
				}
			cout<<endl;
		}
	return 0;
}
