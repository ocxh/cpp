#include<iostream>
using namespace std;

//�����ڸ� �̿��� Call-by-reference �Լ� 
void SwapRef(int &num1, int &num2){
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int main(){
	int n1=10, n2=20;
	SwapRef(n1, n2);
	
	cout<<"n1: "<<n1<<endl;
	cout<<"n2: "<<n2<<endl;
	
	return 0;
}
