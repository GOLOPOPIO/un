#include "UILib.cpp"
#include <Windows.h>

Console console;

int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);

	Vector_16_2_s size;
	UIBlock_s block;

	block.Pos.x = 0;
	block.Pos.y = 0;
	block.Size.x = 10;
	block.Size.y = 5;
	block.BorderChar = '#';
	block.SetColor(FOREGROUND_GREEN);

	size.setX(70);
	size.setY(70);
	
	console.__init__(size, L"Phone list");
	console.AddPipeLine(block.Draw(), 100);

	console.Update();

	getchar();

	return 0;
}
