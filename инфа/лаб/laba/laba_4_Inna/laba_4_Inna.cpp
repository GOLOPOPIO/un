#include <iostream>
#include "PhoneStructFunc.h"
#include "PhoneStruct.cpp"

#define s (char*)

int main()
{
	PhRec_t rec = *(new PhRec_t);
	rec.__init__(s"name name name", 1234567890);

	char* str = (char*)malloc(52);
	str = rec.toString();

	getchar();
}
