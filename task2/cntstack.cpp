#include <iostream>
#include <cmath>
#include <algorithm>

size_t cntStack = 1;
size_t maxCntStack = 1;

int f(int n)
{
	++cntStack;					  // выделяем для n
	int s = 0, x = 6, y = -5; // выделяем для s, x, y
	cntStack += 4;				  // для s, x, y
	maxCntStack = std::max(maxCntStack, cntStack);

	for (int ii = 0; ii < 4 * n; ii++)
	{
		s = s + 2 * ii;
		y += s;
	}
	cntStack--;
	if (n < 2)
	{
		cntStack -= 4; // Освобождение места для n, s, x, y
		return (s + x + y);
	}

	cntStack += 2; // выделяем для двух f(n-1)
	maxCntStack = std::max(maxCntStack, cntStack);
	s = s + x * f(n - 1) + f(n - 1);
	cntStack -= 2; // освобождаем место для двух f(n-1)

	cntStack++; // выделяем для j
	for (int j = 0; j < 15; j++)
	{
		cntStack++; // выделяем для f(n-2)
		maxCntStack = std::max(maxCntStack, cntStack);
		s = s + x * f(n - 2);
		cntStack--; // освобождаем место для f(n-2)
	}
	cntStack--; // освобождаем место для j

	cntStack++; // выделяем для k
	maxCntStack = std::max(maxCntStack, cntStack);
	for (int k = 0; k < 3 * n * n; k++)
	{
		s = s * k;
	}
	cntStack--; // освобождаем место для k

	cntStack -= 4; // освобождаем место для n, s, x, y (переход к следующему вызову)
	return s;
}

int main()
{
	int N, N_max;
	N_max = 16; // Укажите значение, чтобы время работы было порядка более 10^10 операций

	for (N = 1; N <= N_max; N++)
	{
		f(N); // Выполнение функции
		std::cout << "N = " << N << " cntStack = " << cntStack << "  MaxStack = " << maxCntStack << "\n";
		cntStack = 1;	  // Сброс счётчика размера стека
		maxCntStack = 1; // Сброс счётчика максимального размера стека
	}
	return 0;
}
