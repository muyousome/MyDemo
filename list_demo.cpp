/*
2012年11月23日19:42:55

单链表的相关操作
*/


#include<stdio.h>
#include<stdlib.h>

///////////结点定义////////////////
struct Node
{
	int data;
	struct Node *pNext;
};


//////////////函数声明/////////////
struct Node * CreatList(int len);
void DispList(struct Node *pHead);
bool Delete(struct Node *pHead,int n);
int ListLength(struct Node *pHead);




///////////////////////////
int main(void)
{
	struct Node * pHead;
	int len;
	printf("输入第要生成的链表长度：");
	scanf("%d",&len);
	pHead = CreatList(len);
	DispList(pHead);
	Delete((struct Node *)pHead,3);
	printf("链表长度为%d\n",ListLength((struct Node *)pHead));
	DispList(pHead);
	return 0;

}




///////////建立单链表（尾插法）//////////////////
struct Node * CreatList(int len)
{
	int i;
	//int val;
	struct Node * PHead;//头指针
	struct Node * pNew;
	struct Node * pTail;//尾指针
	
	PHead = (struct Node *)malloc(sizeof(struct Node));  // 建立头结点
	PHead -> pNext = NULL;
	pTail = PHead;
	//printf("长度len");
	//scanf("%d",&len);
	
	for(i=0;i<len;++i)
	{
		//printf("输入第%d个元素",i+1);
		//scanf("%d",&val);
		pNew = (struct Node *)malloc(sizeof(struct Node)); //建立新节点
		pTail -> pNext = pNew;
		pTail = pNew;
		pNew->pNext = NULL;
		pNew->data = rand()%100+1;
 	}
	return PHead;
}



////////////////遍历输出//////////////
void DispList(struct Node *pHead)
{
	struct Node *p = pHead->pNext;
	while(NULL != p)
	{
		printf("%d",p->data);
		p = p->pNext;
		printf("\n");
	}
}

////////////输出长度//////////////
int ListLength(struct Node *pHead)
{
	struct Node *p =pHead->pNext;
	int i = 0;
	while(NULL != p)
	{
		p = p->pNext;
		i++;
	}
	return i;
}

///////////删除结点//////////
bool Delete(struct Node *pHead,int n)
{
	int m = ListLength(pHead);
	struct Node *p;
	int val = p->pNext->data;
	
/*
	struct Node *p = pHead;
	while(i<n-1 && NULL != p)
	{
		i++;
		p = p->pNext;
	}	
	if(n>)
	{	
		return false;
	}
*/	
	printf("删除的元素为:%d\n",m);
	
	p->pNext = p->pNext->pNext;
	return true;
}