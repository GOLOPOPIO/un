#include <corecrt_malloc.h>
#include "MyLib.h"


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