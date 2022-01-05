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
			cout<<"이름: "<<name<<endl;
			cout<<"계좌번호: "<<account_ID<<endl;
			cout<<"잔액: "<<money<<endl;
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
		
		cout<<"선택: ";
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
				cout<<"[프로그램을 종료합니다]"<<endl;
				return 0;
			default:
				cout<<"[Error]올바른 입력 값을 입력하세요"<<endl;
		}
	}	
}

void menu(){
	cout<<endl<<"------Menu------"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입금"<<endl;
	cout<<"3. 출금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
}

void make_account()
{	
	char name[10];
	int account_ID;
	int money;
	
	cout<<endl<<"[계좌개설]"<<endl;
	cout<<"이름: ";
	cin>>name;
	cout<<"계좌번호: ";
	cin>>account_ID;
	cout<<"잔액: ";
	cin>>money;
	cout<<"[개설완료]"<<endl;
	
	account[user++] = new Account(name, account_ID, money);
}

void input()
{
	int account_ID;
	int money;
	
	cout<<endl<<"[입   금]"<<endl;
	cout<<"계좌번호: ";
	cin>>account_ID;
	cout<<"입금액: ";
	cin>>money;
	
	for(int i=0; i<user; i++){
		if(account[i]->GetAccountId() == account_ID)
		{
			account[i]->input(money);	
		 } 
	}
	cout<<"입금 완료"<<endl;
}

void output()
{
	int account_ID;
	int money;
	
	cout<<endl<<"[출   금]"<<endl;
	cout<<"계좌번호: ";
	cin>>account_ID;
	cout<<"출금액: ";
	cin>>money;
	
	for(int i=0; i<user; i++){
		if(account[i]->GetAccountId() == account_ID)
		{
			account[i]->output(money);	
		 } 
	}
	cout<<"출금 완료"<<endl;
}

void all_account()
{
	cout<<endl<<"[전체 계좌 목록]"<<endl;
	for(int i=0; i<user; i++){
		account[i]->Account_Info();
		cout<<endl;
	}
}
