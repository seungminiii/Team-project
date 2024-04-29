#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define WIDTH 40
#define HEIGHT 40
#define MAX_FOOD 5  
#define PLAYER_SPEED 3

typedef struct {
    int x;
    int y;
    int act;
}Poo;

typedef struct {
    int x;
}Player;

Poo poo[WIDTH];
Player player;

int isKeyDown(int key) {
    return ((GetAsyncKeyState(key) & 0x8000) != 0);
}

// ���� �ʱ�ȭ, ���� ��Ģ ����
void init() {
    int i;
    for (i = 0; i < WIDTH; i++)
        poo[i].act = FALSE;
    player.x = WIDTH / 1;

    // ���� ��Ģ ����
    printf("\033[0m");      // ���� ���� ����
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                    ���� ����: �÷��̾ �¿� ȭ��ǥ�� �������� o�� ���ϼ���!(����Ű ��,��� ����)\n\n");
    printf("                                       ������ �����Ϸ��� �ƹ� Ű�� ��������...");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

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

//���ھ�
int score = 0;
void MoveePoo() {
    int i;
    for (i = 0; i < WIDTH; i++) {
        if (poo[i].act) {
            poo[i].y--;
            if (poo[i].y == 0) {
                score++; // ���� ���� ������ ���ھ� ����
            }
        }
    }
}

// �� �̵� �Լ�
void MovePoo() {
    int i;
    for (i = 0; i < WIDTH; i++) {
        if (poo[i].act) {
            poo[i].y--;

            // ���� �� ���� �������� �� ���ھ� ����
            if (poo[i].y == 0) {
                score++;
            }

            // ���� ȭ�� ������ ����� ��Ȱ��ȭ
            if (poo[i].y < 0) {
                poo[i].act = FALSE;
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
            printf("o");
        }
    }
    gotoxy(player.x, HEIGHT);
    printf("��");
    gotoxy(0, HEIGHT + 1);
    for (i = 0; i < WIDTH - 19; i++)
        printf("��");

    gotoxy(0, HEIGHT + 2);
    printf("\n");
    printf("                Score: %d", score);
    printf("\n");
}

void jang() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);

    char key;
    while (1) {
        score = 0;

        init();
        while (!PlayerContainsPoo()) {
            srand((int)malloc(NULL));

            CreatePoo();
            MovePoo();
            DeletePoo();

            MovePlayer();
            PrintMap();
            Sleep(100);
        }
        system("cls");
        over();

        printf("\n\n");
        printf("                                          �ٽ� �����Ͻðڽ��ϱ�? ( Y / N ): ");
        scanf(" %c", &key);

        if (key != 'Y') {
            printf("\n\n\n\n");
            break;
        }
    }

}