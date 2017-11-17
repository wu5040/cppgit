#include <iostream>
#include "Students.h"
#include "LinkList.h"
using namespace std;

void test1()
{
    Student s[3]={
        Student("Wang",3.75),
        Student("Li",2.8),
        Student("Chen",3.2),
    };

    Student a("Zhang",3.4),b("Qian",2.37);

    LinkList<Student> Stu_List(s,3);
    cout<<"ѧ��GPA����"<<endl;
    Stu_List.ShowList();
    cout<<endl;
    cout<<"��������������㣺"<<endl;
    cout<<a<<endl<<b<<endl<<endl;

    cout<<"��Zhang���뵽�׽��ǰ��"<<endl;
    Stu_List.BeforeHead(a);
    Stu_List.ShowList();
    cout<<endl;

    cout<<"��Zhang���뵽β����"<<endl;
    Stu_List.AfterTail(a);
    Stu_List.ShowList();
    cout<<endl;

    cout<<"ɾ����1����㣺"<<endl;
    Stu_List.Go(1);
    Stu_List.DeleteCurNode();
    Stu_List.ShowList();
    cout<<endl;

    cout<<"��Li������ΪQian��㣺"<<endl;
    Stu_List.Go(2);
    Stu_List.Change(b);
    Stu_List.ShowList();
    cout<<endl;
}

int main()
{
    test1();
    return 0;
}
