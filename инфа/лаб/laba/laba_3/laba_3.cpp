#include <stdio.h>
#include <Windows.h>
#include "TranslateString.h"

const char*  int_max = "+2147483647";
const char*  int_min = "-2147483648";
const char* uint_max = " 4294967295";

int main()
{
#pragma region Объявление необходимых переменных

	// Для работы с консолью
	COORD pos;
	HANDLE hConsole;

	// Для работы программы
	char input[13];
	char count;
	char errorFlag;

	int inputNum;
	int numCount;
	char numType;

	char* filtrStr;
	char* tetra;

#pragma endregion

#pragma region Выделение памяти и инициализирование переменных

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = 0;
	pos.Y = 0;

	filtrStr = (char*)malloc(12);
	tetra = (char*)malloc(40);

	count = 0;
	errorFlag = 0;
	numCount = 0;
	numType = 0;
	
	inputNum = 0;

#pragma endregion

#pragma region Начальные настройки

	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
	COORD bufSize = { 120, 120 };
	SMALL_RECT windowSize = { 0, 0, 119, 119 };
	SetConsoleTitle(L"Ass Convertor 4000");
	SetConsoleScreenBufferSize(hConsole, bufSize);
	SetConsoleWindowInfo(hConsole, true, &windowSize);

#pragma endregion

	while (true)
	{
#pragma region Украшательства
		
		printf_s("---------------------------\n");
		printf_s("|Enter number:            |\n");
		printf_s("---------------------------");
		pos.X = 15;
		pos.Y = count + 1;
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
		SetConsoleCursorPosition(hConsole, pos); // перемещяем курсор в координаты
		
#pragma endregion

#pragma region Ввод данных

		for (size_t i = 0; i < 13; i++)
			input[i] = ' '; /* на всякий затираем массив пустыми символами 
			до этого могли появлятся проблеммы по типу программа выдавала ошибку когда ее быть не должно
			скорее всего это из-за того что считывая мы заполняем не весь массив а только часть и в оставшихся ячейках непонятные данные */
		fgets(input, sizeof(input), stdin); /* читаем строку из консоли
			fgets т.к. scanf_s не хочет считывать пустую строку из-за чего программа работает некоректно
			также из-за это массив входных данных не 11 символов а 13 */

		for (size_t i = 0; i < 12; i++)
		{
			// для коректного вывода в таблицу убираем символы окночания строки(так как он может стоять не там где нам нужно) и символ перееноса строки
			if (input[i] == '\0' || input[i] == '\n')
				input[i] = ' '; // fgets помимо прочего также считывает символ переноса строки и окончания наличие которых мешает нам коректно вывести это строку в таблицу

		}
		input[12] = '\0'; // последний символ символ переноса строки 

#pragma endregion

#pragma region Проверка на выход

		if (input[0] == 48 && input[1] == 32)// если первый символ '0' а последующий пустой значит мы ввели только 0, а по условию задачи это условие окончания 
		{
			pos.X = 0;
			pos.Y = count + 2;

			SetConsoleCursorPosition(hConsole, pos);
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
			
			printf_s("\nDosvidyli\n");

			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
			break;
		}

		count++;
		if (count > 100)
		{
			pos.X = 0;
			pos.Y = count + 2;

			SetConsoleCursorPosition(hConsole, pos);
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);

			printf_s("\npls stop\n");

			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
			break;
		}

#pragma endregion

#pragma region Подготовка данных к выводу

		filtrStr = StrToRight(Filter(input, errorFlag), 12); // фильтруем входную строку и выравниваем ее по правому краю

#pragma region Прверка на диапозон

		if (errorFlag != 1)
		{
			for (size_t i = 0; i < 11; i++)
				if (filtrStr[i] > 47 && filtrStr[i] < 58)
					numCount++;

			if (numCount == 11)
				errorFlag = 2;

			if (errorFlag != 2)
				switch (filtrStr[0])
				{
				case '+':
					if (0 != ChecStr(filtrStr, StrToCharArray(int_max, 11)))
						errorFlag = 2;
					break;
				case '-':
					if (0 != ChecStr(filtrStr, StrToCharArray(int_min, 11)))
						errorFlag = 2;
					break;
				default:
					if (0 != ChecStr(filtrStr, StrToCharArray(uint_max, 11)))
						errorFlag = 2;
					break;
				}
		}

#pragma endregion

		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		switch (errorFlag)
		{
		case 3:
		case 0:
			// преобразуем входную строку в число и переводим его в двоичный код разделенный на тетрады
			tetra = ToBinCode(atoll(filtrStr)); 
			break;
		case 1:
			tetra = StrToCharArray("   Empty string", 39);
			break;
		case 2:
			tetra = StrToCharArray("   So big", 39);
			break;
		}	

		if (errorFlag) // если фильтр обнаружил некоректые символы то окрышиваем строку таблицы в красный иначе она остается зеленной
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			errorFlag = 0;
		}

#pragma endregion

#pragma region Вывод одной строки таблицы

		// устанавливаем курсор в начало строки 
		pos.X = 0;
		pos.Y = count - 1;
		SetConsoleCursorPosition(hConsole, pos);

		// вывод 1 строку в таблицы
		printf_s("| %s |", ToString(count, 3));
		printf_s(" %s |", filtrStr);
		printf_s(" %s |", tetra);
		printf_s("%s |\n", StrToRight(input, 13));

		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);

#pragma endregion

		// устанавливаем координаты курсора
		pos.X = 0;
		pos.Y = count;
	}
}