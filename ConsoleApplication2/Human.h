#pragma once

class Human
{
public:
	//������������
	Human();
	Human(const char * name);
	Human(const char * name, const char * surname);
	//����������
	~Human();
	//������� � ��������
	char * get_name();
	char * get_surname();
	char * get_sex();
	char * get_height();
	char * get_weight();
	char * get_phone();
	char * get_adress();
	void set_name(const char * str);
	void set_surname(const char * str);
	void set_sex(const char * str);
	void set_height(const char * str);
	void set_weight(const char * str);
	void set_phone(const char * str);
	void set_adress(const char * str);
	void print();

private:
	//�������, ���, ���, ����, ���, ���� ��������, �������, �����
	char * surname;
	char * name;
	char * sex;
	char * height;
	char * weight;
	char * birthday;
	char * phone;
	char * adress;
};