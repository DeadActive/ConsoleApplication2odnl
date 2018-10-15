#include "stdafx.h"
#include <string>
#include <iostream>
#include "Human.h"

//геттеры и сеттеры
char * Human::get_name() { return name; }
char * Human::get_surname() { return surname; }
char * Human::get_sex() { return sex; }
char * Human::get_height() { return height; }
char * Human::get_weight() { return weight; }
char * Human::get_phone() { return phone; }
char * Human::get_adress() { return adress; }
void Human::set_name(const char * str) { name = new char[strlen(str) + 1]; strcpy(name, str); }
void Human::set_surname(const char * str) { surname = new char[strlen(str) + 1]; strcpy(surname, str); }
void Human::set_sex(const char * str) { sex = new char[strlen(str) + 1]; strcpy(sex, str); }
void Human::set_height(const char * str) { height = new char[strlen(str) + 1]; strcpy(height, str); }
void Human::set_weight(const char * str) { weight = new char[strlen(str) + 1]; strcpy(weight, str); }
void Human::set_phone(const char * str) { phone = new char[strlen(str) + 1]; strcpy(phone, str); }
void Human::set_adress(const char * str) { adress = new char[strlen(str) + 1]; strcpy(adress, str); }

//вспомогательная функция, если значение равно NULL возвращает строку "NULL"
const char * get_string(char * str)
{
	if (str == NULL)
		return "NULL";
	return str;
}

//вывод в консоль
void Human::print()
{
	std::cout << "\t" << get_string(name) << "\t" << get_string(surname) << std::endl;
	std::cout << "========================================================" << std::endl;
	std::cout << "Sex:\t" << get_string(sex) << std::endl;
	std::cout << "Height:\t" << get_string(height) << std::endl;
	std::cout << "Weight:\t" << get_string(weight) << std::endl;
	std::cout << "Phone:\t" << get_string(phone) << std::endl;
	std::cout << "Adress:\t" << get_string(adress)<< std::endl << std::endl;
}

//минимальный конструктор
Human::Human() {};

//конструктор по имени
Human::Human(const char * _name)
{
	this->set_name(_name);
}

//конструктор по имени и фамилии
Human::Human(const char * _name, const char * _surname)
{
	this->set_name(_name);
	this->set_surname(_surname);
}

//деструктор
Human::~Human()
{
	free(name);
	free(surname);
	free(sex);
	free(height);
	free(weight);
	free(phone);
	free(adress);
}