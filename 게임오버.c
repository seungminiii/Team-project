#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define clear_X 0
#define clear_Y 0



void over() {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    while (1) {
        if (_kbhit()) {
            _getch();
            break;
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

        // ����Ʈ�Ǵ� ����� �������� ��¦�̴� ȿ���� ��
        gotoxy(clear_X, clear_Y + 21);  printf("                                  ������������\n");
        gotoxy(clear_X, clear_Y + 22);  printf("                                ���������������\n");
        gotoxy(clear_X, clear_Y + 23);  printf("                              �����������������\n");
        gotoxy(clear_X, clear_Y + 24);  printf("                            �������������������\n");
        gotoxy(clear_X, clear_Y + 25);  printf("                            ��������������������\n");
        gotoxy(clear_X, clear_Y + 26);  printf("                          ���������������������\n");
        gotoxy(clear_X, clear_Y + 27);  printf("                          ���                            ������\n");
        gotoxy(clear_X, clear_Y + 28);  printf("       �Ͼ�..             ��                                �����\n");
        gotoxy(clear_X, clear_Y + 29);  printf("                          ��  �����          ����      �����      �ּ��� ��.�� �̷α�                \n");
        gotoxy(clear_X, clear_Y + 30);  printf("                          ��        ���  ��  ��            �����         �̷��� Ʋ���ٴ�             \n");
        gotoxy(clear_X, clear_Y + 31);  printf("                        ����          ��                  �����                           \n");
        gotoxy(clear_X, clear_Y + 32);  printf("                      ���  ������        �������    ����\n");
        gotoxy(clear_X, clear_Y + 33);  printf("                    ���    ��        ��    ��            ��  ����\n");
        gotoxy(clear_X, clear_Y + 34);  printf("                    ��    ���        �����              �����\n");
        gotoxy(clear_X, clear_Y + 35);  printf("                  ���    ��          ��    ��            ���  ���\n");
        gotoxy(clear_X, clear_Y + 36);  printf("                ����    ��������      �������      ���\n");
        gotoxy(clear_X, clear_Y + 37);  printf("                ��      ���          ��    ��                  ���\n");
        gotoxy(clear_X, clear_Y + 38);  printf("              ���          ���  ��  �����      ��  ��    ���                 ��..\n");
        gotoxy(clear_X, clear_Y + 39);  printf("              ��            ��                              ���\n");
        gotoxy(clear_X, clear_Y + 40);  printf("            ���      ���  ��  ��      ������    ��    ����� \n");
        gotoxy(clear_X, clear_Y + 41);  printf("            ��        ��    ���        �������      ��������\n");
        gotoxy(clear_X, clear_Y + 42);  printf("          ���      ��������                    ���  ���������\n");
        gotoxy(clear_X, clear_Y + 43);  printf("          ���      ��  ��������          ����      �������    ��\n");
        gotoxy(clear_X, clear_Y + 44);  printf("        ��  ������������    �������        �������        ��\n");
        gotoxy(clear_X, clear_Y + 45);  printf("      ��            ��  ������                    ��������            ��\n");
        gotoxy(clear_X, clear_Y + 46);  printf("      ��            ��  �����  ������������  ������             ��\n");
        gotoxy(clear_X, clear_Y + 47);  printf("    ��              ��  �����                          ������              ��\n");


        gotoxy(clear_X, clear_Y + 4);
        printf("\n\n\n");
        printf("    ########        ###       ###       ###   #########    #########    ###      ###   #########   #########\n");
        printf("   ###    ###     ##   ##     ####      ###   ###         ###     ###   ###      ###   ###         ###    ###\n");
        printf("   ###           ###   ###    ####     ####   ###         ###     ###   ###      ###   ###         ###    ###\n");
        printf("   ###   ####   ###########   ### ## ## ###   #########   ###     ###   ###      ###   #########   ######### \n");
        printf("   ###    ###   ###     ###   ###   #   ###   ###         ###     ###    ###    ###    ###         ###   ###\n");
        printf("   ###    ###   ###     ###   ###       ###   ###         ###     ###     ###  ###     ###         ###    ###\n");
        printf("    ########    ###     ###   ###       ###   #########    #########         ##        #########   ###     ### \n");




        Sleep(300);
        // ����Ʈ�Ǵ� ����� �������� ��¦�̴� ȿ���� ��
        gotoxy(clear_X, clear_Y + 21);  printf("                                  ������������\n");
        gotoxy(clear_X, clear_Y + 22);  printf("                                ���������������\n");
        gotoxy(clear_X, clear_Y + 23);  printf("                              �����������������\n");
        gotoxy(clear_X, clear_Y + 24);  printf("                            �������������������\n");
        gotoxy(clear_X, clear_Y + 25);  printf("                            ��������������������\n");
        gotoxy(clear_X, clear_Y + 26);  printf("                          ���������������������\n");
        gotoxy(clear_X, clear_Y + 27);  printf("                          ���                            ������\n");
        gotoxy(clear_X, clear_Y + 28);  printf("                          ��                                �����       �̸� ���� ������                        \n");
        gotoxy(clear_X, clear_Y + 29);  printf("                          ��  �����          ����      �����         Ʋ���ٴ�                      \n");
        gotoxy(clear_X, clear_Y + 30);  printf("                        ����      ���  ��  ��            �����            �߷��߷�                   \n");
        gotoxy(clear_X, clear_Y + 31);  printf("                      ��    ������  ��    �������  �����                              \n");
        gotoxy(clear_X, clear_Y + 32);  printf("      ��,,          ��      ��        ��    ��            ��  ����                             \n");
        gotoxy(clear_X, clear_Y + 33);  printf("                  ���    ��          �����              �����\n");
        gotoxy(clear_X, clear_Y + 34);  printf("                ���      ���        ��    ��            ���  ���\n");
        gotoxy(clear_X, clear_Y + 35);  printf("                ��      ��  �������      �������      ���\n");
        gotoxy(clear_X, clear_Y + 36);  printf("            ���      ����          ��                        ���\n");
        gotoxy(clear_X, clear_Y + 37);  printf("            ��            ��          ��    ��                  ��\n");
        gotoxy(clear_X, clear_Y + 38);  printf("          ��        ���  ��  ��  ��  �����      ��  ��    ���\n");
        gotoxy(clear_X, clear_Y + 39);  printf("          ��        ��    ��                                ���\n");
        gotoxy(clear_X, clear_Y + 40);  printf("          ��        �����    ��      ������    ��    �����\n");
        gotoxy(clear_X, clear_Y + 41);  printf("          ��        ������                    ��      ��������\n");
        gotoxy(clear_X, clear_Y + 42);  printf("          ������������        ������    ���  ���������\n");
        gotoxy(clear_X, clear_Y + 43);  printf("        ��          ��  �������                ���    �������    ��\n");
        gotoxy(clear_X, clear_Y + 44);  printf("      ��            ��������  ���������      �������        ��\n");
        gotoxy(clear_X, clear_Y + 45);  printf("      ��            ��  ������                    ��������            ��\n");
        gotoxy(clear_X, clear_Y + 46);  printf("      ��            ��  �����  ������������  ������             ��\n");
        gotoxy(clear_X, clear_Y + 47);  printf("    ��              ��  �����                          ������              ��\n");



        gotoxy(clear_X, clear_Y + 4);
        printf("\n\n\n");
        printf("    ########        ###       ###       ###   #########    #########    ###      ###   #########   #########\n");
        printf("   ###    ###     ##   ##     ####      ###   ###         ###     ###   ###      ###   ###         ###    ###\n");
        printf("   ###           ###   ###    ####     ####   ###         ###     ###   ###      ###   ###         ###    ###\n");
        printf("   ###   ####   ###########   ### ## ## ###   #########   ###     ###   ###      ###   #########   ######### \n");
        printf("   ###    ###   ###     ###   ###   #   ###   ###         ###     ###    ###    ###    ###         ###   ###\n");
        printf("   ###    ###   ###     ###   ###       ###   ###         ###     ###     ###  ###     ###         ###    ###\n");
        printf("    ########    ###     ###   ###       ###   #########    #########         ##        #########   ###     ### \n");



        Sleep(300);

    }
}
