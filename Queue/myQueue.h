#pragma once
#include "queueADT.h"

template <class Type>
class myQueue
{
private:
	Type* list;
	int count;
	int maxSize;
	int front;
	int rear;
public:
	myQueue(int size);

	myQueue(const myQueue&);

	~myQueue();

	bool isEmptyQueue() const;

	bool isFullQueue() const;

	void initializeQueue();

	Type frontQueue() const;

	Type backQueue() const;

	void printQueue();

	void addQueue(const Type& queueElement);

	void deleteQueue();

	const myQueue<Type>& operator=
		(const myQueue<Type>&);
};

template <class Type>
myQueue<Type>::myQueue(int size)
{
	maxSize = size;
	count = 0;
	front = 0;
	rear = maxSize - 1;

	list = new Type[maxSize];
}

template <class Type>
myQueue<Type>::myQueue(const myQueue& otherQueue)
{
	maxSize = otherQueue.maxSize;
	count = otherQueue.count;
	front = otherQueue.front;
	rear = otherQueue.rear;

	list = new Type[maxSize];

	for (int i = front; i <= rear; i++)
		list[i] = otherQueue.list[i];
}

template <class Type>
myQueue<Type>::~myQueue()
{
	delete[] list;
}

template <class Type>
bool myQueue<Type>::isEmptyQueue() const
{
	return (count == 0);
}

template <class Type>
bool myQueue<Type>::isFullQueue() const
{
	return (count == maxSize);
}

template <class Type>
void myQueue<Type>::initializeQueue()
{
	count = 0;
	front = 0;
	rear = maxSize - 1;
}

template <class Type>
Type myQueue<Type>::frontQueue() const
{
	//assert(!isEmptyQueue());
	return *(list + front);
}

template <class Type>
Type myQueue<Type>::backQueue() const
{
	//assert(!isEmptyQueue());
	return *(list + rear);
}

template <class Type>
void myQueue<Type>::printQueue()
{
	if (isEmptyQueue())
	{
		std::cout << "ERROR: Queue is empty!\n";
	}
	else
	{
		for (int i = front; i <= rear; i++)
		{
			std::cout << *(list + i) << std::endl;
		}
	}
}

template <class Type>
void myQueue<Type>::addQueue(const Type& queueElement)
{
	if (isFullQueue())
	{
		std::cout << "ERROR: Queue is full!\n";
	}
	else
	{
		rear = (rear + 1) % maxSize;
		count++;
		*(list + rear) = queueElement;
	}

}

template <class Type>
void myQueue<Type>::deleteQueue()
{
	if (isEmptyQueue())
	{
		std::cout << "ERROR: Queue is empty!\n";
	}
	else
	{
		front = (front + 1) % maxSize;
	}
}

template <class Type>
const myQueue<Type>& myQueue<Type>::operator= (const myQueue<Type>& otherQueue)
{
	delete[] list;

	maxSize = otherQueue.maxSize;
	count = otherQueue.count;
	front = otherQueue.front;
	rear = otherQueue.rear;

	list = new Type[maxSize];

	for (int i = front; i <= rear; i = (i + 1) % maxSize)
		*(list + i) = *(otherQueue.list + i);

	return *this;
}