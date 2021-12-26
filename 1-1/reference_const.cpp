#include<iostream>
using namespace std;

int add(const int &num1, const int &num2){
	return num1+num2;
}

int main(){
	//int &num1 = 10;  --> impossible
	//const &num1 = 10; --> possible(temporary variable)
	int res = add(1,10);
	cout<<res<<endl;
}
