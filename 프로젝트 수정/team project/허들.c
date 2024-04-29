#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define koko_X 0
#define koko_Y 15
#define TREE_X 90
#define TREE_Y 25
#define ����_X 90
#define ����_Y 25
#define STONE_X 125
#define STONE_Y 0
#define koko_BENT_X koko_X                   // �� ����
#define koko_BENT_Y (koko_Y + 6)


void setting();               // Ŀ���̵�, �ܼ�â ����
//void gotoxy(int x, int y);    // 
void start();
int game(int);
void re(int);
int crashing();
void end(int);


void ����(int);                  // �����׸���
void ����1();                 //���������


//�� ���� �Լ�
void draw_koko(int);          // �߱׸���
void erase_koko();           // �������
void earase_foot();           // �������
void draw_bent_koko(); // ���̱� ��� �׸��� �Լ�
//void erase_bent_koko(); // ���̱� ��� ����� �Լ�


//���� ���� �Լ�
void tree();                  //���� �����ʿ��� �������� �̵���Ű�� �Լ�
void draw_tree();            // �����׸���
void erase_tree();           // ���������


// 
void draw_stone(); // �� �׸��� �Լ�
void erase_stone(); // �� ����� �Լ�
void stone(); // �� �̵� �Լ�



int ����X = ����_X;
int treeX = TREE_X;
int kokoX = koko_X;
int kokoY = koko_Y;
int stoneX = STONE_X;
int stoneY = STONE_Y;
int bentX = koko_BENT_X;




// �� ���̱�
int isBent = 0; // ���̱� ���θ� ��Ÿ���� ����
int key = 0; //Ű���� �Է� �ޱ�


int koko()
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
            if (key == 32 && kokoY - 15 == 0) { //'�����̽� ��'�� ������ ���� �ٴڿ� ���� ��

                int h = 0; //���� ���� �ʱ�ȭ

                while (h < 9) { //y������ 8ĭ ��� == ��������
                    erase_koko();
                    kokoY--;
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
                    kokoY++;
                    erase_koko();
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
    system("cls");
    re(tic);
    tree();
    draw_koko(tic);
    ����(tic);
    stone();

    Sleep(20); //0.02��      //������ ����
    tic++;

    return tic;
}



int crashing() { //�浹 ����   //���̵� '��'
    // (����1 && ����2) && ����
    // ����1: ������ ���� 11ĭ���� �ڿ� ����
    // ����2: ������ ���� 15ĭ���� �տ� ����
    // ����1 && ����2: ������ ���� 11ĭ�� 15ĭ ���̿� ����
    // ����: �� �� 3ĭ�� ���� 5ĭ ���� ���̰� ���ų� ���� ��
    if ((kokoX + 6 <= treeX + 2 && kokoX + 10 >= treeX + 2) && kokoY + 12 >= TREE_Y + 2)
        return -1;
    if (stoneX <= 11 && isBent == 0) {
        //�� ������ġ�� 11(�ߺ��� ������ġ)�� �����ϰ� && isBent(����Ʈ�� �������ʾҶ�)= 0 ==> �浹
        return -1;
    }
    else
        return 0;
}




void draw_koko(int tic) {
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
    gotoxy(kokoX, kokoY);          printf("\n");
    gotoxy(kokoX, kokoY + 1);      printf("        �����\n");
    gotoxy(kokoX, kokoY + 2);      printf("        ������\n");
    gotoxy(kokoX, kokoY + 3);      printf("        ������\n");


    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(kokoX, kokoY + 4);      printf("      ��������\n");
    gotoxy(kokoX, kokoY + 5);      printf("    ����������\n");


    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(kokoX, kokoY + 6);                printf("    �����");
    SetConsoleTextAttribute(hConsole, 0);    printf("��");
    SetConsoleTextAttribute(hConsole, 15);   printf("���");
    SetConsoleTextAttribute(hConsole, 0);    printf("��");
    SetConsoleTextAttribute(hConsole, 15);   printf("��\n");

    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(kokoX, kokoY + 7);               printf("��������");
    SetConsoleTextAttribute(hConsole, 6);   printf("����");
    SetConsoleTextAttribute(hConsole, 15);  printf("��\n");

    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(kokoX, kokoY + 8);               printf("���������");
    SetConsoleTextAttribute(hConsole, 4);   printf("��");
    SetConsoleTextAttribute(hConsole, 15);  printf("���\n");

    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(kokoX, kokoY + 9);              printf("���������");
    SetConsoleTextAttribute(hConsole, 4);  printf("��");
    SetConsoleTextAttribute(hConsole, 15); printf("���\n");

    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(kokoX, kokoY + 10);      printf("  �����������\n");
    gotoxy(kokoX, kokoY + 11);      printf("    ����������\n");
    gotoxy(kokoX, kokoY + 12);      printf("      ��� ��� ���\n");


    // ���̴� ���
    if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
        erase_koko();
        gotoxy(kokoX, kokoY);          printf("\n");
        gotoxy(kokoX, kokoY + 1);      printf("\n");
        gotoxy(kokoX, kokoY + 2);      printf("\n");
        gotoxy(kokoX, kokoY + 3);      printf("\n");
        gotoxy(kokoX, kokoY + 4);      printf("\n");
        gotoxy(kokoX, kokoY + 5);      printf("\n");
        SetConsoleTextAttribute(hConsole, 4);
        gotoxy(kokoX, kokoY + 6);      printf("       ����\n");
        gotoxy(kokoX, kokoY + 7);      printf("      ������ \n");
        SetConsoleTextAttribute(hConsole, 15);
        gotoxy(kokoX, kokoY + 8);      printf("    ��������\n");;
        gotoxy(kokoX, kokoY + 9);      printf("  �����  ���  �� \n");
        gotoxy(kokoX, kokoY + 10);     printf("��������");;
        SetConsoleTextAttribute(hConsole, 6);
        printf("����\n");
        SetConsoleTextAttribute(hConsole, 15);
        gotoxy(kokoX, kokoY + 11);     printf("  ��������");
        SetConsoleTextAttribute(hConsole, 4);
        printf("��");
        SetConsoleTextAttribute(hConsole, 15);
        printf("��\n");
        SetConsoleTextAttribute(hConsole, 15);
        gotoxy(kokoX, kokoY + 12);     printf("    ��� ��� ���\n");
        isBent = 1;
    }
    else {
        if (isBent) {
            erase_koko();
            isBent = 0;
        }
    }

    //�� ������ ����
    if (toc >= 0 && toc <= 3) { // 4 tic ���� ����
        earase_foot();
        SetConsoleTextAttribute(hConsole, 6);
        gotoxy(kokoX + 10, kokoY + 13); //�� �׸���
        printf("��\n");
    }
    else if (toc >= 0 && toc <= 5) {
        earase_foot();
        SetConsoleTextAttribute(hConsole, 6);
        gotoxy(kokoX + 14, kokoY + 13); //�� �׸���
        printf("��\n");
    }

    SetConsoleTextAttribute(hConsole, saved_attributes);

    return 0;
}

