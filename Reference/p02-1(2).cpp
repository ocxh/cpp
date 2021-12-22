#include<iostream>
using namespace std;

void SwapPointer(int *(&a), int *(&b)){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int num1=5, num2=10;
	int *ptr1=&num1, *ptr2=&num2;
	SwapPointer(ptr1, ptr2);
	cout<<*ptr1<<endl;
	cout<<*ptr2<<endl;
}
