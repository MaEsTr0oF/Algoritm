#include <iostream>
#include <conio.h>
#include <windows.h>
size_t k = 2;
size_t r = 0;
size_t q = 0;
size_t N_op = 0;
#define VAR 182
long long int f(int n)
{
	if (n >= k)
	{
		r++;
		return f(n - 1) + f(n - 1) + f(n - 2) + f(n - 2) + f(n - 2) + f(n - 2) + f(n - 2) + f(n - 2) + f(n - 2) + f(n - 2) + f(n - 2) + f(n - 2) + f(n - 2) + f(n - 2) + f(n - 2) + f(n - 2) + f(n - 2) + 18 * n * n + 32 * n + 130;
	}
	else
	{
		q++;
		return 11 + 32 * n;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "\n";
	int N, N_max;
	N_max = 17;
	long long t1, t2;
	for (N = 0; N <= N_max; ++N)
	{
		r = 0;
		q = 0;
		t1 = GetTickCount64();

		N_op = f(N);
		t2 = GetTickCount64();
		std::cout << " N = " << N << " r = " << r << " q = " << q << " r+q = " << (r + q);
		std::cout << " N_op = " << N_op << " T = " << t2 - t1 << "\n";
	}
	return 0;
}
