#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void Hanoi(int num, int x, int y)
{
	if (num > 1) Hanoi(num - 1, x, 6 - x - y);
	printf("%d %d\n", x, y);
	if (num > 1) Hanoi(num - 1, 6 - x - y, y);
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	printf("%.0f\n", pow(2, num)-1);
	Hanoi(num, 1, 3);
	return 0;
}