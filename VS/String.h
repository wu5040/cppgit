#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include "VS.h"

class String : public VS<char>
{
public:
    String(int n=0,char *s=NULL):VS<char>(n,s){}

	void output(ostream &out)const                            //Êä³ö×Ö·û´®(*)
    {
        if(VS<char>::p==NULL)
            cout<<"";
        else
            for(int i=0;i<VS<char>::num;i++)
                cout<<VS<char>::p[i];
    }

};

#endif
