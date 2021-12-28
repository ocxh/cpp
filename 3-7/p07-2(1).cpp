#include<iostream>
using namespace std;

class Rectangle
{
	private:
		int a1;
		int a2;
	public:
		Rectangle(int a, int b): a1(a), a2(b){}	
		void ShowAreaInfo()
		{
			cout<<"¸éÀû: "<<a1*a2<<endl;
		}
};

class Square: public Rectangle
{
	public:
		Square(int a, int b): Rectangle(a,b){}
		Square(int a): Rectangle(a,a){}
};

int main()
{
	Rectangle p1(3,4);
	p1.ShowAreaInfo();
	
	Square p2(3);
	p2.ShowAreaInfo();
}
