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
    VS(int n=0,const T *x=NULL)    //���캯��
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

    VS(const VS &a)                //���
    {
        p=new T[a.num];
        for(int i=0; i<a.num; i++)
            p[i]=a.p[i];
        num=a.num;
    }

    virtual ~VS()                  //������
    {
        if(p!=NULL)
            delete [] p;
    }

    virtual VS & operator=(const VS &a)     //�ֵ
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

    virtual T & operator[](int a)          //����������
    {
        return p[a];
    }

    virtual int getsize() const            //���Ȼ�ά��
    {
        return num;
    }

    virtual void output(ostream &out)const =0; //��������麯����

};

template <typename T>                                //������������أ���ͨC++����
ostream & operator<<(ostream &out,const VS<T> &a)
{
    a.output(out);
    return out;
}


#endif // VS_H_INCLUDED
