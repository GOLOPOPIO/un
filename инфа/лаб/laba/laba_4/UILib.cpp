#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include "Slovani.h"

struct Vector_16_2_s
{
	unsigned short x;
	unsigned short y;

	Vector_16_2_s normalize()
	{
		Vector_16_2_s ret;
		short l = len();

		ret.x = x / l;
		ret.y = y / l;

		return ret;
	}

	unsigned short getX() { return x; }
	unsigned short getY() { return y; }
	void setX(unsigned short value) { x = value; }
	void setY(unsigned short value) { y = value; }

	unsigned short len(){ return sqrt((x * x) + (y * y)); }

	/*==============  STATIC  ==============*/

	static Vector_16_2_s sym(Vector_16_2_s a, Vector_16_2_s b)
	{
		Vector_16_2_s ret;

		ret.x = a.x + b.x;
		ret.y = a.y + b.y;

		return ret;
	}
	static Vector_16_2_s sub(Vector_16_2_s a, Vector_16_2_s b)
	{
		Vector_16_2_s ret;

		ret.x = a.x - b.x;
		ret.y = a.y - b.y;

		return ret;
	}
	static Vector_16_2_s inc(Vector_16_2_s a, int size)
	{
		Vector_16_2_s ret;

		ret.x = a.x * size;
		ret.y = a.y * size;

		return ret;
	}

};

struct FormatChar_s
{
	Vector_16_2_s Pos;
	char Me;
	short Color;
};

struct Content_s
{

};

struct UIBlock_s 
{
	Vector_16_2_s Pos;
	Vector_16_2_s Size;

	char BorderChar;
	short Color;

	Content_s Content;

	void SetColor(short color)
	{
		Color = color;
		//Color = Color << 4;
		//Color = Color & c;
	}

	FormatChar_s* Draw()
	{
		int length = Size.x * Size.y;
		FormatChar_s* buf = (FormatChar_s*)malloc(length);
		FormatChar_s test[100];

		FormatChar_s CHAR;
		CHAR.Color = Color;
		CHAR.Me = BorderChar;

		int a = 0, x = 0, y = 0, index;
		
		for (size_t i = 0; i < Size.x; i++)
		{
			for (size_t j = 0; j < Size.y; j++)
			{
				CHAR.Pos.x = x;
				CHAR.Pos.y = y;
				index = x + (Size.x * y);
				buf[index] = CHAR;
				//test[index] = CHAR;
				x += 1;
			}
			y += 1;
			x = 0;
		}

		return buf;
	}
};

struct Console
{
private:
	COORD cursorPos;
	HANDLE hConsole;
	FormatChar_s* FormatChar;
	Vector_16_2_s Size;

	FormatChar_s test[100];

	int pipeLine = 0;

	void SetCursor(int x, int y)
	{
		cursorPos.X = x;
		cursorPos.Y = y;
		SetConsoleCursorPosition(hConsole, cursorPos);
	}
	void PrintChar(int index)
	{
		FormatChar_s CHAR = FormatChar[index];
		SetConsoleTextAttribute(hConsole, CHAR.Color);
		SetCursor(CHAR.Pos.getX(), CHAR.Pos.getY());
		printf_s("%c", CHAR.Me);
	}

public:
	void Update()
	{
		for (size_t i = 0; i < pipeLine; i++)
			PrintChar(i);
		
		pipeLine = 0;
	}
	void AddPipeLine(FormatChar_s CHAR)
	{
		pipeLine++;

		FormatChar[pipeLine - 1] = CHAR;
	}
	void AddPipeLine(FormatChar_s* CHARS, int len)
	{
		FormatChar_s test[100];

		for (size_t i = 0; i < len; i++)
		{
			//test[pipeLine + i - 1] = CHARS[i - 1];
			FormatChar[pipeLine + i - 1] = CHARS[i - 1];
		}

		pipeLine += len;
	}
	void __init__(Vector_16_2_s size, const wchar_t* titel)
	{
		Size = size;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		FormatChar = (FormatChar_s*)malloc(Size.x * Size.y);

		cursorPos.X = 0;
		cursorPos.Y = 0;

		COORD bufSize = { Size.getX() + 1, Size.getY() + 1};
		SMALL_RECT windowSize = { 0, 0, Size.getX(), Size.getY() };
		SetConsoleTitle(titel);
		SetConsoleScreenBufferSize(hConsole, bufSize);
		SetConsoleWindowInfo(hConsole, true, &windowSize);
	}
};