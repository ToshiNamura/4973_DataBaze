// Approximate calculation of the area of the figure by the Monte Carlo method
// Variant: 21
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int f(double x, double y)
{
	if ((x*x + y*y <= 4) &&
		(-(x*x) + 2 <= y))
		return 1;
	else
		return 0;
}

int main(
	int argc,
	const char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double Si = 3.14;
	double Sq = 4.0;
	do
	{
		int c;
		printf("[Введите количество точек]: ");
		scanf("%d", &c);
		if (c == 0)
			break;
		srand(time(0));
		int p_in = 0;
		printf("[Логи точек]:\n");
		for (int i = 0; i < c; i++)
		{
			double x = -10.0 + (double)(rand()) / (double)(RAND_MAX / 20.0);
			double y = -10.0 + (double)(rand()) / (double)(RAND_MAX / 20.0);
			printf("(%.2f,%.2f:%d)", x, y, f(x, y));
			p_in += f(x, y);
		}
		double S = (double)p_in / (double)c * Sq;
		printf("\n[Всего брошено точек]: %d\n", c);
		printf("[Попаданий]: %d\n", p_in);
		printf("[Не попали в фигуру]: %d\n", c - p_in);
		printf("[значение: Si]: %lf\n", Si);
		printf("[значение: S]: %lf\n", S);
		printf("[значение: (S - Si)]: %lf\n", fabs(S - Si));
	} while (1);
	getchar();
	getchar();
	return 0;
}