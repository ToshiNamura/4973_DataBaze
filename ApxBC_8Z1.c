// Organization of data storage in files (lists of strings)
// Variant: 7
// Zadanir: 1
#include <Windows.h>
#include <stdlib.h> 
#include <stdio.h>
#include <memory.h>

char* getline(void) {
	char* line = malloc(250), * linep = line;
	size_t lenmax = 250, len = lenmax;
	int c;

	if (line == NULL)
		return NULL;

	for (;;) {
		c = fgetc(stdin);
		if (c == EOF)
			break;

		if (--len == 0) {
			len = lenmax;
			char* linen = realloc(linep, lenmax *= 2);

			if (linen == NULL) {
				free(linep);
				return NULL;
			}
			line = linen + (line - linep);
			linep = linen;
		}

		if ((*line++ = c) == '\n')
			break;
	}
	*line = '\0';
	return linep;
}

int main(
	int argc,
	const char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE* f_out = NULL;
	char* strbuf = NULL;
	int nstr = 0;
	printf("[Введите 0 для выхода из программы]\n");
	printf("[Начальные данные]\n");
	printf("[Указатель файла записи] адрес: %p, значение: %p;\n", &f_out, f_out);
	printf("[Буффер чтения/запяси] адрес: %p, значение: %p;\n", &strbuf, strbuf);
	do {
		do {
			printf("[Введите количество строк]: ");
			scanf("%d", &nstr);
			if (nstr == 0)
				exit(0);
			if (nstr < 0)
				printf("[Не верный ввод числа]\n");
			else
				break;
		} while (1);
		f_out = fopen("outdat.txt", "wt");
		{
			getchar();
			for (int i = 0; i < nstr; i++)
			{
				printf("[%d] ", i);
				strbuf = getline();
				int j = 0;
				while (strbuf[j])
				{
					if (!((strbuf[j] >= '!' &&
						strbuf[j] <= '/') ||
						(strbuf[j] >= ':' &&
						strbuf[j] <= '@')))
						fprintf(f_out, "%c", strbuf[j]);
					j++;
				}
			}
			free(strbuf);
		}
		printf("[Результируюшие данные]\n");
		printf("[Указатель файла записи] адрес: %p, значение: %p;\n", &f_out, f_out);
		printf("[Буффер чтения/запяси] адрес: %p, значение: %p;\n", &strbuf, strbuf);
		fclose(f_out);
	} while (1);
	return 0;
}