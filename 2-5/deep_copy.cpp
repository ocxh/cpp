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
		Person(const Person& copy):age(copy.age) //���� ���� ������ 
		{
			name = new char[strlen(copy.name)+1];
			strcpy(name, copy.name);
		}
		void ShowInfo()
		{
			cout<<"�̸�: "<<name<<endl;
			cout<<"����: "<<age<<endl; 
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
	Person b=a; //���� ���� ������ 
	a.ShowInfo();
	b.ShowInfo();
	
	return 0; //a�� name�� b�� name�� �ٸ� ���̱⿡ "Boom!"�� 2�� ��µ� 
}
