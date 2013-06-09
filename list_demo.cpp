/*
2012��11��23��19:42:55

���������ز���
*/


#include<stdio.h>
#include<stdlib.h>

///////////��㶨��////////////////
struct Node
{
	int data;
	struct Node *pNext;
};


//////////////��������/////////////
struct Node * CreatList(int len);
void DispList(struct Node *pHead);
bool Delete(struct Node *pHead,int n);
int ListLength(struct Node *pHead);




///////////////////////////
int main(void)
{
	struct Node * pHead;
	int len;
	printf("�����Ҫ���ɵ������ȣ�");
	scanf("%d",&len);
	pHead = CreatList(len);
	DispList(pHead);
	Delete((struct Node *)pHead,3);
	printf("������Ϊ%d\n",ListLength((struct Node *)pHead));
	DispList(pHead);
	return 0;

}




///////////����������β�巨��//////////////////
struct Node * CreatList(int len)
{
	int i;
	//int val;
	struct Node * PHead;//ͷָ��
	struct Node * pNew;
	struct Node * pTail;//βָ��
	
	PHead = (struct Node *)malloc(sizeof(struct Node));  // ����ͷ���
	PHead -> pNext = NULL;
	pTail = PHead;
	//printf("����len");
	//scanf("%d",&len);
	
	for(i=0;i<len;++i)
	{
		//printf("�����%d��Ԫ��",i+1);
		//scanf("%d",&val);
		pNew = (struct Node *)malloc(sizeof(struct Node)); //�����½ڵ�
		pTail -> pNext = pNew;
		pTail = pNew;
		pNew->pNext = NULL;
		pNew->data = rand()%100+1;
 	}
	return PHead;
}



////////////////�������//////////////
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

////////////�������//////////////
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

///////////ɾ�����//////////
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
	printf("ɾ����Ԫ��Ϊ:%d\n",m);
	
	p->pNext = p->pNext->pNext;
	return true;
}