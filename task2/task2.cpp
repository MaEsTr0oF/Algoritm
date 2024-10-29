#include <iostream>
int f(int n)
{
	int s = 0, x = 6, y = -5 for (int ii = 0; ii < 4 * n; ii++) s = s + 2 * ii;
	y += s;
	if (n < 2)
		return (s + x + y);
	s = s + x * f(n - 1) + f(n - 1) for (int j = 0; j < 15; j++) s = s + x * f(n - 2);
	for (int k = 0; k < 3 * n * n; k++)
		s = s * k;
	return s;
}
int main()
{
	int n;
	std::cin << n;

	return 0;
}