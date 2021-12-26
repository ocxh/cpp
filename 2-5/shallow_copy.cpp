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
	Person b=a; //default ���� ������ 
	a.ShowInfo(); 
	b.ShowInfo();
	
	return 0; //return�� a�� b�� name�� delete �Ǿ�� �ϴµ� a�� name�� delete��
			 //b�� name�� a�� name�� ����Ű�°��� �����̱� ����. ������ �� X 
}
