#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

class Vector;

class Matrix
{
private:
    int row,col;
    double *x;
public:
    Matrix(int r=0,int c=0,const double *a=NULL);  //构造函数
    Matrix(const Matrix &m);                       //深拷贝
    Matrix & operator=(const Matrix &m);           //深赋值
    virtual ~Matrix();                             //析构
    int GetRow() const;                            //读取行数
    int GetCol() const;                            //读取列数
    void Show() const;                             //展示矩阵

    //double & operator[][](int a,int b) const throw(char);
    friend Matrix operator+(const Matrix &a,const Matrix &b);
    friend Matrix operator-(const Matrix &a,const Matrix &b);
    friend Matrix operator*(const Matrix &a,const Matrix &b);
    friend Vector Mul(const Matrix &a,const Vector &b);

};

#endif // MATRIX_H_INCLUDED
