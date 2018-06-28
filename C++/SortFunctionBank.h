#pragma once
#include<iostream>
using namespace std;

#define M 106 //��������Ϊ105,0��λ��Ϊ��������λ��Ƚ�λ

struct list//������
{
	int key[M];
	int compareCount = 0;//��¼�Ƚϴ���
	int moveCount = 0;//��¼�����ƶ�����
};

void InsertSort(list &a)//��������
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

void ShellInsert(list &l, int dk)//ϣ�����뷨
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

void ShellSort(list &l, int t)//ϣ������
{//����������dt[0������t-1]
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

void BubbleSort(list &l)//ð������
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

int Partition(list &l, int low, int high)//��������ָ��
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

void QSort(list &L, int low, int high)//��������ָ��ݹ�
{
	if (low < high)
	{
		int pivotloc = Partition(L, low, high);
		QSort(L, low, pivotloc - 1);
		QSort(L, pivotloc + 1, high);
	}
}

void QuickSort(list &L)//��������ִ�к���
{
	QSort(L, 1, M);
}

void SelectSort(list &l)//ѡ������
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

void HeapAdjust(list &l, int s, int m)//������ѵ�������
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

void creatHeap(list &l)//������
{
	int n = M;
	for (int i = n / 2; i > 0; --i)
	{
		HeapAdjust(l, i, n);
	}
}

void HeapSort(list &l)//������
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

void listCountClear(list &l)//�����������ʱ����λ��
{
	l.key[0] = 0;
	l.compareCount = 0;
	l.moveCount = 0;
}

void listFullClear(list &l)//ȫ�������µ������������������
{
	for (int i = 1; i < 107; i++)
	{
		l.key[i] = (rand() % (200)) + 1;
	}
	l.compareCount = 0;
	l.moveCount = 0;
}

void show(list l)//չʾ�б����ݣ�ʮ���һ��
{
	for(int i= 1;i<M;i++)
	{
		cout << l.key[i] << " ";
		if (i%15==0)
			cout << endl;
	}
	//cout << endl;
	cout << "�Ƚϴ�����" << l.compareCount << endl;
	cout << "�ƶ�������" << l.moveCount << endl;
}

void menu()//�˵�����
{
	cout << endl;
	cout << "��ѡ�����¹��ܣ�" << endl;	
	cout << "1.��������" << endl;
	cout << "2.��������" << endl;
	cout << "3.ѡ������" << endl;
	cout << "4.��������" << endl;
	cout << "5.ϣ������" << endl;
	cout << "6.������" << endl;
	cout << "7.���Ŀǰ������,�Լ��Ƚϴ���" << endl;
	cout << "8.���Ŀǰ������,�Լ��Ƚϴ���������һ���µ�����" << endl;
	cout << "9.��һ�����ݽ�������6������չʾ�Ƚϴ������ƶ�����" << endl;
	cout << "10.�˳�����" << endl;
}