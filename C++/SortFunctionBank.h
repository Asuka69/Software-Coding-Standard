#pragma once
#include<iostream>
using namespace std;

#define M 106 //数据总量为105,0号位作为交换参照位或比较位

struct list//数字列
{
	int key[M];
	int compareCount = 0;//记录比较次数
	int moveCount = 0;//记录数据移动次数
};

void InsertSort(list &a)//插入排序
{
	int j = 0;
	for (int i = 2; i < M; i++)
	{
		if (a.key[i] < a.key[i - 1])
		{
			a.compareCount++;
			a.key[0] = a.key[i];
			a.moveCount++;
			a.key[i] = a.key[i - 1];
			a.moveCount++;
			for (j = i - 2; a.key[0] < a.key[j]; --j)
			{
				a.compareCount++;
				a.key[j + 1] = a.key[j];
				a.moveCount++;
			}
			a.key[j + 1] = a.key[0];
			a.moveCount++;
		}
	}
}

void ShellInsert(list &l, int dk)//希尔插入法
{
	int j;
	for (int i = dk + 1; i < M; ++i)
	{
		if (l.key[i] < l.key[i - dk])
		{
			l.compareCount++;
			l.key[0] = l.key[i];
			l.moveCount++;
			for (j = i - dk; j > 0 && l.key[0] < l.key[j]; j -= dk)
			{
				l.compareCount++;
				l.key[j + dk] = l.key[j];
				l.moveCount++;
			}
			l.key[j + dk] = l.key[0];
			l.moveCount++;
		}
	}
}

void ShellSort(list &l, int t)//希尔排序
{//按增量序列dt[0···t-1]
	int dt[8];
	for (int i = 0; i < 8; i++)
	{
		dt[i] = 35-i*5;
		if (i == 7)
			dt[i] = 1;
	}
	for (int k=0; k < t; ++k)
		ShellInsert(l, dt[k]);
}

void BubbleSort(list &l)//冒泡排序
{
	int m = M - 1, flag = 1,temp;
	while ((m > 0) && (flag == 1))
	{
		flag = 0;
		for (int j = 1; j <= m; j++)
		{
			if (l.key[j] > l.key[j + 1])
			{
				l.compareCount++;
				flag = 1;
				temp = l.key[j]; l.key[j] = l.key[j + 1]; l.key[j + 1] = temp;
				l.moveCount += 3;
			}
		}
		--m;
	}
}

int Partition(list &l, int low, int high)//快速排序分割函数
{
	l.key[0] = l.key[low];
	int pivotkey = l.key[low];
	while (low<high)
	{
		while (low<high&&l.key[high] >= pivotkey) {
			--high;
			l.compareCount++;
		}
		l.key[low] = l.key[high];	l.moveCount++;
		while (low<high&&l.key[low] <= pivotkey)
		{
			++low;
			l.compareCount++;
		}
		l.key[high] = l.key[low];
		l.moveCount++;
	}
	return low;
}

void QSort(list &L, int low, int high)//快速排序分割后递归
{
	if (low < high)
	{
		int pivotloc = Partition(L, low, high);
		QSort(L, low, pivotloc - 1);
		QSort(L, pivotloc + 1, high);
	}
}

void QuickSort(list &L)//快速排序执行函数
{
	QSort(L, 1, M);
}

void SelectSort(list &l)//选择排序
{
	int k;
	for (int i = 1; i < M; i++)
	{
		k = i;
		for (int j = i + 1; j <= M; ++j)
			if (l.key[j] < l.key[k])
			{
				l.compareCount++;
				k = j;
			}
		if (k != i)
		{
			int temp = l.key[i];
			l.key[i] = l.key[k];
			l.key[k] = temp;
			l.moveCount += 3;
		}
	}
}

void HeapAdjust(list &l, int s, int m)//堆排序堆调整函数
{
	int rc = l.key[s];
	l.moveCount++;
	for (int j = 2 * s; j <= m; j *= 2)
	{
		if (j < m&&l.key[j] < l.key[j + 1])
		{
			++j;
			l.compareCount++;
		}
		if (rc >= l.key[j]) 
		{ 
			l.compareCount++;
			break; 
		}
		l.key[s] = l.key[j];
		l.moveCount++;
		s = j;
	}
	l.key[s] = rc;
	l.moveCount++;
}

void creatHeap(list &l)//创建堆
{
	int n = M;
	for (int i = n / 2; i > 0; --i)
	{
		HeapAdjust(l, i, n);
	}
}

void HeapSort(list &l)//堆排序
{
	creatHeap(l);
	for (int i = M; i > 1; --i)
	{
		int x = l.key[1];
		l.key[1] = l.key[i];
		l.key[i] = x;
		l.moveCount += 3;
		HeapAdjust(l, 1, i - 1);
	}
}

void listCountClear(list &l)//清除记数和临时参数位置
{
	l.key[0] = 0;
	l.compareCount = 0;
	l.moveCount = 0;
}

void listFullClear(list &l)//全部产生新的随机数，将参数清零
{
	for (int i = 1; i < 107; i++)
	{
		l.key[i] = (rand() % (200)) + 1;
	}
	l.compareCount = 0;
	l.moveCount = 0;
}

void show(list l)//展示列表内容，十五个一行
{
	for(int i= 1;i<M;i++)
	{
		cout << l.key[i] << " ";
		if (i%15==0)
			cout << endl;
	}
	//cout << endl;
	cout << "比较次数：" << l.compareCount << endl;
	cout << "移动次数：" << l.moveCount << endl;
}

void menu()//菜单函数
{
	cout << endl;
	cout << "请选择以下功能：" << endl;	
	cout << "1.起泡排序" << endl;
	cout << "2.插入排序" << endl;
	cout << "3.选择排序" << endl;
	cout << "4.快速排序" << endl;
	cout << "5.希尔排序" << endl;
	cout << "6.堆排序" << endl;
	cout << "7.浏览目前的数列,以及比较次数" << endl;
	cout << "8.清除目前的数列,以及比较次数，生成一组新的数据" << endl;
	cout << "9.对一组数据进行上述6种排序并展示比较次数和移动次数" << endl;
	cout << "10.退出程序" << endl;
}