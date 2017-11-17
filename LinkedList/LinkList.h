#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include <iostream>
using namespace std;

template <typename T> class LinkList;         //提前声明链表类

template <typename T> class Node              //结点类
{
private:
    T data;      //数据域类的对象
    Node *next;  //指向下一个结点的指针变量
public:
    Node(const T &t=0) : data(t){} //冒泡语法初始化组合成员
    friend class LinkList<T>;    //声明友元类
};

template <typename T> class LinkList         //链表类
{
private:
    Node<T> *head,*cur_node;   //链首指针、当前结点指针
    int num;                  //结点数

public:
    LinkList();                                     //默认构造
    LinkList(const T *t,int n);
    LinkList(const LinkList &List);                //拷贝构造链表
    LinkList & operator=(const LinkList & List);  //赋值运算
    virtual ~LinkList();                          //析构

    Node<T> *Go(int n)throw(char);              //定位到第n个结点

    T & CurData() const;            //返回当前结点
    int Node_Num() const;           //返回当前链表的结点数

    void BeforeHead(const T &t);    //插入到首结点前
    void AfterCurNode(const T &t);  //插入到当前结点之后
    void AfterTail(const T &t);     //插入到尾结点之后

    void DeleteCurNode();           //删除当前结点
    void DeleteList();              //删除所有结点

    void Change(const T &t);        //修改当前结点数据

    void ShowCurData() const;       //输出当前结点数据
    void ShowList() const;          //输出所有结点数据

};

template <typename T> LinkList<T>::LinkList()                 //默认构造
{
    num=0;
    head=cur_node=NULL;
}

template <typename T> LinkList<T>::LinkList(const T *t,int n)
{
    Node<T> *p;
    head=NULL;
    for(int i=n-1;i>=0;i--)
    {
        p=new Node<T>(t[i]);
        p->next=head;
        head=p;
    }
    num=n;
    cur_node=head;
}

template <typename T>
LinkList<T>::LinkList(const LinkList<T> &list)   //拷贝构造
{
	Node<T> *p, *pTail, *temp=list.head;
	if((num=list.num)==0)
	{
		head = cur_node = NULL;
		return;
	}
	head = pTail = new Node<T>(list.head->data);
	if(list.head == list.cur_node) cur_node = head;
	for(int i=1; i<num; i++)
	{
		temp = temp->next;
		p = new Node<T>(temp->data);
		if(temp == list.cur_node) cur_node = p;
		pTail->next = p;
		pTail = p;
	}
	pTail->next = NULL;
}

template <typename T>
LinkList<T> & LinkList<T>::operator=(const LinkList<T> &list)  //赋值
{
	if(list.head==this->head) return *this;
	DeleteList();
	Node<T> *p, *pTail, *temp=list.head;
	if((num=list.num) == 0)
	{
		head = cur_node = NULL;
		return *this;
	}
	head = pTail = new Node<T>(list.head->data);
	if(list.head == list.cur_node) cur_node = head;
	for(int i=1; i<num; i++)
	{
		temp = temp->next;
		p = new Node<T>(temp->data);
		if(temp == list.cur_node) cur_node = p;
		pTail->next = p;
		pTail = p;
	}
	pTail->next = NULL;
	return *this;
}

template <typename T> LinkList<T>::~LinkList<T>()  //析构
{
	DeleteList();
	cout << "析构一条链表。" << endl;
}

template <typename T> Node<T> *LinkList<T>::Go(int n)throw(char)   //定位到第n个结点
{
    if(n<=0||n>num)
        throw (char)0;
	if((cur_node=head) == NULL) return cur_node;
	for(int i=1; i<n && cur_node!=NULL; i++)
		cur_node = cur_node->next;
	return cur_node;
}

template <typename T> T & LinkList<T>::CurData() const   //返回当前结点
{
	return cur_node->data;
}

template <typename T> int LinkList<T>::Node_Num() const  //返回链表结点数
{
	return num;
}

template <typename T>
void LinkList<T>::BeforeHead(const T &t)        //插入到首结点前
{
	num++;
	Node<T> *p = new Node<T>(t);
	p->next = head;
	head = p;
	cur_node = head;
}

template <typename T>
void LinkList<T>::AfterCurNode(const T &t)    //插入到当前结点后
{
	if(cur_node==NULL)
		AfterTail(t);
	else
	{
		num++;
		Node<T> *p = new Node<T>(t);
		p->next = cur_node->next;
		cur_node->next = p;
		cur_node = p;
	}
}

template <typename T> void LinkList<T>::AfterTail(const T &t)  //插入到尾结点后
{
	Node<T> *p = head;
	num++;
	if(head==NULL)
		head = p = new Node<T>(t);
	else
	{
		while(p->next != NULL)
			p = p->next;           //遍历整个链表
		p->next = new Node<T>(t);
		p = p->next;
	}
	p->next = NULL;
	cur_node = p;
}

template <typename T> void LinkList<T>::DeleteCurNode()  //删除当前结点
{
	if(cur_node==NULL) return;
	if(cur_node==head)           //删除头结点
	{
		num--;
		head = head->next;
		delete cur_node;
		cur_node = head;
		return;
	}

	Node<T> *p = head;
	while(p->next!=NULL && p->next!=cur_node)  //遍历
		p = p->next;
	if(p->next != NULL)
	{
		num--;
		p->next = cur_node->next;
		delete cur_node;
		cur_node = p->next;
	}
}

template <typename T> void LinkList<T>::DeleteList()  //删除所有结点
{
	Node<T> *p;
	while(head!=NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
	cur_node = NULL;
	num = 0;
}

template <typename T> void LinkList<T>::Change(const T &t)  //修改当前结点数据
{
	if(cur_node!=NULL)
		cur_node->data = t;
}

template <typename T> void LinkList<T>::ShowCurData() const  //输出当前结点数据
{
	if(cur_node!=NULL)
		cout << cur_node->data;
}

template <typename T> void LinkList<T>::ShowList() const //输出所有结点数据
{
	for(Node<T> *p=head; p!=NULL; p=p->next)
	{
	    cout<<p->data<<endl;
	}
}

#endif // LINKLIST_H_INCLUDED
