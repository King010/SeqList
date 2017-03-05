#include<iostream>
#include<list>
#include"Seqlist.h"
using namespace std;


//1、实现斐波那契数列，递归和非递归形式，并分析其时间复杂度和空间复杂度
//2、实现二分查找，递归和非递归形式，并分析其时间复杂度
//3、用递归求n！
//4、用递归实现无头单链表的逆序打印和逆序删除
//5、用递归实现判断一个字符串是否是回文



int  Fibonacci(int i)
{
	int a = 1;
	int b = 1;
	int c = 0;
	i -= 2;
	while (i--)
	{
		c = a + b;
		b = a;
		a = c;
	}
	return c;
}

int FibonacciDiGui(int i)
{
	if (i == 0)
		return 0;
	if (i == 1)
		return 1;
	return FibonacciDiGui(i - 1) + FibonacciDiGui(i - 2);
}



int BinSearch(int array[], int left, int right, int key)
{
	right -= 1;
	while (left<=right)
	{
		int mid = (left + right) >> 1;
		if (array[mid] > key)
			right = mid - 1;
		if (array[mid] < key)
			left = mid + 1;
		if (array[mid] == key)
			return mid;
	}
	return -1;
}


int BinSearchDigui(int array[], int left, int right, int key)
{
	int mid = (left + right) >> 1;
	if (left <= right)
	{
		if (array[mid] == key)
			return mid;
		else if (array[mid]<key)
			{
				return BinSearchDigui(array, mid + 1, right, key);
			}
		else if (array[mid]>key)
			{
				return BinSearchDigui(array, left, mid - 1, key);
			}
	}
	else
	 return -1;
}

int Fac(int i)
{
	if (i == 0)
		return 1;
	return i*Fac(i - 1);
}

bool Huiwen(char* arr, int size, char left, char right)
{
	
	if (size == 0 || size == 1)
		return  true;
	if (arr[left] != arr[right])
		return false;
	return Huiwen(arr,size-2,left+1,right-1);
}

void ReversePrintf(list<int> *phead)
{
	if (phead == NULL)
		return;
	else
	{
		cout << phead->_Myval << endl;
		return ReversePrintf(phead->_Nextnode);
	}
}

int main()
{
	/*int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int idx = BinSearch(array, 0, 9, 1);
	cout << idx<<endl;*/
	/*int i=FibonacciDiGui(5);
	
	cout << i << endl;;
	int a = Fac(5);
	cout << a << endl;*/
	/*char array[] = "1231321";
	int i = Huiwen(array, strlen(array),0,strlen(array)-1);
	cout << i << endl;*/
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	
	system("pause");
	return 0;
}