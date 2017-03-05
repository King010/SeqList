
#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node, *PNode;


void InitList(PNode* pHead);
void PushBack(PNode* pHead, DataType data);
void PopBack(PNode* pHead);
void PushFront(PNode* pHead, DataType data);
void PopFront(PNode* pHead);
PNode Find(PNode pHead, DataType data);
void Insert(PNode pos, DataType data);
void Erase(PNode* pHead, PNode pos);
void Remove(PNode* pHead, DataType data);
void RemoveAll(PNode* pHead, DataType data);
int Empty(PNode pHead);
void Clear(PNode* pHead);
void Destroy(PNode* pHead);
int Size(PNode pHead);
PNode BuyBode(DataType data);
void PrintList(PNode pHead);
void ReversePrintList(PNode	pHead);
void BubbleSort(PNode pHead);
PNode MergeList(PNode pHead1, PNode pHead2);

int IsCross(PNode pHead1, PNode pHead2);
PNode GetCrossNode(PNode pHead1, PNode pHead2);
PNode HasCircle(PNode pHead);
int GetCirclelen(PNode pMeetNode);
PNode GetEnterNode(PNode pHead, PNode pMeetNode);  // 在邮件中给出推理
int IsCrossWithCircle(PNode pHead1, PNode pHead2); // 在邮件中给出带环可能相交的几种情况
void UnionSet(Node* l1, Node* l2);


////////////////////////////////////////////////////
void ResversePrintList(PNode pHead);
void DeleteNotTailNode(PNode pos);
void InsertNotHeadNode(PNode pos, DataType data);
PNode Back(PNode PHead);
PNode  JosephCircle(PNode PHead, int m);


void InitList(PNode* pHead)
{
	assert(pHead);
	(*pHead) = NULL;
}

void PushBack(PNode* pHead, DataType data)
{
	assert(pHead);
	if (NULL == *pHead)
	{
		*pHead = BuyBode(data);
	}
	else
	{
		PNode PTailNode = *pHead;
		while (PTailNode->next)
		{
			PTailNode = PTailNode->next;
		}
		PTailNode->next = BuyBode(data);
	}
}

void PopBack(PNode* pHead)
{
	assert(pHead);
	if (NULL == *pHead)
	{
		return;
	}
	if (NULL == (*pHead)->next)
	{
		free(*pHead);
	}
	else
	{
		PNode PPreNode = *pHead;
		PNode PDelNode = *pHead;
		while (PDelNode->next)
		{
			PPreNode = PDelNode;
			PDelNode = PDelNode->next;
		}
		free(PDelNode);
		PPreNode->next = NULL;
	}
}


PNode BuyBode(DataType data)
{
	PNode PTemp = (PNode)malloc(sizeof(Node));
	if (PTemp)
	{
		PTemp->data = data;
		PTemp->next = NULL;
	}
	return PTemp;
}

void PrintList(PNode pHead)
{

	PNode cur = NULL;
	//assert(pHead);
	cur = pHead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}

void PushFront(PNode* pHead, DataType data)
{
	assert(pHead);
	PNode PNewNode = NULL;
	PNewNode = BuyBode(data);
	if (PNewNode)
	{
		PNewNode->next = *pHead;
		*pHead = PNewNode;
	}
}

void PopFront(PNode* pHead)
{
	assert(pHead);
	if (NULL == *pHead)
	{
		return;
	}
	else
	{
		PNode PDelNode = *pHead;
		*pHead = (*pHead)->next;
		free(PDelNode);
		PDelNode = NULL;
	}
}

PNode Find(PNode PHead, DataType data)
{
	PNode pCurNode = PHead;
	while (pCurNode)
	{
		if (pCurNode->data == data)
		{
			return pCurNode;
		}
		pCurNode = pCurNode->next;
	}
	return NULL;
}


void Insert(PNode pos, DataType data)
{
	PNode PNewNode = NULL;
	if (NULL == pos)
	{
		return;
	}
	PNewNode = BuyBode(data);
	if (PNewNode)
	{
		PNewNode->next = pos->next;
		pos->next = PNewNode;
	}
}

void InsertNotHeadNode(PNode pos, DataType data)
{
	PNode pNewNode = NULL;
	if (pos == NULL)
	{
		return;
	}
	pNewNode = BuyBode(pos->data);
	pNewNode->next = pos->next;
	pos->next = pNewNode;
	pos->data = data;
}

void Erase(PNode *pHead, PNode pos)
{
	assert(pHead);
	if (NULL == pHead)
	{
		return;
	}
	if (*pHead == pos || NULL == pos)
	{
		*pHead = pos->next;
		free(pos);
	}
	else
	{
		PNode pPrePos = *pHead;
		while (pPrePos && pPrePos->next != pos)
		{
			pPrePos = pPrePos->next;
		}
		if (pPrePos)
		{
			pPrePos->next = pos->next;
			free(pos);
		}
	}
}

