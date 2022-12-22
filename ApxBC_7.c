// Организация хранения данных в файлах (массивы)
// Вариант: 7
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include <time.h>
#include <memory.h>

FILE* FileEdit(const char* Name)
{
	FILE* Temp = fopen(Name, "wb");
	if (Temp == NULL)
		printf("[FileEdit] Ошибка открытия файла \n");
	return Temp;
}

FILE* FileOpened(const char* Name)
{
	FILE* Temp = fopen(Name, "rb");
	if (Temp == NULL)
		printf("[FileOpened] Ошибка открытия файла \n");
	return Temp;
}

FLOAT FlipingBits(FLOAT Number)
{
	
}

#define BufferSize 64

int main(
	int argc,
	const char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	srand((UINT)time(0));

	FLOAT* Buffer;
	FILE* fPointer;
	// Инициализация буфера
	if ((Buffer = (FLOAT*)malloc(BufferSize * sizeof(FLOAT))) == NULL)
		return -12;
	else
		for (size_t i = 0; i < BufferSize; i++)
			Buffer[i] = (FLOAT)(rand()) / (FLOAT)(RAND_MAX);
	// Открытие для чтения данных
	if ((fPointer = FileEdit("Resource.bin")) == NULL)
		return -27;
	else
	{
		fwrite(Buffer, sizeof(FLOAT), BufferSize, fPointer);
		fclose(fPointer);
	}
	// Открытие для чтения данных
	if ((fPointer = FileOpened("Resource.bin")) == NULL)
		return -57;
	else
	{
		fread(Buffer, sizeof(FLOAT), BufferSize, fPointer);
		printf("[Содержимое файла '%s']\n", "Resource.bin");
		for (size_t i = 0; i < BufferSize; i++)
			printf("[HEX: %x] = %f\n", *(UINT*)&(Buffer[i]), Buffer[i]);
		fclose(fPointer);
	}

	free(Buffer);
	return 0;
}