#include "stdafx.h"
#include "List.h"
#include <iostream>

//добавление элемента в конец списка
void List::push(T _data)
{
	Node *tmp = new Node;
	tmp->data = _data;
	tmp->next = head;
	head = tmp;
}

//выталкивание последнего элемента
T List::pop()
{
	Node *prev = NULL;
	T _data;
	if (head == NULL)
		return NULL;
	prev = head;
	_data = prev->data;
	head = head->next;
	free(prev);
	return _data;
}

//вставка элемента на место другого
void List::insert(T _data, unsigned int n)
{
	unsigned int i = 0;
	Node * tmp = NULL;
	Node *_head = head;
	//находим нужный элемент, если не находим свтавка в конец
	while (i < n && _head->next)
	{
		_head = _head->next;
		i++;
	}

	tmp = new Node; tmp->data = _data;
	if (_head->next)
		tmp->next = _head->next;
	else
		tmp->next = NULL;
	_head->next = tmp;

	head = _head;
}

//удаление первого элемента
void List::delete_first()
{
	pop();
}

//удаление последнего
void List::delete_last()
{
	Node * tmp = NULL;
	Node * prev = NULL;

	if (!head)
		return;
	
	tmp = head;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}

	if (prev == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		free(tmp->next);
		prev->next = NULL;
	}

}

//получение н-го элемента
Node * List::get_n(unsigned int n)
{
	Node * tmp = head;
	int c = 0;
	while (c < n && tmp)
	{
		tmp = tmp->next;
		c++;
	}
	return tmp;
}

//удаление н-го элемента
void List::delete_n(unsigned int n)
{
	if (n == 0)
		pop();
	else
	{
		Node * prev = get_n(n - 1);
		Node * elm = prev->next;
		T _data = elm->data;

		prev->next = elm->next;
		free(elm);
	}
}

//возвращает длинну списка
unsigned int List::length()
{
	Node * tmp = head;
	
	unsigned int i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return i;
}

//конструктор списка
List::List()
{
	head = NULL;
}

//деструктор списка
List::~List()
{
	while (head->next)
	{
		pop();
		head = head->next;
	}
	free(head);
}
