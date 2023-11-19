#include <stdio.h>
#include <stdlib.h>
#include "TranslateString.h"

char ChecStr(char* one, char* two)
{
	for (int i = 0; i < 11; i++)
	{
		if (one[i] > two[i])
			return 1;
		else if (one[i] < two[i])
			return 0;
	}
	return 0;
}
char* StrToCharArray(const char* str, int len)
{
	char* buf;
	buf = (char*)malloc(len + 1);
	char f = 0;

	for (int i = 0; i < len; i++)
	{
		char a = str[i];
		buf[i] = ' ';
		if (str[i] == '\0' && f != 1) {
			f = 1;
			continue;
		}
			
		if(!f)
			buf[i] = str[i];
	}
		
	buf[len] = '\0';

	return buf;
}
char* Filter(char* src, char& errFlag)
{
	char i = 0, j = 0;
	char* buf;
	buf = (char*)malloc(12);
	buf[11] = '\0';

	if (src[0] == '+' || src[0] == '-')
	{
		buf[j] = src[i];
		i++;
		j++;
	}

	for (;i < 11; i++)
	{
		buf[i] = ' ';
		char f = src[i];
		if (!(src[i] > 47 && src[i] < 58)) 
		{
			if (src[i] != ' ' && src[i] != '\0' && src[i] != '\n' && src[i] != -2)
				errFlag = 3;
			continue;
		}

		buf[j] = src[i];
		j++;
	}

	if (j == 0)
		errFlag = 1;
	
	return buf;
}
char* ToBinCode(unsigned int num)
{
	char* str;
	str = (char*)malloc(40);
	str[39] = '\0';

	for (
		char i = 1, j = 0; 
		i < 40; i++) // в объ€влении цикла объ€вл€ем переменные i и j типа char (чтоб они меньше места занимали)
	{
		if (i % 5 == 0 && i != 0)
		{
			str[39 - i] = ' ';
			continue;
		}

		str[39 - i] = '0' + ((num >> j) & 1);
		j++;
	}

	return str;
}
char* StrToRight(char* src, int size)
{
	char* buf;
	buf = (char*)malloc(size);
	buf[size - 1] = '\0';

	char i = 0, j = 0;
	for (; i < size - 1; i++)
	{
		if (src[size - i - 2] != ' ')
		{
			buf[size - j - 2] = src[size - i - 2];
			j++;
		}
	}
	for (; j < size - 1; j++)
	{
		buf[size - j - 2] = ' ';
	}

	return buf;
}
char* ToString(int num, int len)
{
	char* str;
	str = (char*)malloc(len + 1);
	str[len] = '\0';

	for (int i = len - 1; i > -1; i--)
	{
		if (num == 0)
		{
			str[i] = ' ';
			continue;
		}
		str[i] = '0' + (num % 10);
		num /= 10;
	}
	return str;
}
