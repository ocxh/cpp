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
	Person b=a; //default 복사 생성자 
	a.ShowInfo(); 
	b.ShowInfo();
	
	return 0; //return시 a와 b의 name이 delete 되어야 하는데 a의 name만 delete됨
			 //b의 name은 a의 name을 가르키는것이 전부이기 때문. 고유한 값 X 
}
