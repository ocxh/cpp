#include<iostream>
#include<cstring>
using std::cout;
using std::cin;
using std::endl;

void menu();
void make_account();
void input();
void output();
void all_account();

class Account
{
	private:
		char *name;
		int account_ID;
		int money;
	public:
		Account(char *name, int account_ID, int money):account_ID(account_ID), money(money)
		{
			this->name = new char[strlen(name)+1];
			strcpy(this->name, name);
		}
		Account(const Account& copy):account_ID(copy.account_ID), money(copy.money)
		{
			name = new char[strlen(copy.name)+1];
			strcpy(name, copy.name);
		}
		int GetAccountId()
		{
			return account_ID;
		}
		void input(int money)
		{
			this->money += money;
		}
		void output(int money)
		{
			this->money -= money;
		}
		
		void Account_Info()
		{
			cout<<"�̸�: "<<name<<endl;
			cout<<"���¹�ȣ: "<<account_ID<<endl;
			cout<<"�ܾ�: "<<money<<endl;
		}
		~Account()
		{
			delete []name;
		}
};

Account *account[100];
int user=0;

int main(){
	int option=0;
	while(true){
		menu();
		
		cout<<"����: ";
		cin>>option;
		
		switch(option)
		{
			case 1:
				make_account();
				break;
			case 2:
				input();
				break;
			case 3:
				output();
				break;
			case 4:
				all_account();
				break;
			case 5:
				cout<<endl;
				cout<<"[���α׷��� �����մϴ�]"<<endl;
				return 0;
			default:
				cout<<"[Error]�ùٸ� �Է� ���� �Է��ϼ���"<<endl;
		}
	}	
}

void menu(){
	cout<<endl<<"------Menu------"<<endl;
	cout<<"1. ���°���"<<endl;
	cout<<"2. �Ա�"<<endl;
	cout<<"3. ���"<<endl;
	cout<<"4. �������� ��ü ���"<<endl;
	cout<<"5. ���α׷� ����"<<endl;
}

void make_account()
{	
	char name[10];
	int account_ID;
	int money;
	
	cout<<endl<<"[���°���]"<<endl;
	cout<<"�̸�: ";
	cin>>name;
	cout<<"���¹�ȣ: ";
	cin>>account_ID;
	cout<<"�ܾ�: ";
	cin>>money;
	cout<<"[�����Ϸ�]"<<endl;
	
	account[user++] = new Account(name, account_ID, money);
}

void input()
{
	int account_ID;
	int money;
	
	cout<<endl<<"[��   ��]"<<endl;
	cout<<"���¹�ȣ: ";
	cin>>account_ID;
	cout<<"�Աݾ�: ";
	cin>>money;
	
	for(int i=0; i<user; i++){
		if(account[i]->GetAccountId() == account_ID)
		{
			account[i]->input(money);	
		 } 
	}
	cout<<"�Ա� �Ϸ�"<<endl;
}

void output()
{
	int account_ID;
	int money;
	
	cout<<endl<<"[��   ��]"<<endl;
	cout<<"���¹�ȣ: ";
	cin>>account_ID;
	cout<<"��ݾ�: ";
	cin>>money;
	
	for(int i=0; i<user; i++){
		if(account[i]->GetAccountId() == account_ID)
		{
			account[i]->output(money);	
		 } 
	}
	cout<<"��� �Ϸ�"<<endl;
}

void all_account()
{
	cout<<endl<<"[��ü ���� ���]"<<endl;
	for(int i=0; i<user; i++){
		account[i]->Account_Info();
		cout<<endl;
	}
}
