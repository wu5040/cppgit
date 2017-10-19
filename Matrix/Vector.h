#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

class Vector
{
public:
    Vector(int n=0,const double *v=NULL);      //���캯��
    Vector(const Vector &x);                   //������캯��
    virtual ~Vector();                          //��������
    Vector & operator=(const Vector &v);       //�ֵ���������
    double GetData(int n) const;                //��ȡ��������
    int GetN() const;                           //��ȡ����ά��
    void Display();                             //չʾ����

private:
    double *Vec;
    int N;
};



#endif // VECTOR_H_INCLUDED
