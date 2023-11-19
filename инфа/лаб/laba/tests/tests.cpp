#define print printf_s
#define read scanf_s
#define wait getchar

#include <iostream>

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

	char* ret = (char*)malloc(len);
	ret[0] = a;

	while (b[i] != 0)
		ret[i++] = b[i - 2];

	return ret;

}

int main()
{
	char name[40];
	char n[] = "test test test test test test test test";
	strcopy(name, n);
	wait();
}
