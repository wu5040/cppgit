#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

class Vector;

class Matrix
{
private:
    int row,col;
    double *x;
public:
    Matrix(int r=0,int c=0,const double *a=NULL);  //���캯��
    Matrix(const Matrix &m);                       //���
    Matrix & operator=(const Matrix &m);           //�ֵ
    virtual ~Matrix();                             //����
    int GetRow() const;                            //��ȡ����
    int GetCol() const;                            //��ȡ����
    void Show() const;                             //չʾ����

    //double & operator[][](int a,int b) const throw(char);
    friend Matrix operator+(const Matrix &a,const Matrix &b);
    friend Matrix operator-(const Matrix &a,const Matrix &b);
    friend Matrix operator*(const Matrix &a,const Matrix &b);
    friend Vector Mul(const Matrix &a,const Vector &b);

};

#endif // MATRIX_H_INCLUDED
