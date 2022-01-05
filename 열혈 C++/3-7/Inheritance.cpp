#include<iostream>
#include<cstring>
using namespace std;

class Person
{
	private:
		int age;
		char name[50];
	public:
		Person(int age, char* name):age(age)
		{
			strcpy(this->name, name);
		}
		void WhatYourName() const
		{
			cout<<"My name is"<<name<<endl;
		}
		void HowOldAreYou() const
		{
			cout<<"I'm "<<age<<" years old"<<endl;
		}
};

class UnivStudent : public Person
{
	private:
		char major[50];
	public:
		UnivStudent(char * name, int age, char *major):Person(age,name)
		{
			strcpy(this->major, major);
		}
		void WhoAreYou() const
		{
			WhatYourName();
			HowOldAreYou();
			cout<<"My major is "<<major<<endl<<endl;
		}
};

int main()
{
	UnivStudent ustd1("Lee", 22, "Computer eng.");
	ustd1.WhoAreYou();
	
	UnivStudent ustd2("Yoon", 21, "Electronic eng.");
	ustd2.WhoAreYou();
	return 0;
}
