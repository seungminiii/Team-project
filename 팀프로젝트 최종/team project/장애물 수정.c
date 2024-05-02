#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define WIDTH 40
#define HEIGHT 30
#define MAX_FOOD 20  
#define PLAYER_SPEED 1
#define TRUE 1
#define FALSE 0

typedef struct {
    int x;
    int y;
    int act;
    char symbol;
}Poo;

typedef struct {
    int x;
}Player;

Poo poo[WIDTH];
Poo food[MAX_FOOD];
Player player;

int isKeyDown(int key) {
    return ((GetAsyncKeyState(key) & 0x8000) != 0);
}

// ���� �ʱ�ȭ, ���� ��Ģ ����
void init() {
    int i;
    for (i = 0; i < WIDTH; i++)
        poo[i].act = FALSE;
    player.x = WIDTH / 2;

    // ���� ��Ģ ����
    system("cls");
    printf("\033[0m");      // ���� ���� ����
    printf("\n\n\n\n\n\n");
    printf("                            < ���� ���� >\n\n");
    printf("        �÷��̾ �¿� ȭ��ǥ�� �������� (����Ű ��,��� ����)\n\n");
    printf("                ��ֹ�(o)�� ���ϰ� ����(w)�� ��������!\n\n");
    printf("                    ���� �� ���� 100���� �߰��˴ϴ�.\n\n");
    printf("\n\n");
    printf("                ������ �����Ϸ��� �ƹ� Ű�� ��������...");

    // �ƹ� Ű�� �Է¹ޱ�
    getchar();
    getchar();
}

void CreatePoo() {
    int i;
    for (i = 0; i < WIDTH; i++) {
        if (!poo[i].act) {
            poo[i].x = rand() % WIDTH;
            poo[i].y = HEIGHT - 1;
            poo[i].act = TRUE;
            return;
        }
    }
}

void CreateFood() {
    int i;
    int count = 0;

    for (i = 0; i < MAX_FOOD; i++) {
        if (!food[i].act && count < 1 && rand() % 20 == 0) { // 20�� �߿� �� ���� 'W' ���� ����, �׸��� �̹� 5���� �����Ǿ� �ִٸ� �� �̻� �������� ����.
            food[i].x = rand() % (WIDTH);
            food[i].y = HEIGHT - 1;
            food[i].act = TRUE;
            food[i].symbol = 'W'; // "W" ������ ��� ����
            count++;
        }
    }
}

//���ھ�
int score = 0;
int score2 = 0;
void MovePoo() {
    int i;
    for (i = 0; i < WIDTH; i++) {
        if (poo[i].act) {
            poo[i].y--;
            if (poo[i].y == 0) {
                score++; // ���� ���� ������ ���ھ� ����
            }
            if (food[i].y < 0) {
                food[i].act = FALSE;
            }
        }
    }
}

void MoveFood() {
    int i;
    for (i = 0; i < MAX_FOOD; i++) {
        if (food[i].act) {
            food[i].y--;

            if (food[i].y < 0) {
                food[i].act = FALSE;
            }
        }
    }
}

void DeletePoo() {
    int i;
    for (i = 0; i < WIDTH; i++) {
        if (poo[i].act && poo[i].y < 0) {
            poo[i].act = FALSE;
        }
    }
}

void DeleteFood() {
    int i;
    for (i = 0; i < MAX_FOOD; i++) {
        if (food[i].y < 0) {
            food[i].act = FALSE;
        }
    }
}

// ����ڿ� �� �浹 ���� Ȯ�� 
int PlayerContainsPoo() {
    int i;
    for (i = 0; i < WIDTH; i++) {
        if ((poo[i].act) && (poo[i].y == 0) && (poo[i].x == player.x)) {
            return TRUE;
        }
    }
    return FALSE;
}

// ���̿� �÷��̾� �浹 ���� Ȯ��
int CheckFoodCollision() {
    int i;
    for (i = 0; i < MAX_FOOD; i++) {
        if (food[i].act && player.x == food[i].x && food[i].y == 0) {
            food[i].act = FALSE;
            return TRUE;
        }
    }
    return FALSE;
}

// ����� �Է¿� ���� �÷��̾� ��ġ ����
void MovePlayer() {
    if (isKeyDown(VK_LEFT))
        player.x -= PLAYER_SPEED;
    if (isKeyDown(VK_RIGHT))
        player.x += PLAYER_SPEED;

    if (player.x < 0)
        player.x = 0;
    if (player.x > WIDTH - 1)
        player.x = WIDTH - 1;
}

void PrintMap() {

    system("cls");
    int i;
    for (i = 0; i < WIDTH; i++) {
        if (poo[i].act) {
            gotoxy(poo[i].x, HEIGHT - poo[i].y);
            printf("\033[0mo");
        }
    }
    for (i = 0; i < MAX_FOOD; i++) {
        if (food[i].act) {
            gotoxy(food[i].x, HEIGHT - food[i].y + 1); // ���� ��ġ���� ����
            printf(" "); // ���� ��ġ�� ����
            gotoxy(food[i].x, HEIGHT - food[i].y); // �� ��ġ�� �̵��ؼ� ���
            printf("\033[31mw");
        }
    }

    gotoxy(player.x, HEIGHT);
    printf("\033[1;36mp");
    gotoxy(0, HEIGHT + 1);
    for (i = 0; i < WIDTH; i++)
        printf("\033[0mT");

    gotoxy(0, HEIGHT + 2);
    printf("\033[0m");
    printf("\n");
    printf("            Score: %d, ���� : %d", score, score2);
    printf("\n");
}

void jang() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);

    system("mode con:cols=70 lines=40");

    char key;
    while (1) {
        score = 0;
        score2 = 0;

        while (1) {
            while (!PlayerContainsPoo()) {
                srand((unsigned int)malloc(NULL));

                CreatePoo();
                CreateFood();
                MovePoo();
                MoveFood();
                DeletePoo();
                DeleteFood();

                if (CheckFoodCollision()) {
                    score2++;
                }

                MovePlayer();
                PrintMap();
                Sleep(150);
            }
            system("cls");
            printf("\n\n");
            printf("                              score :: %d", score + score2 * 100);
            printf("\n\n");
           
        }

        over(); // over �Լ� ȣ��

        printf("                  �ٽ� �����Ͻðڽ��ϱ�? ( Y / N ): ");
        scanf(" %c", &key);

        if (key != 'Y') {
            break;
        }

        init();
    }
}