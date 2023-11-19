#include <iostream>
#include "PhoneStructFunc.h"

struct PhNum_s
{
	long long number : 40;
	char plus : 1;

	void __init__(char _plus, long long _number)
	{
		number = _number;
		plus = _plus;
	}
	void __init__(long long _number) { __init__(0, _number); }
	void __init__() { __init__(0, INT_MAX); }

	char* toString()
	{
		char* ret = (char*)malloc(12);// +1234567890
		
		ret = charAddStr((plus ? '+' : ' '), ToString(number, 10), (sizeof ret));
		ret[11] = '\0';

		return ret;
	}
};

struct PhRec_t
{
	char name[40];
	PhNum_s phNum;

	void __init__(char* _name, PhNum_s _number)
	{
		strcopy(name, _name);
		phNum = _number;
	}
	void __init__(char* _name, long long _number, char _plus)
	{
		strcopy(name, _name);
		phNum.__init__(_plus, _number);
	}
	void __init__(char* _name, long long _number){ __init__(_name, _number, 0); }

	char* toString()
	{
		char* ret = (char*)malloc(52);
		int i = 0;

		while (name[i] != 0)
			ret[i] = name[i++];

		ret[i] = '\n';
		ret[i + 1] = '\0';

		ret = strAddStr(ret, phNum.toString());

		return ret;
	}
};