void DeleteNotTailNode(PNode pos)
{
	PNode pDelNode = NULL;
	if (NULL == pos || NULL == pos->next)
	{
		return;
	}
	pDelNode = pos->next;
	pos->data = pDelNode->data;
	pos->next = pDelNode->next;
	free(pDelNode);
}

void ResversePrintList(PNode pHead)
{
	if (NULL == pHead)
	{
		return;
	}
	else
	{
		ResversePrintList(pHead->next);
		printf("%d ", pHead->data);
	}
}

int Size(PNode pHead)
{
	int icount = 0;
	while (pHead)
	{
		pHead = pHead->next;
		icount++;
	}
	return icount;
}

int Empty(PNode pHead)
{
	if (pHead == NULL)
	{
		return 0;
	}
	else
		return 1;
}
void Clear(PNode* pHead)
{
	PNode q, p;
	p = (*pHead)->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*pHead)->next = NULL;
}

void Destroy(PNode* pHead)
{
	PNode q;
	while (*pHead)
	{
		q = (*pHead)->next;
		free(*pHead);
		*pHead = q;
	}
}

void Remove(PNode *pHead, DataType data)
{
	PNode pNewNode = NULL;
	assert(pHead);
	pNewNode = Find(*pHead, data);
	if (pNewNode == NULL)
	{
		return;
	}
	Erase(pHead, pNewNode);
}

void RemoveAll(PNode* pHead, DataType data)
{
	PNode PPreNode = *pHead;
	while (PPreNode)
	{
		PNode PDelNode = *pHead;
		PDelNode = Find(*pHead, data);
		if (PDelNode == NULL)
			return;
		Erase(pHead, PDelNode);
	}
	/*
	assert(pHead);
	PNode DelNode = *pHead;
	if (DelNode == NULL)
	return;
	while (DelNode = Find(*pHead, data))
	{
	Erase(pHead, DelNode);
	}*/
}

//
//PNode  JosephCircle(PNode PHead, int m)
//{
//	int count = 0;
//	PNode DelNode = NULL;
//	PNode posNode = PHead;
//	if (PHead == NULL || m <= 0)
//		return NULL;
//	while (posNode->next != posNode)
//	{
//		count = m;
//		while (--count)
//		{
//			posNode = posNode->next;
//		}
//		DelNode = posNode->next;
//		posNode->data = DelNode->data;
//		posNode->next = DelNode->next;
//		free(DelNode);
//	}
//	return posNode;
//}

PNode JosephCircle(PNode pHead, int M)//约瑟夫环
{
	PNode DelNode = NULL;
	PNode posNode = pHead;
	int count = 0;
	//  空链表 或者M 为0
	if (NULL == pHead || M <= 0)
	{
		return NULL;
	}
	while (posNode->next != posNode)
	{
		count = M;
		while (--count)
		{
			posNode = posNode->next;
		}
		DelNode = posNode->next;
		posNode->data = DelNode->data;
		posNode->next = DelNode->next;
		free(DelNode);
	}
	return posNode;
}


PNode Back(PNode PHead)//找最后一个节点
{
	PNode ppreNode = PHead;
	if (ppreNode == NULL)
	{
		return NULL;
	}
	while (ppreNode->next)
	{
		ppreNode = ppreNode->next;
	}
	return ppreNode;
}


void ReversePrintList(PNode	pHead)//你需打印单链表，递归实现
{
	if (NULL == pHead)
		return;
	else
	{
		ReversePrintList(pHead->next);
		printf("%d", pHead->data);
	}
}

void BubbleSort(PNode pHead)//链表冒泡排序
{

	PNode pTailNode = NULL;
	PNode prePos = pHead;
	PNode pos = NULL;
	while (pTailNode != pHead)
	{
		prePos = pHead;
		pos = prePos->next;
		while (pos != pTailNode)
		{
			if (prePos->data > pos->data)
			{
				DataType temp = prePos->data;
				prePos->data = pos->data;
				pos->data = temp;
			}
			prePos = pos;
			pos = pos->next;


		}
		pTailNode = prePos;
	}
}

