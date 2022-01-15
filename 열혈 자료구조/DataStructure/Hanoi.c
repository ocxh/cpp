void Hanoi(int num, int x, int y)
{
	if (num > 1) Hanoi(num - 1, x, 6 - x - y);
	printf("%d %d\n", x, y);
	if (num > 1) Hanoi(num - 1, 6 - x - y, y);
}