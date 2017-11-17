#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include <iostream>
using namespace std;

template <typename T> class LinkList;         //��ǰ����������

template <typename T> class Node              //�����
{
private:
    T data;      //��������Ķ���
    Node *next;  //ָ����һ������ָ�����
public:
    Node(const T &t=0) : data(t){} //ð���﷨��ʼ����ϳ�Ա
    friend class LinkList<T>;    //������Ԫ��
};

template <typename T> class LinkList         //������
{
private:
    Node<T> *head,*cur_node;   //����ָ�롢��ǰ���ָ��
    int num;                  //�����

public:
    LinkList();                                     //Ĭ�Ϲ���
    LinkList(const T *t,int n);
    LinkList(const LinkList &List);                //������������
    LinkList & operator=(const LinkList & List);  //��ֵ����
    virtual ~LinkList();                          //����

    Node<T> *Go(int n)throw(char);              //��λ����n�����

    T & CurData() const;            //���ص�ǰ���
    int Node_Num() const;           //���ص�ǰ����Ľ����

    void BeforeHead(const T &t);    //���뵽�׽��ǰ
    void AfterCurNode(const T &t);  //���뵽��ǰ���֮��
    void AfterTail(const T &t);     //���뵽β���֮��

    void DeleteCurNode();           //ɾ����ǰ���
    void DeleteList();              //ɾ�����н��

    void Change(const T &t);        //�޸ĵ�ǰ�������

    void ShowCurData() const;       //�����ǰ�������
    void ShowList() const;          //������н������

};

template <typename T> LinkList<T>::LinkList()                 //Ĭ�Ϲ���
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
LinkList<T>::LinkList(const LinkList<T> &list)   //��������
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
LinkList<T> & LinkList<T>::operator=(const LinkList<T> &list)  //��ֵ
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

template <typename T> LinkList<T>::~LinkList<T>()  //����
{
	DeleteList();
	cout << "����һ������" << endl;
}

template <typename T> Node<T> *LinkList<T>::Go(int n)throw(char)   //��λ����n�����
{
    if(n<=0||n>num)
        throw (char)0;
	if((cur_node=head) == NULL) return cur_node;
	for(int i=1; i<n && cur_node!=NULL; i++)
		cur_node = cur_node->next;
	return cur_node;
}

template <typename T> T & LinkList<T>::CurData() const   //���ص�ǰ���
{
	return cur_node->data;
}

template <typename T> int LinkList<T>::Node_Num() const  //������������
{
	return num;
}

template <typename T>
void LinkList<T>::BeforeHead(const T &t)        //���뵽�׽��ǰ
{
	num++;
	Node<T> *p = new Node<T>(t);
	p->next = head;
	head = p;
	cur_node = head;
}

template <typename T>
void LinkList<T>::AfterCurNode(const T &t)    //���뵽��ǰ����
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

template <typename T> void LinkList<T>::AfterTail(const T &t)  //���뵽β����
{
	Node<T> *p = head;
	num++;
	if(head==NULL)
		head = p = new Node<T>(t);
	else
	{
		while(p->next != NULL)
			p = p->next;           //������������
		p->next = new Node<T>(t);
		p = p->next;
	}
	p->next = NULL;
	cur_node = p;
}

template <typename T> void LinkList<T>::DeleteCurNode()  //ɾ����ǰ���
{
	if(cur_node==NULL) return;
	if(cur_node==head)           //ɾ��ͷ���
	{
		num--;
		head = head->next;
		delete cur_node;
		cur_node = head;
		return;
	}

	Node<T> *p = head;
	while(p->next!=NULL && p->next!=cur_node)  //����
		p = p->next;
	if(p->next != NULL)
	{
		num--;
		p->next = cur_node->next;
		delete cur_node;
		cur_node = p->next;
	}
}

template <typename T> void LinkList<T>::DeleteList()  //ɾ�����н��
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

template <typename T> void LinkList<T>::Change(const T &t)  //�޸ĵ�ǰ�������
{
	if(cur_node!=NULL)
		cur_node->data = t;
}

template <typename T> void LinkList<T>::ShowCurData() const  //�����ǰ�������
{
	if(cur_node!=NULL)
		cout << cur_node->data;
}

template <typename T> void LinkList<T>::ShowList() const //������н������
{
	for(Node<T> *p=head; p!=NULL; p=p->next)
	{
	    cout<<p->data<<endl;
	}
}

#endif // LINKLIST_H_INCLUDED