PNode MergeList(PNode pHead1, PNode pHead2)//合并两个单链表，合并后依然有序
{
	PNode pNewNode = NULL;
	PNode p1 = pHead1;
	PNode p2 = pHead2;
	PNode pTailNode = NULL;
	if (NULL == p1)
	{
		return p2;
	}
	if (NULL == p2)
	{
		return p1;
	}
	if (p1->data <= p2->data)
	{
		pNewNode = p1;
		pTailNode = p1;
		p1 = p1->next;
	}
	while (p1 && p2)
	{
		if (p1->data <= p2->data)
		{
			pTailNode->next = p1;
			p1 = p1->next;
		}
		else
		{
			pTailNode->next = p2;
			p2 = p2->next;
		}
		pTailNode = pTailNode->next;
	}
	if (NULL == p1)
	{
		pTailNode = p2;
	}
	if (NULL == p2)
	{
		pTailNode = p1;
	}
	return pNewNode;
}

PNode FindMidNode(PNode pHead)//查找中间节点
{
	PNode pFast = pHead;
	PNode pSlow = pHead;
	// 判断链表是否为空 
	while (pFast && pFast->next)// 判断是否到达末尾
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}

PNode FindLastKNode(PNode pHead, int k)//倒数第K个节点
{
	PNode pFast = pHead;
	PNode pSlow = pHead;
	if (NULL == pHead || k <= 0)
	{
		return NULL;
	}
	while (k--)
	{
		// 可能k大于链表的大小
		if (NULL == pFast)
			return NULL;
		pFast = pFast->next;
	}
	while (pFast)
	{
		pFast = pFast->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}

PNode ReverseList(PNode pHead)
{
	PNode preNode = NULL;
	PNode pCurNode = NULL;
	PNode pNextNode = NULL;
	if (NULL == pHead || NULL == pHead->next)
	{
		return pHead;
	}
	preNode = pHead;
	pCurNode = preNode->next;
	pNextNode = pCurNode->next;
	while (pCurNode->next)
	{
		pCurNode->next = preNode;
		preNode = pCurNode;
		pCurNode = pNextNode;
		pNextNode = pNextNode->next;
	}
	pCurNode->next = preNode;
	pHead->next = NULL;
	return pCurNode;
}

int GetCirclelen(PNode pMeetNode)
{
	PNode pCurNode = pMeetNode;
	int count = 1;
	if (NULL == pMeetNode)
		return 0;
	while (pCurNode->next != pMeetNode)
	{
		pCurNode = pCurNode->next;
		count++;
	}
	return count;
}

int IsCross(PNode pHead1, PNode pHead2)
{
	if (NULL == pHead1 || NULL == pHead2)
	{
		return 0;
	}
	while (pHead1->next)
	{
		pHead1 = pHead1->next;
	}
	while (pHead2->next)
	{
		pHead2 = pHead2->next;
	}
	if (pHead1 == pHead2)
	{
		return 1;
	}
	return 0;
}

PNode GetCrossNode(PNode pHead1, PNode pHead2)
{
	int len1 = 1;
	int len2 = 1;
	PNode pnode1 = pHead1;
	PNode pnode2 = pHead2;
	if (pHead1 == NULL || pHead2 == NULL)
		return NULL;
	while (pnode1->next)
	{
		pnode1 = pnode1->next;
		len1++;
	}
	while (pnode2->next)
	{
		pnode2 = pnode2->next;
		len2++;
	}
	if (pnode1 != pnode2)
		return NULL;
	if (len1 > len2)
	{
		int k = len1 - len2;
		while (k--)
		{
			pHead1 = pHead1->next;
		}
	}
	else
	{
		int k = len2 - len1;
		while (k--)
		{
			pHead2 = pHead2->next;
		}
	}
	while (pHead1 != pHead2)
	{
		pHead1 = pHead1->next;
		pHead2 = pHead2->next;
	}
	return pHead1;
}

PNode GetEnterNode(PNode pHead, PNode pMeetNode)

{
	PNode pEnterNode = NULL;
	PNode pnode = pHead;
	while (pnode != pMeetNode)
	{
		pnode = pnode->next;
		pMeetNode = pMeetNode->next;
	}
	pEnterNode = pnode;
	return pEnterNode;
}

int IsCrossWithCircle(PNode pHead1, PNode pHead2)
{
	PNode pMeetNode1 = HasCircle(pHead1);
	PNode pMeetNode2 = HasCircle(pHead2);
	if (pHead1 == NULL || pHead1 == NULL)
	{
		return 0;
	}

	// 两个链表都不带环

	if ((pMeetNode1 == NULL) && (pMeetNode2 == NULL))
	{
		return IsCross(pHead1, pHead2);
	}
	if ((pMeetNode1 != NULL) && (pMeetNode2 != NULL))

	{

		PNode pCurNode = pMeetNode1;

		while (pMeetNode1 != pCurNode->next)

		{
			if (pMeetNode2 == pCurNode)
				return 2;
			pCurNode = pCurNode->next;
			if (pMeetNode2 == pCurNode)
			{
				return 2;
			}
		}

	}

	return 0;
}