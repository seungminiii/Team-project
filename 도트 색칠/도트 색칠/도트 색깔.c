#include <windows.h>
#include <stdio.h>

int main() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


	SetConsoleTextAttribute(hConsole, 4);
	printf("    �����       ������\n");
	printf("  �������   ��������\n");
	printf("  �������   ����� ���� \n");
	printf("   ���  ����   ����   ���\n");
	printf("        ������������\n");


	SetConsoleTextAttribute(hConsole, 4);
	printf("      ���");
	SetConsoleTextAttribute(hConsole, 15);
	printf("���������");
	SetConsoleTextAttribute(hConsole, 4);
	printf("���\n");


	SetConsoleTextAttribute(hConsole, 4);
	printf("    ���");
	SetConsoleTextAttribute(hConsole, 15);
	printf("�����������");
	SetConsoleTextAttribute(hConsole, 4);
	printf("���\n");
	

	SetConsoleTextAttribute(hConsole, 4);
	printf("    ���");
	SetConsoleTextAttribute(hConsole, 15);
	printf("���");
	SetConsoleTextAttribute(hConsole, 0);
	printf("��");
	SetConsoleTextAttribute(hConsole, 15);
	printf("�����");
	SetConsoleTextAttribute(hConsole, 0);
	printf("��");
	SetConsoleTextAttribute(hConsole, 15);
	printf("���");
	SetConsoleTextAttribute(hConsole, 4);
	printf("���\n");


	SetConsoleTextAttribute(hConsole, 4);
	printf("    ���");
	SetConsoleTextAttribute(hConsole, 15);
	printf("���");
	SetConsoleTextAttribute(hConsole, 0);
	printf("��");
	SetConsoleTextAttribute(hConsole, 15);
	printf("��");
	SetConsoleTextAttribute(hConsole, 6);
	printf("���");
	SetConsoleTextAttribute(hConsole, 15);
	printf("��");
	SetConsoleTextAttribute(hConsole, 0);
	printf("��");
	SetConsoleTextAttribute(hConsole, 15);
	printf("���");
	SetConsoleTextAttribute(hConsole, 4);
	printf("���\n");


	SetConsoleTextAttribute(hConsole, 4);
	printf("      ��");
	SetConsoleTextAttribute(hConsole, 15);
	printf("��");
	SetConsoleTextAttribute(hConsole, 12);
	printf("��");
	SetConsoleTextAttribute(hConsole, 15);
	printf("�������");
	SetConsoleTextAttribute(hConsole, 12);
	printf("��");
	SetConsoleTextAttribute(hConsole, 15);
	printf("��");
	SetConsoleTextAttribute(hConsole, 4);
	printf("��\n");


	SetConsoleTextAttribute(hConsole, 4);
	printf("        �����������");
	

	/*������(Black) : 0
		�Ķ���(Blue) : 1
		�ʷϻ�(Green) : 2
		û�ϻ�(Cyan) : 3
		������(Red) : 4
		���ֻ�(Magenta) : 5
		�����(Yellow) : 6
		ȸ��(Gray) : 7
		���� ȸ��(Light Gray) : 8
		���� �Ķ���(Light Blue) : 9
		���� �ʷϻ�(Light Green) : 10
		���� û�ϻ�(Light Cyan) : 11
		���� ������(Light Red) : 12
		���� ���ֻ�(Light Magenta) : 13
		���� �����(Light Yellow) : 14
		���(White) : 15*/



}
