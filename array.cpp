//array.cpp
#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T> void New2D_1(T **&array,int row,int col)
{
    int i;
    array=new T*[row];
    for(i=0; i<row; i++)
        array[i]=new T[col];
}

template <typename T> T **New2D_2(T **array,int row,int col)
{
    int i;
    array=new T*[row];
	if(array==NULL) return array;
    for(i=0; i<row; i++)
	{
		array[i]=new T[col];
		if(array[i]==NULL)
		{
			delete [] array;
			return array=NULL;
		}
	}
	return array;
}

template <typename T> void Delete2D(T **&array,int row)
{
    int i;
    for(i=0; i<row; i++)
    {
        if(array[i])
            delete [] array[i];
    }
    delete [] array;
    array=NULL;
}

template <typename T> void Display2D(T **array,int row,int col)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            cout<<(array[i][j]=rand())<<' ';
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    int **p;
    int m,n;
    cout<<"输入二维数组行数 列数 m n： ";
    cin>>m>>n;
	New2D_1(p,m,n);
    //p=New2D_2(p,m,n);
    Display2D(p,m,n);
    Delete2D(p,m);
    return 0;
}

