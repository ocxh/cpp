#include<iostream>
using namespace std;

void cbr(int &num1){
	num1 ++;
	num1 *= -1;
}

int main(){
	int n = 10;
	cbr(n);
	cout<<n<<endl;
} 
