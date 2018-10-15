#pragma once

//структура элемента списка
typedef void* T;
typedef struct Node
{
	T data;
	Node * next;
};


//класс списка
class List
{
public:
	List();
	~List();
	void push(T data);
	T pop();
	void insert(T data, unsigned int n);
	Node * get_n(unsigned int n);
	void delete_first();
	void delete_last();
	void delete_n(unsigned int n);
	unsigned int length();
private:
	Node * head;
};

