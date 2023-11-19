#include <iostream>
#include "MyLib.h"

int main()
{
	int input = 0;

	do
	{
		printf_s("Enter number : ");
		scanf_s("%u", &input);
		if (input == 0)
			break;
		printf_s("In bin code : %s\n", ToBinCode(input));
	} while (true);
}
