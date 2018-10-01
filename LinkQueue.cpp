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
} ;                     //链队列结点
class LinkQueue
{
private:
	QueueNode *front;
	QueueNode *rear;
public:
	LinkQueue()               //构造一个新的空队列
	{    
		front=NULL;
		rear=NULL;
	};
	~LinkQueue()                  //销毁一个已存在的队列
	{
		QueueNode *p,*q;
		while(p)                   //删除链上的所有结点
		{
			q=p;
			p=p->next;
			delete q;
		}
		front =NULL;              //置为空表示空队列
		rear =NULL;               //置为空表示空队列
	};
	int Empty_Queue();             //判断队列是否为空
	int En_Queue(DataType e);      //将元素e插入队尾
	int De_Queue(DataType &e);     //从队头删除一个元素到e中返回
	int Front_Queue(DataType &e);  //从队头取出一个元素到E中返回
};

int LinkQueue::Empty_Queue()         //判断队列是否为空
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

int LinkQueue::En_Queue(DataType e)         //将元素e插入队尾
{
	QueueNode *p=new QueueNode;
	if(p)                         //申请结点成功
	{
		p->data =e;
		if(rear)            //原队列为非空队列，入队元素直接插入单链表的尾部
			rear->next  =p;
		else                //原队列为空队列，插入元素既是队头元素也是队尾元素
		rear=front=p;
		return 1;
	}
	else
		return 0;
	
}

int LinkQueue::De_Queue(DataType &e)          //从队头删除一个元素到e中返回
{
	QueueNode *p;
	if(Empty_Queue())                 //判断队列是否为空
		return 0;
	else
	{
		p=front;
		e=p->data;
		front=front->next ;          //修改队头指针
		if(!front)                   //删除出队元素后队列变成了空队列，要修改队尾指针
			rear=NULL;
		delete p;
		return 1;
	}
}

int LinkQueue:: Front_Queue(DataType &e)          //从队头取出一个元素到E中返回
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