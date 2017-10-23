#ifndef VS_H_INCLUDED
#define VS_H_INCLUDED

#include <iostream>
using namespace std;

template <typename T> class VS
{
protected:
    int num;
    T *p;
public:
    VS(int n=0,const T *x=NULL)    //构造函数
    {
        if(n<=0)
        {
            num=0;
            p=NULL;
            return;
        }
        p=new T[n];
        for(int i=0; i<n; i++)
            p[i]=(x!=NULL?x[i]:0);
        num=n;
    }

    VS(const VS &a)                //深拷贝
    {
        p=new T[a.num];
        for(int i=0; i<a.num; i++)
            p[i]=a.p[i];
        num=a.num;
    }

    virtual ~VS()                  //虚析构
    {
        if(p!=NULL)
            delete [] p;
    }

    virtual VS & operator=(const VS &a)     //深赋值
    {
        if(&a!=this)
        {
            if(p!=NULL)
                delete [] p;
            p=new T[a.num];
            for(int i=0; i<a.num; i++)
                p[i]=a.p[i];
            num=a.num;
        }
        return *this;
    }

    virtual T & operator[](int a)          //方括号运算
    {
        return p[a];
    }

    virtual int getsize() const            //长度或维数
    {
        return num;
    }

    virtual void output(ostream &out)const =0; //输出（纯虚函数）

};

template <typename T>                                //插入运算符重载，普通C++函数
ostream & operator<<(ostream &out,const VS<T> &a)
{
    a.output(out);
    return out;
}


#endif // VS_H_INCLUDED
