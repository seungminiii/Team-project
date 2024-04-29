#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define COCO_X 0
#define COCO_Y 15
#define TREE_X 90
#define TREE_Y 25
#define ����_X 90
#define ����_Y 25
#define STONE_X 125
#define STONE_Y 17
#define COCO_BENT_X COCO_X                   // �� ����
#define COCO_BENT_Y (COCO_Y + 6)





void setting();               // Ŀ���̵�, �ܼ�â ����
// void gotoxy(int x, int y);   
void start();
int game(int);
void scc(int);
int crashing();
void end(int);
void ����(int);                  // �����׸���
void ����1();                 //���������


//�� ���� �Լ�
void draw_coco(int);          // �߱׸���
void erase_coco();           // �������
void earase_foot();           // �������
void draw_bent_coco(); // ���̱� ��� �׸��� �Լ�
//void erase_bent_coco(); // ���̱� ��� ����� �Լ�


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
int cocoX = COCO_X;
int cocoY = COCO_Y;
int stoneX = STONE_X;
int bentX = COCO_BENT_X;




// �� ���̱�
int isBent = 0; // ���̱� ���θ� ��Ÿ���� ����
int key = 0; //Ű���� �Է� �ޱ�


int coco()
{
    int tic = 0; //���� �� �ð� �������� ���� ���� ���
    int crash = 0; //�浹 üũ

    setting();
    start();

    while (1) {

        tic = game(tic);

        //'�����̽� ��' ������ ����
        if (_kbhit()) {
            key = _getch();
            if (key == 32 && cocoY - 15 == 0) { //'�����̽� ��'�� ������ ���� �ٴڿ� ���� ��

                int h = 0; //���� ���� �ʱ�ȭ

                while (h < 9) { //y������ 8ĭ ��� == ��������
                    erase_coco();
                    cocoY--;
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
                    cocoY++;
                    erase_coco();
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
    scc(tic);
    tree();
    draw_coco(tic);
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
    if ((cocoX + 6 <= treeX + 2 && cocoX + 10 >= treeX + 2) && cocoY + 12 >= TREE_Y + 2)
        return -1;
    if ((cocoX + 6 <= stoneX + 2 && cocoX + 10 >= stoneX + 2) && cocoY + 12 <= STONE_Y + 2) {
        //erase_coco();
        return -1;
    }
    else
        return 0;
}

void draw_coco(int tic) {
    int toc = tic % 8;

    //���� �׸���
    gotoxy(cocoX, cocoY);         printf("\n");
    gotoxy(cocoX, cocoY + 1);      printf("          �����\n");
    gotoxy(cocoX, cocoY + 2);      printf("          ������\n");
    gotoxy(cocoX, cocoY + 3);      printf("          ������\n");
    gotoxy(cocoX, cocoY + 4);      printf("         ��         ��\n");
    gotoxy(cocoX, cocoY + 5);      printf("       ��             ��\n");
    gotoxy(cocoX, cocoY + 6);      printf("  ����     ��    �� ��\n");
    gotoxy(cocoX, cocoY + 7);      printf("  ��  ��       ���� ��\n");
    gotoxy(cocoX, cocoY + 8);      printf("  ��                  ��\n");
    gotoxy(cocoX, cocoY + 9);      printf("  ��                  ��\n");
    gotoxy(cocoX, cocoY + 10);      printf("    ��                ��\n");
    gotoxy(cocoX, cocoY + 11);      printf("      ��             ��\n");
    gotoxy(cocoX, cocoY + 12);      printf("        ��� ��� ��\n");

    // ���̴� ���
    if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
        erase_coco();
        gotoxy(cocoX, cocoY);         printf("\n");
        gotoxy(cocoX, cocoY + 1);      printf("\n");
        gotoxy(cocoX, cocoY + 2);      printf("\n");
        gotoxy(cocoX, cocoY + 3);      printf("\n");
        gotoxy(cocoX, cocoY + 4);      printf("\n");
        gotoxy(cocoX, cocoY + 5);      printf("\n");
        gotoxy(cocoX, cocoY + 6);      printf("\n");
        gotoxy(cocoX, cocoY + 7);      printf("\n");
        gotoxy(cocoX, cocoY + 8);      printf("\n");
        gotoxy(cocoX, cocoY + 9);      printf("\n");
        gotoxy(cocoX, cocoY + 10);      printf("   ��������     \n");
        gotoxy(cocoX, cocoY + 11);      printf(" ����������� \n");
        gotoxy(cocoX, cocoY + 12);      printf(" ����������� \n");
        gotoxy(cocoX, cocoY + 13);      printf("   ��������     \n");
        isBent = 1;
    }
    else {
        if (isBent) {
            erase_coco();
            isBent = 0;
        }
    }


    //�� ������ ����
    if (toc >= 0 && toc <= 3) { // 4 tic ���� ����
        earase_foot();
        gotoxy(cocoX, cocoY + 13); //�� �׸���
        printf("           ��\n");
    }
    else if (toc >= 0 && toc <= 5) {
        earase_foot();
        gotoxy(cocoX, cocoY + 13); //�� �׸���
        printf("                ��\n");
    }

}

void earase_foot() {
    gotoxy(cocoX, cocoY + 13);
    printf("                        \n");
    printf("                          ");
}

void erase_coco() {
    for (int i = 0; i < 24; i++) {
        gotoxy(cocoX, 6 + i);
        printf("                              ");
    }
    earase_foot();
}



void ����(int tic) { //������ �׸���---------------------------------------------------------------------------------------------------������

    int toc = tic % 8;

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



//------------------------------------------------------------------------------------------------------------------------------------------



void draw_tree() { //���� �׸���--------------------------------------------------------------------------------------------------------draw_tree
    gotoxy(treeX + 2, TREE_Y);         printf(" ���\n");
    gotoxy(treeX, TREE_Y + 1);        printf("�� ��� ��\n");
    gotoxy(treeX, TREE_Y + 2);        printf("������\n");
    gotoxy(treeX + 2, TREE_Y + 3);      printf(" ���\n");
    gotoxy(treeX + 2, TREE_Y + 4);      printf(" ���");
}

void erase_tree() { //���� �����
    gotoxy(treeX + 3, TREE_Y);        printf("     \n");
    gotoxy(treeX + 1, TREE_Y + 1);   printf("          \n");
    gotoxy(treeX + 1, TREE_Y + 2);   printf("          \n");
    gotoxy(treeX + 3, TREE_Y + 3);     printf("     \n");
    gotoxy(treeX + 3, TREE_Y + 4);      printf("     ");
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
    gotoxy(stoneX + 1, STONE_Y); printf("�����");
}

void erase_stone() {
    gotoxy(stoneX + 1, STONE_Y); printf("           ");
}

void stone() {

    stoneX--;
    erase_stone();
    draw_stone();

    if (stoneX == 0)
        stoneX = STONE_X; // ȭ���� ����� �ʱ� ��ġ�� �̵�
}



void gotoxy(int x, int y) //----------------------------------------------------------------------------------------------------------gotoxy 
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setting() {  // ----------------------------------------------------------------------------------------------------------------setting
    //�ܼ�â ����
    system("title Jumping coco by.woo");
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
        printf("Press 'Space bar' to start the game");
        draw_coco(0);

        if (_kbhit()) {
            key = _getch();
            if (key == 32) { //'�����̽� ��' �Է� Ȯ��
                system("cls");
                break;
            }
        }
    }
}

void scc(int tic) { //���� ���
    gotoxy(45, 1);
    printf("score : %4d", tic / 5 * 10); // tic/5 �� 10��      //�ʵ� �� 4ĭ Ȯ�� (nõ������)
}

void end(int tic) { //���� ȭ��
    system("cls");
    over();

    gotoxy(40, 20);
    printf("final score : %4d", tic / 5 * 10); //���� ����
}