// Организация хранения данных в файлах (массивы)
// Вариант: 7
// Zadanir: 1
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

int main(
	int argc,
	const char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE* f_out = NULL;
	char* f_name = (char*)malloc(255);
	printf("[Введите 0 для выхода из программы]\n");
	printf("[Начальные данные]\n");
	printf("[Указатель файла записи] адрес: %p, значение: %p;\n", &f_out, f_out);
	printf("[Буффер имени файла] адрес: %p, значение: %p;\n", &f_name, f_name);
	do {
		printf("[Введите название файла]: ");
		scanf("%s", f_name);
		if (*f_name == '0')
			break;
		f_out = fopen(f_name, "wb");
		{
			int N = 0;
			float* Buff;
			printf("[Введите длину массива]: ");
			scanf("%d", &N);
			fwrite(&N, sizeof(int), 1, f_out);
			Buff = (float*)malloc(sizeof(float) * N);
			printf("[Введите элементы через пробел]: ");
			for (int i = 0; i < N; i++)
				scanf("%f", (Buff + i));
			fwrite(Buff, sizeof(float), N, f_out);
			printf("[Массив]:");
			for (int i = 0; i < N; i++)
				printf(" %.2f", Buff[i]);
			printf(";\n");
			printf("[HEX]:");
			for (int i = 0; i < N; i++)
				printf(" %X", *((unsigned int*)(Buff + i)));
			printf(";\n");
			free(Buff);
		}
		printf("[Результируюшие данные]\n");
		printf("[Указатель файла записи] адрес: %p, значение: %p;\n", &f_out, f_out);
		printf("[Буффер имени файла] адрес: %p, значение: %p;\n", &f_name, f_name);
		fclose(f_out);
	} while (1);
	free(f_name);
	return 0;
}