#include<iostream>
#include<cstring>
using namespace std;

class Printer{
	private:
		char message[20];
	public:
		void SetString(char *m);
		void ShowString();
};

int main()
{
	Printer pnt;
	pnt.SetString("Hello World!");
	pnt.ShowString();
	pnt.SetString("I love C++");
	pnt.ShowString();
}

void Printer::SetString(char *m)
{
	strcpy(message, m);
}
void Printer::ShowString()
{
	cout<<message<<endl;
}
