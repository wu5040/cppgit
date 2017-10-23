#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include "VS.h"

template <typename T>
class Vector : public VS<T>                       //以VS为基类派生
{
public:
    Vector(int n=0,const T *v=NULL):VS<T>(n,v){}

    virtual void output(ostream &out)const
    {
        if(VS<T>::num<=0)
            cout<<"()"<<endl;
        else
        {
            cout<<"(";
            for(int i=0; i<(VS<T>::num)-1; i++)
            {
                cout<<VS<T>::p[i];
                cout<<",";
            }
            cout<<VS<T>::p[VS<T>::num-1];
            cout<<")";
        }
    }
};



#endif // VECTOR_H_INCLUDED
