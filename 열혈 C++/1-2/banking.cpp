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

typedef struct
{
	char name[10];
	int account_ID;
	int money;
} Account;

Account account[100];
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
	
	strcpy(account[user].name, name);
	account[user].account_ID = account_ID;
	account[user].money = money;
	user ++;	
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
		if(account[i].account_ID == account_ID)
		{
			account[i].money += money;	
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
		if(account[i].account_ID == account_ID)
		{
			account[i].money -= money;	
		 } 
	}
	cout<<"��� �Ϸ�"<<endl;
}

void all_account()
{
	cout<<endl<<"[��ü ���� ���]"<<endl;
	for(int i=0; i<user; i++){
		cout<<"�̸�: "<<account[i].name<<endl;
		cout<<"����ID: "<<account[i].account_ID<<endl;
		cout<<"�ܾ�: "<<account[i].money<<endl;
		cout<<endl;
	}
}
