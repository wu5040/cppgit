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
    cout<<"学生GPA链表："<<endl;
    Stu_List.ShowList();
    cout<<endl;
    cout<<"待操作的两个结点："<<endl;
    cout<<a<<endl<<b<<endl<<endl;

    cout<<"将Zhang插入到首结点前："<<endl;
    Stu_List.BeforeHead(a);
    Stu_List.ShowList();
    cout<<endl;

    cout<<"将Zhang插入到尾结点后："<<endl;
    Stu_List.AfterTail(a);
    Stu_List.ShowList();
    cout<<endl;

    cout<<"删除第1个结点："<<endl;
    Stu_List.Go(1);
    Stu_List.DeleteCurNode();
    Stu_List.ShowList();
    cout<<endl;

    cout<<"将Li结点更改为Qian结点："<<endl;
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