void earase_foot() {
    gotoxy(kokoX, kokoY + 13);
    printf("                        \n");
    printf("                          ");
}

void erase_koko() {
    for (int i = 0; i < 24; i++) {
        gotoxy(kokoX, 6 + i);
        printf("                        ");
    }
    earase_foot();
}



void ����(int tic) { //������ �׸���---------------------------------------------------------------------------------------------------������

    int toc = tic % 8;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    WORD saved_attributes = consoleInfo.wAttributes;

    SetConsoleTextAttribute(hConsole, 2);

    //�� ������ ����
    if (toc >= 0 && toc <= 3) //4tic ���� ����
    {
        ����1();
        gotoxy(����X, ����_Y + 1);  printf("       ���      \n");
        gotoxy(����X, ����_Y + 2);  printf("    ��      ��   \n");
        gotoxy(����X, ����_Y + 3);  printf("���          �� \n");
    }
    else
    {
        ����1();
        gotoxy(����X, ����_Y + 1);  printf("                 \n");
        gotoxy(����X, ����_Y + 2);  printf("                 \n");
        gotoxy(����X, ����_Y + 3);  printf("��������� \n");
    }

    SetConsoleTextAttribute(hConsole, saved_attributes);

    return 0;
}

void ����1() { //�� �����
    gotoxy(����X, 6);
    printf("                                             \n");
    printf("                                             \n");
    printf("                                               ");
}
void ����2() { //�� �����
    gotoxy(����X, 6);
    printf("                                             \n");
    printf("                                             \n");
    printf("                                               ");
}



//



void draw_tree() { //���� �׸���
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (hConsole == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Error getting console handle\n");
        return 1;
    }

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    WORD saved_attributes = consoleInfo.wAttributes;

    SetConsoleTextAttribute(hConsole, 6 + 0);

    gotoxy(treeX, TREE_Y + 1);        printf("    \n");
    gotoxy(treeX + 2, TREE_Y + 2);      printf(" ��\n");
    gotoxy(treeX + 2, TREE_Y + 3);      printf("���");



    SetConsoleTextAttribute(hConsole, saved_attributes);

    return 0;
}

void erase_tree() { //���� �����
    gotoxy(treeX + 2, TREE_Y + 1);   printf("\n");
    gotoxy(treeX + 2, TREE_Y + 1);   printf("    \n");
    gotoxy(treeX + 3, TREE_Y + 2);     printf("   \n");
    gotoxy(treeX + 4, TREE_Y + 3);      printf("    ");
}

void tree() { //���� �����ʿ��� �������� �̵�
    treeX--; //�������� �� ĭ �̵�
    erase_tree(); //�����
    draw_tree(); //�׸���

    if (treeX == 0)
        treeX = TREE_X; //������ ���� ������ �̵��ϸ� �ʱ�ȭ
}

// ���׸���
void draw_stone() {
    gotoxy(stoneX + 1, stoneY + 17); printf("�����");
}

void erase_stone() {
    gotoxy(stoneX + 1, stoneY + 17); printf("           ");
}

void stone() {

    stoneX--;
    erase_stone();
    draw_stone();

    if (stoneX == 0)
        stoneX = STONE_X; // ȭ���� ����� �ʱ� ��ġ�� �̵�
}



void setting() {
    //�ܼ�â ����
    system("title Jumping koko by.woo");
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
        printf(" ���� ����: space�� shift�� ����Ͽ� ��ֹ��� ���ϼ���! (space : �ٱ�, shift : ���̱�)\n\n");
        printf("                                                    �����̽��ٸ� ������ ������ �����ϼ���.");
        draw_koko(0);

        if (_kbhit()) {
            key = _getch();
            if (key == 32) { //'�����̽� ��' �Է� Ȯ��
                system("cls");
                break;
            }
        }
    }

}

void re(int tic) { //���� ���
    gotoxy(45, 1);
    printf("score : %4d", tic / 5 * 10); // tic/5 �� 10��      //�ʵ� �� 4ĭ Ȯ�� (nõ������)
}


void end(int tic) { //���� ȭ��

    treeX = TREE_X;
    kokoX = koko_X;
    kokoY = koko_Y;
    stoneX = STONE_X;
    stoneY = STONE_Y;
    bentX = koko_BENT_X;

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
            koko();
            break;
        }
        else if (key == 'N' || key == 'n') {

            printf("\n\n\n\n");
            exit(0);
        }
    }
}