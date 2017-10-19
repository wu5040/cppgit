#include <iostream>
#include <iomanip>
#include "Matrix.h"

Matrix::Matrix(int r,int c,const double *a)           //构造函数
{
    if(r<=0||c<=0)
    {
        r=c=0;
        x=NULL;
        return;
    }
    row=r;
    col=c;
    x=new double[row*col];
    for(int i=0; i<row*col; i++)
        x[i]=(a!=NULL?a[i]:0);
}

Matrix::Matrix(const Matrix &m)       //深拷贝
{
    if(m.row==0||m.col==0)
    {
        row=col=0;
        x=NULL;
        return;
    }
    row=m.row;
    col=m.col;
    x=new double[row*col];
    for(int i=0; i<row*col-1; i++)
        x[i]=m.x[i];
}

Matrix & Matrix::operator=(const Matrix &m)     //深赋值
{
    if(&m!=this)
    {
        if(x!=NULL)
            delete [] x;
        if(m.row==0||m.col==0)
        {
            row=col=0;
            x=NULL;
            return *this;
        }
        row=m.row;
        col=m.col;
        x=new double[m.row*m.col];
        for(int i=0; i<row*col-1; i++)
            x[i]=m.x[i];
    }
    return *this;
}


Matrix::~Matrix()
{
    if(x!=NULL)
        delete [] x;
}
/*
void Matrix::Set()
{
    for(int i=0; i<row; i++)
    {
        cout<<"请输入第"<<i+1<<"行的"<<col<<"个数据： ";
        for(int j=i*col; j<i*col+col-1; j++)
        {
            cin>>x[j];
        }
    }
}
*/
int Matrix::GetRow() const
{
    return row;
}

int Matrix::GetCol() const
{
    return col;
}

void Matrix::Show() const
{
    if(x!=NULL)
    {
        for(int i=0; i<row; i++)
        {
            cout<<"|"<<setw(5)<<x[i*col];
            for(int j=1; j<col; j++)
                cout<<setw(5)<<x[i*col+j];
            cout<<setw(5)<<"|"<<endl;
        }
    }
    else
        cout<<"||"<<endl;
}
