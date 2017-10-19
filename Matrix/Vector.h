#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

class Vector
{
public:
    Vector(int n=0,const double *v=NULL);      //构造函数
    Vector(const Vector &x);                   //深拷贝构造函数
    virtual ~Vector();                          //析构函数
    Vector & operator=(const Vector &v);       //深赋值运算符函数
    double GetData(int n) const;                //读取向量数据
    int GetN() const;                           //读取向量维数
    void Display();                             //展示函数

private:
    double *Vec;
    int N;
};



#endif // VECTOR_H_INCLUDED
