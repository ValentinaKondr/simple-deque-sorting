#pragma once

class MyDeque
{
	struct Node
	{
		int element;
		Node* prev;
		Node* next;
	};
private:
	Node* head;
	Node* tail;
	int size;		
public:
	MyDeque();
	void pushFront(int);
	void pushBack(int);
	bool isEmpty();
	int popFront(void);
	int popBack(void);
	int top();
	int bottom();
	int getSize();
	void showIt();
	void clear(void);
	void bSort();
	~MyDeque();
};
void trySort(int size, const MyDeque& deque);

#endif // !DEQUE
