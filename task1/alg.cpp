#include <iostream>
#include <cmath>
long long int count = 0; // Счётчик операций
int R(int n, int z, long &s)
{
	int i, j, k, m;
	count += 3;
	for (i = n / 2; i <= (5 * n); i += 2)
	{
		count += 2;
		if (i <= z)
		{
			count += 2;
			for (j = 1; j <= i; j *= 2)
			{
				count += 4;
				s = s + z * j;
			}
		}
		else
		{
			count += 2;
			for (k = 1; k <= n; k++)
			{
				count += 4;
				s = s + k % z;
			}
		}
	}
	return i;
}
void RR(void)
{
	int t, a = -1, b = -1;
	long S = 0;
	int n;
	std::cout << "n = ";
	std::cin >> n;
	count += 7;
	for (t = 1; t <= n; t += 4)
	{
		count += 6;
		if (R(5, n, S) > t * 15)
		{
			a = R(t, 2 * n, S) + R(30, 4 * n, S);
		}
		else
		{
			b = R(30, 4 * n, S);
			count += 4;
		}
	}
	std::cout << "\na = " << a << "   b = " << b;
	std::cout << "   S = " << S << "\n";
	count += 10;
	std::cout << "cnt prog: " << count << "\n";
	std::cout << "cnt teor: " << 523 * n + 3240;
}

int main()
{
	RR();
	/*int cnt = 17;
	for (int i = 1; i <= 5; ++i) {
		 cnt += 4;
		 for (int j = 0; j < log2(i);++j) {
			  cnt += 4;
		 }
	}
	cnt += 1;
	std::cout << cnt;*/
	return 0;
}
