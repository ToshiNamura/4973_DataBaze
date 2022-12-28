// Organization of data storage in files (lists of strings)
// Variant: 7
// Zadanir: 2
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
	FILE* f_in = NULL, * f_out = NULL;
	char* strbuf = NULL, *f_name = (char*)malloc(255);
	printf("[Введите 0 для выхода из программы]\n");
	printf("[Начальные данные]\n");
	printf("[Указатель файла чтения] адрес: %p, значение: %p;\n", &f_in, f_in);
	printf("[Указатель файла записи] адрес: %p, значение: %p;\n", &f_out, f_out);
	printf("[Буффер чтения/запяси] адрес: %p, значение: %p;\n", &strbuf, strbuf);
	printf("[Буффер имени файла] адрес: %p, значение: %p;\n", &f_name, f_name);
	do {
		printf("[Введите название файла]: ");
		scanf("%s", f_name);
		if (*f_name == '0')
			break;
		f_in = fopen(f_name, "rt");
		if (f_in == NULL) {
			printf("Ошибка открытия файла\n");
			continue;
		}
		f_out = fopen("outdat.txt", "wt");
		{
			strbuf = (char*)malloc(255);
			while (fgets(strbuf, 254, f_in))
			{
				printf("[Содержимое]: %s", strbuf);
				int i = 0;
				while (strbuf[i])
				{
					if (!((strbuf[i] >= '!' &&
						strbuf[i] <= '/') ||
						(strbuf[i] >= ':' &&
						strbuf[i] <= '@')))
						fprintf(f_out, "%c", strbuf[i]);
					i++;
				}
			}
			free(strbuf);
			printf("\n");
		}
		printf("[Результируюшие данные]\n");
		printf("[Указатель файла чтения] адрес: %p, значение: %p;\n", &f_in, f_in);
		printf("[Указатель файла записи] адрес: %p, значение: %p;\n", &f_out, f_out);
		printf("[Буффер чтения/запяси] адрес: %p, значение: %p;\n", &strbuf, strbuf);
		printf("[Буффер имени файла] адрес: %p, значение: %p;\n", &f_name, f_name);
		fclose(f_in);
		fclose(f_out);
	} while (1);
	free(f_name);
	return 0;
}