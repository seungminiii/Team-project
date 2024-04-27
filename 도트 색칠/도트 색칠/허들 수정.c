#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define DINO_X 0
#define DINO_Y 15
#define TREE_X 94
#define TREE_Y 25
// ����� ������ ����



void setting();               // Ŀ���̵�, �ܼ�â ����
//void gotoxy(int x, int y);    // 
void start();
int game(int);
void sco(int);
int crashing();
void end(int);




//���� ���� �Լ�
void draw_dino(int);          // ����׸���
void earase_dino();           // ���������
void earase_foot();           // �������

//���� ���� �Լ�
void tree();                  //���� �����ʿ��� �������� �̵���Ű�� �Լ�
void draw_tree();            // �����׸���
void erase_tree();           // ���������


int treeX = TREE_X;
int dinoX = DINO_X;
int dinoY = DINO_Y;



int key = 0; //Ű���� �Է� �ޱ�

void dino()
{
    printf("\033[0m");

    int tic = 0; //���� �� �ð� �������� ���� ���� ���
    int crash = 0; //�浹 üũ

    setting();
    start();

    while (1) {

        tic = game(tic);

        //'�����̽� ��' ������ ����
        if (_kbhit()) {
            key = _getch();
            if (key == 32 && dinoY - 15 == 0) { //'�����̽� ��'�� ������ ������ �ٴڿ� ���� ��

                int h = 0; //���� ���� �ʱ�ȭ

                while (h < 10) { //y������ 8ĭ ��� == ��������
                    earase_dino();
                    dinoY--;
                    tic = game(tic);
                    crash = crashing();
                    if (crash == -1)
                        break;
                    h++;
                }

                while (h > 0) { //y������ 8ĭ �ϰ�
                    tic = game(tic);
                    crash = crashing();
                    if (crash == -1)
                        break;
                    dinoY++;
                    earase_dino();
                    h--;
                }
            }
        }
        crash = crashing();
        if (crash == -1) //�浹 �� Ż��
            break;

    }

    end(tic);

    system("pause>>null");
    return 0;
}

int game(int tic) { //����ȭ�� ���� ���
    sco(tic);
    tree();
    draw_dino(tic);

    Sleep(20); //0.02��      //������ ����
    tic++;

    return tic;
}

int crashing() { //�浹 ����   //���̵� '��'
    // (����1 && ����2) && ����
    // ����1: ������ ���� 11ĭ���� �ڿ� ����
    // ����2: ������ ���� 15ĭ���� �տ� ����
    // ����1 && ����2: ������ ���� 11ĭ�� 15ĭ ���̿� ����
    // ����: ���� �� 3ĭ�� ���� 5ĭ ���� ���̰� ���ų� ���� ��
    if ((dinoX + 6 <= treeX + 2 && dinoX + 10 >= treeX + 2) && dinoY + 12 >= TREE_Y + 2)
        return -1;
    else
        return 0;
}

void draw_dino(int tic) { // �� �׸�
    int toc = tic % 8;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    WORD saved_attributes = consoleInfo.wAttributes;


    if (hConsole == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Error getting console handle\n");
        return 1;
    }

    SetConsoleTextAttribute(hConsole, 4);
    gotoxy(dinoX, dinoY);         printf("\n");
    gotoxy(dinoX, dinoY + 1);      printf("        �����\n");
    gotoxy(dinoX, dinoY + 2);      printf("        ������\n");
    gotoxy(dinoX, dinoY + 3);      printf("        ������\n");


    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(dinoX, dinoY + 4);      printf("      ��������\n");
    gotoxy(dinoX, dinoY + 5);      printf("    ����������\n");

    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(dinoX, dinoY + 6);      printf("  ������");
    SetConsoleTextAttribute(hConsole, 0);
    printf("��");
    SetConsoleTextAttribute(hConsole, 15);
    printf("���");
    SetConsoleTextAttribute(hConsole, 0);
    printf("��");
    SetConsoleTextAttribute(hConsole, 15);
    printf("��\n");


    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(dinoX, dinoY + 7);       printf("���  �����");
    SetConsoleTextAttribute(hConsole, 6);
    printf("����\n");

    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(dinoX, dinoY + 8);       printf("���  ������");
    SetConsoleTextAttribute(hConsole, 4);
    printf("��");
    SetConsoleTextAttribute(hConsole, 15);
    printf("���\n");


    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(dinoX, dinoY + 9);        printf("���������");
    SetConsoleTextAttribute(hConsole, 4);
    printf("��");
    SetConsoleTextAttribute(hConsole, 15);
    printf("���\n");



    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(dinoX, dinoY + 10);      printf("  �����������\n");
    gotoxy(dinoX, dinoY + 11);      printf("    ����������\n");
    gotoxy(dinoX, dinoY + 12);      printf("      ��� ��� ���\n");


    //�� ������ ����
    if (toc >= 0 && toc <= 3) //4tic ���� ����
    {
        earase_foot();
        SetConsoleTextAttribute(hConsole, 6);
        gotoxy(dinoX, dinoY + 13); //�� �׸���
        printf("          ��\n");
        //printf("         @@");
    }
    else
    {
        earase_foot();
        SetConsoleTextAttribute(hConsole, 6);
        gotoxy(dinoX, dinoY + 13); //�� �׸���
        printf("               ��\n");
        //printf("              @@");
    }

    SetConsoleTextAttribute(hConsole, saved_attributes);

    return 0;
}

