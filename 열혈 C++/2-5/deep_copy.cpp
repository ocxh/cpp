#include<iostream>
#include<cstring>
using namespace std;

class Person
{
	private:
		char *name;
		int age;
	public:
		Person(char *name, int age):age(age)
		{
			this->name = new char[strlen(name)+1];
			strcpy(this->name, name);
		}
		Person(const Person& copy):age(copy.age) //깊은 복사 생성자 
		{
			name = new char[strlen(copy.name)+1];
			strcpy(name, copy.name);
		}
		void ShowInfo()
		{
			cout<<"이름: "<<name<<endl;
			cout<<"나이: "<<age<<endl; 
		}
		~Person()
		{
			delete []name;
			cout<<"Boom!"<<endl;
		}
};

int main()
{
	Person a("kim", 22);
	Person b=a; //깊은 복사 생성자 
	a.ShowInfo();
	b.ShowInfo();
	
	return 0; //a의 name과 b의 name은 다른 값이기에 "Boom!"이 2번 출력됨 
}
