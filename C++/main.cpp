#include"SortFunctionBank.h"

int main()
{
	int flag;
	list r;
	r.key[0] = 0;
	listFullClear(r);
	menu();
	cin >> flag;
	while (flag != 10)
	{
		if (flag == 1)
		{
			listCountClear(r);
			BubbleSort(r);
			cout << "ÅÅÐòÍê³É" << endl;
		}
		if (flag == 2)
		{
			listCountClear(r);
			InsertSort(r);
			cout << "ÅÅÐòÍê³É" << endl;
		}
		if (flag == 3)
		{
			listCountClear(r);
			SelectSort(r);
			cout << "ÅÅÐòÍê³É" << endl;
		}
		if (flag == 4)
		{
			listCountClear(r);
			QuickSort(r);
			cout << "ÅÅÐòÍê³É" << endl;
		}
		if (flag == 5)
		{
			listCountClear(r);
			ShellSort(r,8);
			cout << "ÅÅÐòÍê³É" << endl;
		}
		if (flag == 6)
		{
			listCountClear(r);
			HeapSort(r);
			cout << "ÅÅÐòÍê³É" << endl;
		}
		if (flag == 7)
		{
			show(r);
		}
		if (flag == 8)
		{
			listFullClear(r);
			cout << "Çå³ýÍê³É" << endl;
		}
		if (flag == 9)
		{
			list q = r;
			BubbleSort(q);
			cout << "Ã°ÅÝÅÅÐò:" << endl;
			show(q);
			q = r;
			InsertSort(q);
			cout << "²åÈëÅÅÐò:" << endl;
			show(q);
			q = r;
			SelectSort(q);
			cout << "Ñ¡ÔñÅÅÐò:" << endl;
			show(q);
			q = r;
			QuickSort(q);
			cout << "¿ìËÙÅÅÐò:" << endl;
			show(q);
			q = r;
			ShellSort(q,8);
			cout << "Ï£¶ûÅÅÐò:" << endl;
			show(q);
			q = r;
			HeapSort(q);
			cout << "¶ÑÅÅÐò:" << endl;
			show(q);
		}
		menu();
		cin >> flag;
	}
	return 0;
}