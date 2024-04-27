#include <windows.h>
#include <stdio.h>

int main() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


	SetConsoleTextAttribute(hConsole, 4);
	printf("    ■■■■       ■■■■■\n");
	printf("  ■■■■■■   ■■■■■■■\n");
	printf("  ■■■■■■   ■■■■ ■■■ \n");
	printf("   ■■  ■■■   ■■■   ■■\n");
	printf("        ■■■■■■■■■■■\n");


	SetConsoleTextAttribute(hConsole, 4);
	printf("      ■■");
	SetConsoleTextAttribute(hConsole, 15);
	printf("■■■■■■■■");
	SetConsoleTextAttribute(hConsole, 4);
	printf("■■\n");


	SetConsoleTextAttribute(hConsole, 4);
	printf("    ■■");
	SetConsoleTextAttribute(hConsole, 15);
	printf("■■■■■■■■■■");
	SetConsoleTextAttribute(hConsole, 4);
	printf("■■\n");
	

	SetConsoleTextAttribute(hConsole, 4);
	printf("    ■■");
	SetConsoleTextAttribute(hConsole, 15);
	printf("■■");
	SetConsoleTextAttribute(hConsole, 0);
	printf("■");
	SetConsoleTextAttribute(hConsole, 15);
	printf("■■■■");
	SetConsoleTextAttribute(hConsole, 0);
	printf("■");
	SetConsoleTextAttribute(hConsole, 15);
	printf("■■");
	SetConsoleTextAttribute(hConsole, 4);
	printf("■■\n");


	SetConsoleTextAttribute(hConsole, 4);
	printf("    ■■");
	SetConsoleTextAttribute(hConsole, 15);
	printf("■■");
	SetConsoleTextAttribute(hConsole, 0);
	printf("■");
	SetConsoleTextAttribute(hConsole, 15);
	printf("■");
	SetConsoleTextAttribute(hConsole, 6);
	printf("■■");
	SetConsoleTextAttribute(hConsole, 15);
	printf("■");
	SetConsoleTextAttribute(hConsole, 0);
	printf("■");
	SetConsoleTextAttribute(hConsole, 15);
	printf("■■");
	SetConsoleTextAttribute(hConsole, 4);
	printf("■■\n");


	SetConsoleTextAttribute(hConsole, 4);
	printf("      ■");
	SetConsoleTextAttribute(hConsole, 15);
	printf("■");
	SetConsoleTextAttribute(hConsole, 12);
	printf("■");
	SetConsoleTextAttribute(hConsole, 15);
	printf("■■■■■■");
	SetConsoleTextAttribute(hConsole, 12);
	printf("■");
	SetConsoleTextAttribute(hConsole, 15);
	printf("■");
	SetConsoleTextAttribute(hConsole, 4);
	printf("■\n");


	SetConsoleTextAttribute(hConsole, 4);
	printf("        ■■■■■■■■■■");
	

	/*검은색(Black) : 0
		파란색(Blue) : 1
		초록색(Green) : 2
		청록색(Cyan) : 3
		빨간색(Red) : 4
		자주색(Magenta) : 5
		노란색(Yellow) : 6
		회색(Gray) : 7
		밝은 회색(Light Gray) : 8
		밝은 파란색(Light Blue) : 9
		밝은 초록색(Light Green) : 10
		밝은 청록색(Light Cyan) : 11
		밝은 빨간색(Light Red) : 12
		밝은 자주색(Light Magenta) : 13
		밝은 노란색(Light Yellow) : 14
		흰색(White) : 15*/



}
