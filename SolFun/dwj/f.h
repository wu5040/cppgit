#ifndef F_H_INCLUDED
#define F_H_INCLUDED

struct result
{
    double x1,x2;
};
double delta(double a,double b,double c);
int solver1(double a,double b,double c,double *x1,double *x2);
int solver2(double a,double b,double c,double &x1,double &x2);
int solver3(double a,double b,double c,struct result &s);
struct result solver(double a,double b,double c,double d);
int solver4(double a,double b,double c,struct result &t);
void show(int flag,double x1,double x2);

#endif // F_H_INCLUDED
