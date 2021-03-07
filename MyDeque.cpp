#include "stdafx.h"

#include <iostream>
#include <random>	//Генерация случайных чисел
#include <time.h>	// -//-

#include "MyDeque.h"

using namespace std;

//Создание пустого дека
MyDeque::MyDeque() : head(NULL), tail(NULL), size(0) {}

void MyDeque::pushFront(int value)
{
	// Создается новое звено, и, если
	// дек пуст, добавляет его, а ссылки на 
	// следующий и предыдущий элемент делает NULL
	// Иначе просто добавляет элемент 
	Node* newNode = new Node;
	if (isEmpty())
	{
		newNode->element = value;
		head = tail = newNode;
		newNode->next = newNode->prev = NULL;
		size++;
		return;
	}
	newNode->element = value;
	newNode->prev = NULL;
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	size++;
}

void MyDeque::pushBack(int value)
{
	Node* newNode = new Node;
	if (isEmpty())
	{
		newNode->element = value;
		head = tail = newNode;
		newNode->next = newNode->prev = NULL;
		size++;
		return;
	}
	newNode->element = value;
	newNode->next = NULL;
	newNode->prev = tail;
	tail->next = newNode;
	tail = newNode;
	size++;
}

bool MyDeque::isEmpty()
{
	return head && tail ? false : true;
}

int MyDeque::popFront(void)
{
	if(isEmpty())
	{
		cout << "Deque is empty\n";
		return -1;
	} 
	if (size == 1)
	{
		int buffValue = head->element;
		delete head;
		head = tail = NULL;
		size = 0;
		return buffValue;
	}
	int buffValue;
	buffValue = head->element;
	Node* buffRef = head;
	head->next->prev = NULL;
	head = head->next;
	size--;
	delete buffRef;
	return buffValue;
}

int MyDeque::popBack(void)
{
	if(isEmpty())
	{
		cout << "Deque is empty\n";
		return -1;
	} 
	if (size == 1)
	{
		int buffValue = head->element;
		delete head;
		head = tail = NULL;
		size = 0;
		return buffValue;
	}
	int buffValue;
	buffValue = tail->element;
	Node* buffRef = tail;
	tail->prev->next = NULL;
	tail = tail->prev;
	size--;
	delete buffRef;
	return buffValue;
}

int MyDeque::top()
{
	return head->element;
}

int MyDeque::bottom()
{
	return tail->element; 
}

int MyDeque::getSize()
{
	return size;
}

void MyDeque::clear()
{
	Node* buffRef;
	while(head != NULL)
	{
		buffRef = head;
		head = head->next;
		delete buffRef;
	}
	tail = head;
}

MyDeque::~MyDeque()
{
	clear();		
}

//Вывод на экран содержимого дека
void MyDeque::showIt()
{
	Node* buffRef = head;
	while(buffRef != NULL)
	{
		cout << buffRef->element << '\t';
		buffRef = buffRef->next;
	}
	cout << endl;
}

//Сортировка пузырьком
void MyDeque::bSort()
{
	Node* buffRef  = head;
	for(int j = size-1; j > 1; j--)
	{
		for(int i = 0; i < j; i++)
		{
			if (buffRef->element > buffRef->next->element)
			{
				int tmp = buffRef->element;
				buffRef->element = buffRef->next->element;
				buffRef->next->element = tmp;
			}
			buffRef = buffRef->next;
		}
		buffRef = head;
	}
}

void trySort(int size, const MyDeque& deque)
{
	srand(time(0));
	for(int i = 0; i < size; i++)
	{
		unsigned int num = ((rand() % 1000) - (1000 / 2 - 1));
		deque.pushBack(num);
	}
	cout << "Deque before sorting: \n";
	deque.showIt();
	cout << "Deque after sorting: \n";
	auto start = clock();
	deque.bSort();
	auto end = clock();
	deque.showIt();
	cout << "Sorting time is:\t" << end - start << endl; 
}
