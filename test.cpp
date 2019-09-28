// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int maxSize = 100;
template<class T>
class SeqList
{
private:
	T* data;	//存放顺序表中的元素
	int length;	//存放顺序表的长度
public:
	SeqList();		//构造函数
	~SeqList();		//析构函数
	void CreatList(T a[], int n);		//由a数组中的元素构造顺序表
	void Print();		//打印顺序表
	int ListLength();	//求顺序表的长度
	bool Get(int i, T&item);	//取顺序表中某个位置的值
	int Locate(T item);			//按元素查找位置
	bool Insert(int i, T item);	//向顺序表中插入数据
	bool Delete(int i);		//在位置i上删除顺序表中的元素

	
};

template<class T>
SeqList<T>::SeqList()
{
	data = new T[maxSize];
	length = 0;
}
template<class T>
SeqList<T>::~SeqList()
{
	delete[]data;
}
template<class T>
void SeqList<T>::CreatList(T a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		data[i] = a[i];
		length = i;
	}
}

template<class T>
void SeqList<T>::Print()
{
	cout << "打印顺序表:" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << data[i] << " " ;
	}
}

template<class T>
int SeqList<T>::ListLength()
{
	return length;
}

template<class T>
bool SeqList<T>::Get(int i,T &item)
{
	if (i<0 || i>length)
		return false;
	item = data[i - 1];
	return true;
}

template<class T>
int SeqList<T>::Locate(T item)
{
	int i = 0;
	while (i < length && i != item)
		i++;
	if (i >= length)
		return 0;
	else
		return i + 1;
}

template<class T>
bool SeqList<T>::Insert(int i, T item)
{
	if (i<0 || i>length)
		return false;
	for(int j=length;j>=i;j--)
	{
		data[j] = data[j - 1];
	}
	data[i - 1] = item;
	length++;
	return true;
}

template<class T>
bool SeqList<T>::Delete(int i)
{
	if (i<0 || i>length)
		return false;
	for (int j = length; j >= i; j--)
	{
		data[j] = data[j - 1];
	}
	length--;
	return true;
}
int main()
{
	SeqList<int> seq;
	int array[8] = { 1,2,3,4,5,6,7,8 };
	seq.CreatList(array, 8);	//创建顺序表
	seq.Print();
	cout << endl;
	seq.ListLength();
	cout << "当前顺序表的长度为：" << seq.ListLength() << endl;
	int a;
	seq.Get(2, a);
	cout << "第二个数值为：" << a << endl;
	seq.Insert(3,5);
	cout << "插入后重新";
	seq.Print();
	cout << endl;
	seq.Delete(4);
	cout << "删除第4个位置后重新";
	seq.Print();
}

