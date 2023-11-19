#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

char* getByteCode1(int);

int main()
{
	int num = 0;
	char input[256];

	printf("%d", INT_MAX);

	getchar();

	while (true)
	{
		fgets(input, sizeof(input), stdin);
		if (sscanf_s(input, "%d", &num) != 1 || num < 0)
		{
			printf("error\n");	
			continue;
		}
		
		printf("%s", getByteCode1(num));
		printf("%d", INT_MAX);
		printf("\n");
	}
}

char* getByteCode1(int num) 
{
	int size = sizeof(num) * 8 + 3;
	char* byte = (char*)malloc((sizeof(num) * 8) + 3);

	byte[0] = '0';
	byte[1] = 'b';
	byte[size - 1] = '\0';
	
	for (int i = size - 2; i >= 2; i--)
	{
		byte[i] = '0' + (num % 2); 
		num /= 2;
	}

	return byte;
}