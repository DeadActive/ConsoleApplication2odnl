// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Human.h"
#include "List.h"

#define HELP_HUMAN "\nList of commands:\n0 or return - exit \n1 - name\n2 - surname\n3 - sex\n4 - height\n5 - weight\n6 - phone\n7 - adress\n"
#define HELP_LIST "\nList of commands:\n0 or return - exit\n1 - add\n2 - delete(default last)\n3 - insert\n4 - edit\n5 - save\n6 - load\n7 - find\n8 - filter(e - equals, g - greather, l - less)\n"

//вывод в консоль всех элементов списка
void print_list(List * l)
{
	Human * tmp = NULL;
	unsigned int length = l->length();

	for (unsigned int i = 0; i < length; i++)
	{
		std::cout << i << "'n element" << std::endl;
		tmp = (Human*)(l->get_n(i)->data);
		tmp->print();
	}
}

//ввод с косоли нового человекаи выделение памяти под него
Human * input_human()
{
	std::string tmp;
	
	std::cout << "Name: "; std::getline(std::cin, tmp); Human * human = new Human(tmp.c_str());
	std::cout << "Surname: "; std::getline(std::cin, tmp); human->set_surname(tmp.c_str());
	std::cout << "Sex: "; std::getline(std::cin, tmp); human->set_sex(tmp.c_str());
	std::cout << "Height: "; std::getline(std::cin, tmp); human->set_height(tmp.c_str());
	std::cout << "Weight: "; std::getline(std::cin, tmp); human->set_weight(tmp.c_str());
	std::cout << "Phone: "; std::getline(std::cin, tmp); human->set_phone(tmp.c_str());
	std::cout << "Adress: "; std::getline(std::cin, tmp); human->set_adress(tmp.c_str());

	return human;
}

//подпрограмма изменения полей отдельного человека
void edit_human(Human *h)
{
	std::string tmp;
	int i = 0;

	for (;;)
	{
		h->print();
		std::cout << HELP_HUMAN;
		std::cout << "> ";
		std::getline(std::cin, tmp);

		if (tmp.empty())
			return;
		try
		{
			i = std::stoi(tmp);
		}
		catch (const std::exception&)
		{
			std::cout << "Unexpected command" << std::endl;
		}
		
		switch (i)
		{
			case 1:{
				std::cout << "Name: "; std::getline(std::cin, tmp);
				h->set_name(tmp.c_str());
				break;
			}
			case 2: {
				std::cout << "Surname: "; std::getline(std::cin, tmp);
				h->set_surname(tmp.c_str());
				break;
			}
			case 3: {
				std::cout << "Sex: "; std::getline(std::cin, tmp);
				h->set_sex(tmp.c_str());
				break;
			}
			case 4: {
				std::cout << "Height: "; std::getline(std::cin, tmp);
				h->set_height(tmp.c_str());
				break;
			}
			case 5: {
				std::cout << "Weight: "; std::getline(std::cin, tmp);
				h->set_weight(tmp.c_str());
				break;
			}
			case 6: {
				std::cout << "Phone: "; std::getline(std::cin, tmp);
				h->set_phone(tmp.c_str());
				break;
			}
			case 7: {
				std::cout << "Adress: "; std::getline(std::cin, tmp);
				h->set_adress(tmp.c_str());
				break;
			}
			case 0: return;
		default:
			break;
		}
	}
}

//вспомогательная функция, если значение равно NULL возвращает строку "NULL"
const char * get_str(char * str)
{
	if (str == NULL)
		return "NULL";
	return str;
}

//сохранение в файл
void save(List * l, const char * file)
{
	std::ofstream f;
	f.open(file, std::ios::out);

	if (!f.is_open())
		throw std::runtime_error("Can't save file!");

	unsigned int length = l->length();

	Human * tmp = NULL;

	f << length << std::endl;

	for (unsigned int i = 0; i < length; i++)
	{
		tmp = (Human*)(l->get_n(i)->data);
		
		f << get_str(tmp->get_name()) << std::endl;
		f << get_str(tmp->get_surname()) << std::endl;
		f << get_str(tmp->get_sex()) << std::endl;
		f << get_str(tmp->get_height()) << std::endl;
		f << get_str(tmp->get_weight()) << std::endl;
		f << get_str(tmp->get_phone()) << std::endl;
		f << get_str(tmp->get_adress()) << std::endl;
	}

	f.close();
}

//загрузка из файла
List * load(const char * file)
{
	std::ifstream f;
	f.open(file, std::ios::in);

	if (!f.is_open())
		throw std::runtime_error("Can't read file");

	std::string tmp;
	std::getline(f, tmp);
	unsigned int length = std::stoi(tmp);

	List * l = new List();

	for (unsigned int i = 0; i < length; i++)
	{
		std::getline(f, tmp); Human * human = new Human(tmp.c_str());
		std::getline(f, tmp); human->set_surname(tmp.c_str());
		std::getline(f, tmp); human->set_sex(tmp.c_str());
		std::getline(f, tmp); human->set_height(tmp.c_str());
		std::getline(f, tmp); human->set_weight(tmp.c_str());
		std::getline(f, tmp); human->set_phone(tmp.c_str());
		std::getline(f, tmp); human->set_adress(tmp.c_str());
		l->push(human);
	}

	f.close();
	return l;
}

