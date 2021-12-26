#include<iostream>
#include<cstring>
using namespace std;

namespace COMP_POS
{
	enum{CLERK, SENIOR, ASSIST, MANAGER};
	
	void ShowPos(int pos)
	{
		switch (pos){
			case CLERK:
				cout<<"사원"<<endl;
				break;
			case SENIOR:
				cout<<"주임"<<endl;
				break;
			case ASSIST:
				cout<<"대리"<<endl;
				break;
			case MANAGER:
				cout<<"과장"<<endl;
				break;
			default:
				break;
		}
	}
}

class NameCard
{
	private:
		char *name;
		char *comp;
		char* number;
		int position;
	public:
		NameCard(char * name, char * comp, char* number,int pos):position(pos)
		{
			this->name = new char[strlen(name)+1];
			this->comp = new char[strlen(comp)+1];
			this->number = new char[strlen(number)+1];
			
			strcpy(this->name, name);
			strcpy(this->comp, comp);
			strcpy(this->number, number);
		}
		void ShowNmaeCardInfo()
		{
			cout<<"이름: "<<name<<endl;
			cout<<"회사이름: "<<comp<<endl;
			cout<<"전화번호: "<<number<<endl;
			cout<<"직급: "; COMP_POS::ShowPos(position); cout<<endl;
		}
		~NameCard()
		{
			delete []name;
			delete []comp;
			delete []number;
		}
};

int main(){
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("HONG", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNmaeCardInfo();
	manSENIOR.ShowNmaeCardInfo();
	manAssist.ShowNmaeCardInfo();
}
