// Организация хранения данных в файлах (массивы)
// Вариант: 7
// Zadanir: 2
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

float Reverse(float var)
{
	unsigned int tmp = *((unsigned int*)(&var));
	unsigned int N = (sizeof(float) * 8);
	unsigned int t = 0;
	unsigned int ret = 0;
	for (unsigned int i = 0; i < N / 2; ++i) {
		t |= (tmp & (1 << i)) << (N - i - 1);
		ret |= ((tmp & (1 << (N - i - 1))) >> (N - i - 1)) << i;
		ret |= t;
	}
	return *((float*)(&ret));
}

int main(
	int argc,
	const char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE* f_in = NULL;
	char* f_name = (char*)malloc(255);
	printf("[Введите 0 для выхода из программы]\n");
	printf("[Начальные данные]\n");
	printf("[Указатель файла чтения] адрес: %p, значение: %p;\n", &f_in, f_in);
	printf("[Буффер имени файла] адрес: %p, значение: %p;\n", &f_name, f_name);
	do {
		printf("[Введите название файла]: ");
		scanf("%s", f_name);
		if (*f_name == '0')
			break;
		f_in = fopen(f_name, "rb");
		{
			int N = 0;
			fread(&N, sizeof(int), 1, f_in);
			float* Buff = (float*)malloc(sizeof(float) * N);
			fread(Buff, sizeof(float), N, f_in);
			printf("[Массив]:");
			for (int i = 0; i < N; i++)
				printf(" %.2f", Buff[i]);
			printf(";\n");
			printf("[HEX]:");
			for (int i = 0; i < N; i++)
				printf(" %X", *((unsigned int*)(Buff + i)));
			printf(";\n");
			printf("[Работа над данными]\n");
			for (int i = 0; i < N; i++)
				Buff[i] = Reverse(Buff[i]);
			printf("[Массив]:");
			for (int i = 0; i < N; i++)
				printf(" %.2f", Buff[i]);
			printf(";\n");
			printf("[HEX]:");
			for (int i = 0; i < N; i++)
				printf(" %X", *((unsigned int*)(Buff + i)));
			printf(";\n");
			printf("[Введите файл rev]: ");
			scanf("%s", f_name);
			if (*f_name == '0')
				break;
			FILE* f_out = fopen(f_name, "wb");
			fwrite(Buff, sizeof(float), N, f_out);
			fclose(f_out);
			free(Buff);
		}
		printf("[Результируюшие данные]\n");
		printf("[Указатель файла чтения] адрес: %p, значение: %p;\n", &f_in, f_in);
		printf("[Буффер имени файла] адрес: %p, значение: %p;\n", &f_name, f_name);
		fclose(f_in);
	} while (1);
	free(f_name);
	return 0;
}