//подпрограмма редактирования списка
void edit_list(List *l)
{
	std::string tmp;
	int i = 0;
	List * fList = new List();

	for (;;)
	{
		print_list(l);
		std::cout << HELP_LIST;
		std::cout << "> ";
		std::getline(std::cin, tmp);

		if (tmp.empty())
			return;

		try
		{
			i = std::stoi(tmp);
		}
		catch (const std::exception&)
		{
			std::cout << "Unexpected command" << std::endl;
		}

		switch (i)
		{
		case 0: {
			return;
		}
		case 1: {
			//добавление нового элемента
			Human *h = input_human();
			l->push(h);
			break;
		}
		case 2: {
			//удаление
			std::cout << "n = ";
			std::getline(std::cin, tmp);
			if (tmp.empty())
			{
				l->delete_last();
				break;
			}

			try
			{
				i = std::stoi(tmp);
			}
			catch (const std::exception&)
			{
				std::cout << "Unexpected command" << std::endl;
			}

			if (i == 0)
				l->delete_first();
			else
				l->delete_n(i);
			break;
		}
		case 3:
		{
			//вставка
			Human * h = input_human();

			std::cout << "n = ";
			std::getline(std::cin, tmp);
			if (tmp.empty())
			{
				l->push(h);
				break;
			}

			try
			{
				i = std::stoi(tmp);
			}
			catch (const std::exception&)
			{
				std::cout << "Unexpected command" << std::endl;
			}

			l->insert(h, i);
			break;
		}
		case 4: {
			//редактирование
			std::cout << "n = ";
			std::getline(std::cin, tmp);
			if (tmp.empty())
				break;

			try
			{
				i = std::stoi(tmp);
			}
			catch (const std::exception&)
			{
				std::cout << "Unexpected command" << std::endl;
			}

			Node * n = l->get_n(i);
			Human *h = (Human*)n->data;
			edit_human(h);
			break;
		}
		case 5: {
			//сохранение
			std::cout << "> ";
			std::getline(std::cin, tmp);
			if (tmp.empty())
				break;

			try
			{
				save(l, tmp.c_str());
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what();
			}
			break;
		}
		case 6: {
			//загрузка
			std::cout << "> ";
			std::getline(std::cin, tmp);
			if (tmp.empty())
				break;

			try
			{
				List * _l = load(tmp.c_str());
				l = _l;
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what();
			}
			break;
		}
		case 7: {
			//поиск по фамилии
			std::cout << "> ";
			std::getline(std::cin, tmp);
			if (tmp.empty())
				break;

			Human* h = NULL;
			Node* n = NULL;
			unsigned int length = l->length();

			std::cout << "Finded by surname\"" << tmp << "\":" << std::endl;
			for (int i = 0; i < length; i++)
			{
				n = l->get_n(i);
				h = (Human*)n->data;
				if (strcmp(tmp.c_str(), h->get_surname()) == 0)
					h->print();
			}

			break;
		}
		case 8: {
			//фильтр по адресу
			std::cout << "> ";
			std::getline(std::cin, tmp);
			if (tmp.empty())
				break;

			Human* h = NULL;
			Node* n = NULL;
			unsigned int length = l->length();

			std::string op;
			std::cout << "Operator> ";
			std::getline(std::cin, op);

			std::cout << "Filtered by adress\"" << tmp << "\":" << std::endl;
			for (int i = 0; i < length; i++)
			{
				n = l->get_n(i);
				h = (Human*)n->data;
				if (strcmp(tmp.c_str(), h->get_surname()) == 0 && op.c_str()[0] == 'e')
				{
					h->print();
					fList->push(h);
				}

				if (strcmp(tmp.c_str(), h->get_surname()) < 0 && op.c_str()[0] == 'l')
				{
					h->print();
					fList->push(h);
				}

				if (strcmp(tmp.c_str(), h->get_surname()) > 0 && op.c_str()[0] == 'g')
				{
					h->print();
					fList->push(h);
				}

			}

			break;
		}
		default:
			break;
		}
	}
}

void test()
{
	Human * r_human = new Human("John", "Williams");
	r_human->set_sex("Male");
	r_human->set_height("180 cm.");
	r_human->set_weight("60 kg");
	r_human->set_phone("1 111 111 11 11");
	r_human->set_adress("Adress");

	List * r_list = new List();
	r_list->push(r_human);

	edit_list(r_list);

	delete r_human;
}

int main()
{
	test();
	
	std::system("pause");
	return 0;
}

