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
		NameCard(NameCard& copy) //'깊은 복사'생성자 
		{
			name = new char[strlen(copy.name)+1];
			strcpy(name, copy.name);
			
			comp = new char[strlen(copy.comp)+1];
			strcpy(comp, copy.comp);
			
			number = new char[strlen(copy.number)+1];
			strcpy(number, copy.number);
			
			position = copy.position;
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
	NameCard copy1=manClerk;
	NameCard manSENIOR("HONG", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2=manSENIOR;
	
	copy1.ShowNmaeCardInfo();
	copy2.ShowNmaeCardInfo();
	return 0;
}
