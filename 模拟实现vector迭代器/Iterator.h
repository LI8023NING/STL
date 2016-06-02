#pragma once
#include<assert.h>
//模拟实现简化版的vector迭代器

template<class T>
class Vector
{
public:
	typedef T ValueType;
	typedef ValueType* Pointer;
	typedef ValueType* Iterator;
	typedef ValueType& Reference;

	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endStorage(nullptr)
	{}
public:
	Iterator Begin();
	Iterator End();
	size_t Size();
	size_t Cpapcity();
	void PushBack(const T& key);
	void PopBack();

	//返回删除数据的下一个数据 erase
	Iterator Erase(Iterator position);

	//判断是否需要扩容
	void _CheckCapacity();

private:
	Iterator _start;  //数据开头
	Iterator _finish; //有效数据尾部
	Iterator _endStorage; //存储容量的尾部
};

template<class T>
Iterator Vector<T>::Begin()
{
	return _start;
}

template<class T>
Iterator Vector<T>::End()
{
	return _finish;
}

template<class T>
size_t Vector<T>::Size()
{
	return _finish - _start;  //地址连续，可以减
}

template<class T>
size_t Vector<T>::Cpapcity()
{
	return _endStorage - _start;
}

template<class T>
void Vector<T>::_CheckCapacity()
{
	if (_finish == _endStorage)
	{
		size_t size = Size();
		size_t newcpapcity = size * 2 + 3;
		T* tmp = new T[newcpapcity];
		if (_start)
		{
			memcpy(tmp,0,sizeof(T)*newcpapcity);
		}

		_start = tmp;
		_finish = _start + size;
		_endStorage = _start + newcpapcity;
	}
}

template<class T>
void Vector<T>::PushBack(const T& key)
{
	_CheckCapacity();

	*_finish = key;
	finish++;
	Size++;
}


void Test()
{
	Vector<int> v1;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);
	v1.PushBack(5);
	v1.PushBack(8);
	v1.PushBack(7);
	v1.PushBack(9);
	v1.PushBack(6);

	Vector<int>::Iterator it = v1.Begin();
	for (; it != v1.End(); ++it)
	{
		cout << *it << "  ";
	}
	cout << endl;
}