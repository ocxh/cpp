#include<iostream>
#include<cstring>
using namespace std;

class MyFriendInfo
{
	private:
		char * name;
		int age;
	public:
		MyFriendInfo(char *name, int age):age(age)
		{
			this->name = new char[strlen(name)];
			strcpy(this->name, name);
		}
		void ShowMyFriendInfo()
		{
			cout<<"이름: "<<name<<endl;
			cout<<"나이: "<<age<<endl;
		}
		~MyFriendInfo()
		{
			cout<<"MyFriendInfo delete"<<endl;
			delete []name;
		}
};

class MyFriendDetailInfo: public MyFriendInfo
{
	private:
		char *addr;
		char *phone;
	public:
		MyFriendDetailInfo(char *name, int age, char *addr, char *phone): MyFriendInfo(name,age)
		{
			this->addr = new char[strlen(addr)];
			strcpy(this->addr, addr);
			this->phone = new char[strlen(phone)];
			strcpy(this->phone, phone);
		}
		void ShowMyFriendDetailInfo()
		{
			ShowMyFriendInfo();
			cout<<"주소: "<<addr<<endl;
			cout<<"전화: "<<phone<<endl<<endl; 
		}
		~MyFriendDetailInfo()
		{
			cout<<"MyFriendDetailInfo delete"<<endl;
			delete []addr;
			delete []phone;
		}
};

int main()
{
	MyFriendDetailInfo a("Kim",22,"Seoul","010-0000-0000");
	a.ShowMyFriendDetailInfo();
	
	return 0;
}
