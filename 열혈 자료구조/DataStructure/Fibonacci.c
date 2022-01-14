int Fibonacci(int cnt)
{
	if (cnt == 1) return 0;
	else if (cnt == 2) return 1;
	else return Fibonacci(cnt - 1) + Fibonacci(cnt - 2);
}