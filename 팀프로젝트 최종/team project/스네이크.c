#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 25
#define INITIAL_LENGTH 3        // �� ����
#define DELAY 100       // �� �ӵ�
#define MAX_FOOD 10     // �ִ� ���� ���� 

enum Direction { UP, DOWN, LEFT, RIGHT };

struct Position {
    int x;
    int y;
};

struct Snake {
    struct Position body[WIDTH * HEIGHT];
    int length;
    enum Direction dir;
};

struct Snake snake;
struct Position food[MAX_FOOD];
bool game_over = false;
int point = 0;      // ���� ������ ������ ������ ���� (score�� ��Ÿ���µ� ��ֹ����ϱ�� ���� �̸� �浹�Ǽ� �ٲ�)

void setup() {
    snake.length = INITIAL_LENGTH;
    snake.dir = RIGHT;

    // �� �ʱ� ��ġ ����
    for (int i = 0; i < snake.length; i++) {
        snake.body[i].x = WIDTH / 2 - i;
        snake.body[i].y = HEIGHT / 2;
    }

    // ���� �ʱ� ��ġ ����
    srand(time(NULL));
    for (int i = 0; i < MAX_FOOD; i++) {
        food[i].x = rand() % WIDTH;
        food[i].y = rand() % HEIGHT;
    }
}
// ���� �ʱ�ȭ, ���� ��Ģ ����
void iinit() {
    HWND console = GetConsoleWindow();
    RECT rect;
    GetWindowRect(console, &rect);
    MoveWindow(console, rect.left, rect.top, 500, 600, TRUE);

    // ���� ��Ģ ����
    system("cls");
    printf("\033[0m");      // ���� ���� ����
    printf("\n\n\n\n\n\n");
    printf("                      < ���� ���� >\n\n");
    printf("              ���� �������� ���̸� ��������!\n\n");
    printf("               (����Ű ��,��,��,��� ����)\n\n");
    printf("\n\n");
    printf("          ������ �����Ϸ��� �ƹ� Ű�� ��������...");

    // �ƹ� Ű�� �Է¹ޱ�
    getchar();
    getchar();
}


void draw() {
    // �ܼ� Ŀ���� Ȩ ��ġ�� �̵�
    COORD coord;
    coord.X = 0;
    coord.Y = 100;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    // ������ �׸���
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                printf("\033[1;36m#");
            }
            else {
                bool is_food = false;
                for (int k = 0; k < MAX_FOOD; k++) {
                    if (food[k].x == j && food[k].y == i) {
                        printf("\033[0m*");
                        is_food = true;
                        break;
                    }
                }

                if (!is_food) {
                    bool is_snake = false;
                    for (int k = 0; k < snake.length; k++) {
                        if (snake.body[k].x == j && snake.body[k].y == i) {
                            printf("\033[1;33mO");
                            is_snake = true;
                            break;
                        }
                    }
                    if (!is_snake) {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }

    // ���ھ� ���
    printf("\n");
    printf("                Score: %d", point);
    printf("\n");
}



void input() {
    if (_kbhit()) {
        int key = _getch();
        switch (key) {
        case 'x':
            game_over = true;
            break;
        case 72: // ȭ��ǥ ��
            if (snake.dir != DOWN) {
                snake.dir = UP;
            }
            break;
        case 80: // ȭ��ǥ �Ʒ�
            if (snake.dir != UP) {
                snake.dir = DOWN;
            }
            break;
        case 75: // ȭ��ǥ ����
            if (snake.dir != RIGHT) {
                snake.dir = LEFT;
            }
            break;
        case 77: // ȭ��ǥ ������
            if (snake.dir != LEFT) {
                snake.dir = RIGHT;
            }
            break;
        }
    }
}

void move() {
    // ���� ���� ��ġ ����
    struct Position tail = snake.body[snake.length - 1];

    // ���� ���� �̵�
    for (int i = snake.length - 1; i > 0; i--) {
        snake.body[i] = snake.body[i - 1];
    }

    // ���� �Ӹ� �̵�
    switch (snake.dir) {
    case UP:
        snake.body[0].y--;
        break;
    case DOWN:
        snake.body[0].y++;
        break;
    case LEFT:
        snake.body[0].x--;
        break;
    case RIGHT:
        snake.body[0].x++;
        break;
    }

    // ���� �ε����� ���� ����
    if (snake.body[0].x <= 0 || snake.body[0].x >= WIDTH - 1 ||
        snake.body[0].y <= 0 || snake.body[0].y >= HEIGHT - 1) {
        game_over = true;
        return;
    }

    // ���� ���� �ε����� ���� ����
    for (int i = 1; i < snake.length; i++) {
        if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
            game_over = true;
            return;
        }
    }

    // ���� ������ ���� ����
    for (int i = 0; i < MAX_FOOD; i++) {
        if (snake.body[0].x == food[i].x && snake.body[0].y == food[i].y) {
            snake.length++;
            snake.body[snake.length - 1] = tail;
            food[i].x = rand() % (WIDTH - 2) + 1;
            food[i].y = rand() % (HEIGHT - 2) + 1;
            point++;
        }
    }
}

int bamm() {

    HWND console = GetConsoleWindow();
    RECT rect;
    GetWindowRect(console, &rect);
    MoveWindow(console, rect.left, rect.top, 500, 600, TRUE);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);

    char key;
    while (1) {
        game_over = false;
        point = 0;

        setup();

        iinit();
        while (!game_over) {
            draw();
            input();
            move();
            Sleep(DELAY);
        }

        system("cls");
        printf("\033[0m");
        printf("\n\n                         Score: %d", point);
        while (1) {
            // Ű���� �Է��� �ִ��� Ȯ��
            if (_kbhit()) { _getch(); over(); break; }
        }


        printf("\n\n");
        printf("                                          �ٽ� �����Ͻðڽ��ϱ�? ( Y / N ): ");
        scanf("%c", &key);

        if (key != 'Y') {
            printf("\n\n\n\n");
            break;
        }
    }
    return 0;
}