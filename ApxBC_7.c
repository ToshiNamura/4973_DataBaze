// Организация хранения данных в файлах (массивы)
// Вариант: 7
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include <memory.h>

typedef float Type;
const size_t ElementCount = 128;
const size_t ElementSize = sizeof(Type);
Type* Buffer;
FILE* fPointer;
const char* FileName = "Resource.bin";
int InitBufferError = -2006;
int OpenFileError = -2008;

int lc_OpenFile(const char* mode)
{
	fPointer = fopen(FileName, mode);
	if (fPointer == NULL)
	{
		printf("[Error] Файл не был открыт.\n");
		return OpenFileError;
	}
	return NULL;
}

int lc_WriteFile()
{
	int Result = lc_OpenFile("wb");
	if (Result != NULL)
		return Result;
	else {
		fwrite(Buffer, ElementSize, ElementCount, fPointer);
		fclose(fPointer);
	}
	return Result;
}

int lc_ReadFile()
{
	int Result = lc_OpenFile("rb");
	if (Result != NULL)
		return Result;
	else {
		fread(Buffer, ElementSize, ElementCount, fPointer);
		fclose(fPointer);
	}
	return Result;
}

int main(
	int argc,
	const char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int CallResult = NULL;

	if ((Buffer = (Type*)malloc(ElementCount * ElementSize)) == NULL)
		return InitBufferError;
	for (int i = 0; i < ElementCount; i++)
		Buffer[i] = (rand() % 100) / (Type)100;
	
	CallResult = lc_WriteFile();
	if (CallResult != NULL)
	{
		printf("[Func] lc_WriteFile функция вернула ошибку!\n");
		return CallResult;
	}
	
	CallResult = lc_ReadFile();
	if (CallResult != NULL)
	{
		printf("[Func] lc_ReadFile функция вернула ошибку!\n");
		return CallResult;
	}
	else
		for (size_t i = 0; i < ElementCount; i++)
			printf("%.4f ", Buffer[i]);

	free(Buffer);
	return NULL;
}