#include <malloc.h>
#include "PhoneStructFunc.h"

char* strcopy(char a[], char b[])
{
	int i = 0;

	while (b[i] != 0)
	{
		a[i] = b[i];
		i++;
	}

	a[i] = 0;

	return a;
}
char* strAddChar(char a[], char b)
{
	int i = 0;

	while (a[i] != 0)
		i++;

	a[i] = b;
	a[++i] = 0;

	return a;
}
char* charAddStr(char a, char b[], int len)
{
	int i = 1;

	char* ret = (char*)malloc(len + 1);
	ret[0] = a;
	ret[len] = 0;

	while (b[i - 1] != '\0')
		ret[i++] = b[i - 1];

	return ret;

}
char* ToString(long long num, int len)
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
char* strAddStr(char a[], char b[])
{
	char* ret = (char*)malloc((sizeof a) + (sizeof b) - 1);
	ret[(sizeof a) + (sizeof b) - 1] = 0;
	int i = 0, j = 0;

	while (a[i] != 0)
		ret[j++] = a[i++];

	i = 0;

	while (b[i] != 0)
		ret[j++] = b[i++];

	return ret;
}