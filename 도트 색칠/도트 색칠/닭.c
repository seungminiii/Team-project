#include <windows.h>
#include <stdio.h>

int main() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	printf("\n\n색 안채운거\n\n");

	if (hConsole == INVALID_HANDLE_VALUE) {
		fprintf(stderr, "Error getting console handle\n");
		return 1;
	}

	SetConsoleTextAttribute(hConsole, 4);
	printf("\n");
	printf("        ■■■■\n");
	printf("        ■■■■■\n");
	printf("        ■■■■■\n");

	SetConsoleTextAttribute(hConsole, 15);
	printf("       ■         ■\n");
	printf("     ■             ■\n");
	printf("■■■     ■    ■ ■\n");


	SetConsoleTextAttribute(hConsole, 15);
	printf("■  ■       ");
	SetConsoleTextAttribute(hConsole, 14);
	printf("■■■■\n");


	SetConsoleTextAttribute(hConsole, 15);
	printf("■             ");
	SetConsoleTextAttribute(hConsole, 4);
	printf("■");
	SetConsoleTextAttribute(hConsole, 15);
	printf("   ■\n");


	SetConsoleTextAttribute(hConsole, 15);
	printf("■             ");
	SetConsoleTextAttribute(hConsole, 4);
	printf("■");
	SetConsoleTextAttribute(hConsole, 15);
	printf("   ■\n");

	SetConsoleTextAttribute(hConsole, 15);
	printf("  ■                ■\n");
	printf("    ■             ■\n");
	printf("      ■■ ■■ ■■\n");

	SetConsoleTextAttribute(hConsole, 14);
	printf("        ■      ■\n");


	printf("\n\n색 채운거\n\n");


	SetConsoleTextAttribute(hConsole, 4);
	printf("        ■■■■\n");
	printf("        ■■■■■\n");
	printf("        ■■■■■\n");

	SetConsoleTextAttribute(hConsole, 15);
	printf("      ■■■■■■■\n");
	printf("    ■■■■■■■■■\n");

	SetConsoleTextAttribute(hConsole, 15);
	printf("■■■■■■");
	SetConsoleTextAttribute(hConsole, 0);
	printf("■");
	SetConsoleTextAttribute(hConsole, 15);
	printf("■■");
	SetConsoleTextAttribute(hConsole, 0);
	printf("■");
	SetConsoleTextAttribute(hConsole, 15);
	printf("■\n");

	SetConsoleTextAttribute(hConsole, 15);
	printf("■■  ■■■■");
	SetConsoleTextAttribute(hConsole, 6);
	printf("■■■\n");

	SetConsoleTextAttribute(hConsole, 15);
	printf("■■  ■■■■■");
	SetConsoleTextAttribute(hConsole, 4);
	printf("■");
	SetConsoleTextAttribute(hConsole, 15);
	printf("■■\n");

	SetConsoleTextAttribute(hConsole, 15);
	printf("■■■■■■■■");
	SetConsoleTextAttribute(hConsole, 4);
	printf("■");
	SetConsoleTextAttribute(hConsole, 15);
	printf("■■\n");

	SetConsoleTextAttribute(hConsole, 15);
	printf("  ■■■■■■■■■■\n");
	printf("    ■■■■■■■■■\n");
	printf("      ■■ ■■ ■■\n");

	SetConsoleTextAttribute(hConsole, 6);
	printf("        ■      ■\n");
}