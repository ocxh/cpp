#include<iostream>
using namespace std;

class Calculator{
	private:
		int add_n;
		int min_n;
		int mul_n;
		int div_n;
	public:
		void Init();
		double Add(double a, double b);
		double Min(double a, double b);
		double Mul(double a, double b);
		double Div(double a, double b);
		void ShowOpCount();
};

int main(){
	Calculator cal;
	cal.Init();
	cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
	cout<<"3.5 / 1.7 = "<<cal.Div(3.5, 1.7)<<endl;
	cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<endl;
	cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<endl;
	cal.ShowOpCount();
	return 0;
}

void Calculator::Init()
{
	add_n = 0;
	min_n = 0;
	mul_n = 0;
	div_n = 0;
}

double Calculator::Add(double a, double b)
{
	add_n++;
	return a+b;
}

double Calculator::Min(double a, double b)
{
	min_n++;
	return a-b;
}

double Calculator::Mul(double a, double b)
{
	mul_n++;
	return a*b;
}

double Calculator::Div(double a, double b)
{
	div_n++;
	return a/b;
}

void Calculator::ShowOpCount()
{
	cout<<"µ¡¼À: "<<add_n<<" »¬¼À: "<<min_n<<" °ö¼À: "<<mul_n<<" ³ª´°¼À: "<<div_n<<endl; 
}
