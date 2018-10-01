#include <iostream>
using namespace std;
typedef int DataType;
class QueueNode
{
public:
	DataType data;
	QueueNode *next;
	QueueNode()
	{    next=NULL;
	};
} ;                     //�����н��
class LinkQueue
{
private:
	QueueNode *front;
	QueueNode *rear;
public:
	LinkQueue()               //����һ���µĿն���
	{    
		front=NULL;
		rear=NULL;
	};
	~LinkQueue()                  //����һ���Ѵ��ڵĶ���
	{
		QueueNode *p,*q;
		while(p)                   //ɾ�����ϵ����н��
		{
			q=p;
			p=p->next;
			delete q;
		}
		front =NULL;              //��Ϊ�ձ�ʾ�ն���
		rear =NULL;               //��Ϊ�ձ�ʾ�ն���
	};
	int Empty_Queue();             //�ж϶����Ƿ�Ϊ��
	int En_Queue(DataType e);      //��Ԫ��e�����β
	int De_Queue(DataType &e);     //�Ӷ�ͷɾ��һ��Ԫ�ص�e�з���
	int Front_Queue(DataType &e);  //�Ӷ�ͷȡ��һ��Ԫ�ص�E�з���
};

int LinkQueue::Empty_Queue()         //�ж϶����Ƿ�Ϊ��
{
	if(!front&&!rear)
	{
		cout<<"Empty!"<<endl;
		return 1;
	}
	else   
	{
		cout<<"Not Empty!"<<endl;
		return 0;
	}
}

int LinkQueue::En_Queue(DataType e)         //��Ԫ��e�����β
{
	QueueNode *p=new QueueNode;
	if(p)                         //������ɹ�
	{
		p->data =e;
		if(rear)            //ԭ����Ϊ�ǿն��У����Ԫ��ֱ�Ӳ��뵥�����β��
			rear->next  =p;
		else                //ԭ����Ϊ�ն��У�����Ԫ�ؼ��Ƕ�ͷԪ��Ҳ�Ƕ�βԪ��
		rear=front=p;
		return 1;
	}
	else
		return 0;
	
}

int LinkQueue::De_Queue(DataType &e)          //�Ӷ�ͷɾ��һ��Ԫ�ص�e�з���
{
	QueueNode *p;
	if(Empty_Queue())                 //�ж϶����Ƿ�Ϊ��
		return 0;
	else
	{
		p=front;
		e=p->data;
		front=front->next ;          //�޸Ķ�ͷָ��
		if(!front)                   //ɾ������Ԫ�غ���б���˿ն��У�Ҫ�޸Ķ�βָ��
			rear=NULL;
		delete p;
		return 1;
	}
}

int LinkQueue:: Front_Queue(DataType &e)          //�Ӷ�ͷȡ��һ��Ԫ�ص�E�з���
{
	if(!Empty_Queue())
	{
		e=front->data ;
		return 1;
	}
	else
		return 0;
}

int main()
{
	
	return 0;
}