void earase_foot() { //�� �����
    gotoxy(dinoX, dinoY + 13);
    printf("                 \n");
    printf("                 ");
}

void earase_dino() { //���� �����
    for (int i = 0; i < 24; i++) {   // ������ �����ϰ� ���ƿ��µ��� ����� ����� ������. // ������� ������ �Ӹ��� õ�忡 �ΰ���ų� ���� ������µ��� ������ ����
        gotoxy(dinoX, 6 + i);
        printf("                              ");
    }
    earase_foot();
}

void draw_tree() { // ���� �׸���
    gotoxy(treeX + 2, TREE_Y);         printf("\n");
    gotoxy(treeX, TREE_Y + 1);        printf("\n");

    // �� ���� �ֱ�
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (hConsole == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Error getting console handle\n");
        return 1;
    }
    // ���� �ܼ� ���� ����
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    WORD saved_attributes = consoleInfo.wAttributes;
    // ���� ����
    SetConsoleTextAttribute(hConsole, 11);

    gotoxy(treeX, TREE_Y + 2);        printf("    ��\n");
    gotoxy(treeX + 2, TREE_Y + 3);      printf(" ���\n");
    gotoxy(treeX + 2, TREE_Y + 4);      printf("����");
    // ���� �������� ����
    SetConsoleTextAttribute(hConsole, saved_attributes);

    return 0;
}

void erase_tree() { //���� �����
    gotoxy(treeX + 3, TREE_Y);        printf("\n");
    gotoxy(treeX + 1, TREE_Y + 1);   printf("\n");
    gotoxy(treeX + 1, TREE_Y + 2);   printf("      \n");
    gotoxy(treeX + 3, TREE_Y + 3);     printf("     \n");
    gotoxy(treeX + 3, TREE_Y + 4);      printf("      ");
}

void tree() { //���� �����ʿ��� �������� �̵�
    treeX--; //�������� �� ĭ �̵�
    erase_tree(); //�����
    draw_tree(); //�׸���

    if (treeX == 0)
        treeX = TREE_X; //������ ���� ������ �̵��ϸ� �ʱ�ȭ
}

void setting() {  // ----------------------------------------------------------------------------------------------------------------setting
    //�ܼ�â ����
    system("title Jumping Dino by.woo");
    system("mode con:cols=150 lines=30");

    //Ŀ�� ����
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.dwSize = 1;
    ConsoleCursor.bVisible = 0; //Ŀ�� ����
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void start() { //���� ȭ��
    while (1) {
        gotoxy(30, 10);
        printf("�����̽��ٸ� ������ ������ �����ϼ���.");
        draw_dino(0);

        if (_kbhit()) {
            key = _getch();
            if (key == 32) { //'�����̽� ��' �Է� Ȯ��
                system("cls");
                break;
            }
        }
    }
}

void sco(int tic) { //���� ���
    gotoxy(45, 1);
    printf("\n                              score : % 4d", tic / 5 * 10); // tic/5 �� 10��      //�ʵ� �� 4ĭ Ȯ�� (nõ������)
}

void end(int tic) { //���� ȭ��

    treeX = TREE_X;
    dinoX = DINO_X;
    dinoY = DINO_Y;

    char key;
    while (1) {

        system("cls");
        printf("\n                                                     score : % 4d\n\n", tic / 5 * 10);
        over();

        printf("\n\n");
        printf("                                          �ٽ� �����Ͻðڽ��ϱ�? ( Y / N ): ");
        scanf(" %c", &key);

        if (key == 'Y' || key == 'y') {
            printf("\n\n\n\n");
            dino();
            break;
        }
        else if (key == 'N' || key == 'n') {
            printf("\n\n\n\n");
            exit(0);
        }
    }
}