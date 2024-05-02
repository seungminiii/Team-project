#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>



#define BOARD_SIZE 9



// ������ �迭 �ʱ�ȭ
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
        }
    }
}



// ������ ���
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\033[0m");
    printf("     ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("  %2d", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("  %2d", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("  %2c", board[i][j]);
        }
        printf(" \n\n");
    }
}



// �¸� ���� Ȯ�� :: 5���� ���� �Ǿ��°�?   (��/����
bool checkWin(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char player) {
    int count = 1; // ���� ���� ��
    int r, c; // �ӽ� ����




    // 1. ���� ���� Ȯ��
    r = row;
    c = col - 1;
    while (c >= 0 && board[r][c] == player) { count++; c--; }
    c = col + 1;
    while (c < BOARD_SIZE && board[r][c] == player) { count++; c++; }

    if (count >= 5) return true;




    // 2.���� ���� Ȯ��
    count = 1;
    r = row - 1;
    c = col;
    while (r >= 0 && board[r][c] == player) { count++; r--; }
    r = row + 1;

    while (r < BOARD_SIZE && board[r][c] == player) { count++; r++; }
    if (count >= 5) return true;




    // 3_1.�밢�� ���� Ȯ�� (���� ������ ������ �Ʒ�)
    count = 1;
    r = row - 1;
    c = col - 1;
    while (r >= 0 && c >= 0 && board[r][c] == player) { count++; r--; c--; }

    r = row + 1;
    c = col + 1;
    while (r < BOARD_SIZE && c < BOARD_SIZE && board[r][c] == player) { count++; r++; c++; }

    if (count >= 5) return true;


    // 3_2.�밢�� ���� Ȯ�� (������ ������ ���� �Ʒ�)
    count = 1;
    r = row - 1;
    c = col + 1;
    while (r >= 0 && c < BOARD_SIZE && board[r][c] == player) { count++; r--; c++; }

    r = row + 1;
    c = col - 1;
    while (r < BOARD_SIZE && c >= 0 && board[r][c] == player) { count++; r++; c--; }


    if (count >= 5) return true;


    return false;
}

int omok() {
    system("mode con:cols=100 lines=40");

    printf("\033[0m");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);


    char board[BOARD_SIZE][BOARD_SIZE];
    int row, col;    // ����ڰ� �Է��� ��� ���� ��ġ��
    char currentPlayer = 'X'; // ���� �÷��̾�, X���� ����

    initializeBoard(board);
    printf("\033[0m");
    printf("\n\n�ºθ� �����ϰڽ��ϴ�!\n\n");
    printf("ù��° ����� X �ι�° ����� O�� �˴ϴ�.\n\n");
    printf("5���� �������� ���� �մ� ����� �¸��մϴ�.(����,����,�밢�� ���� �����մϴ�.) \n\n");

    while (true) {
        printBoard(board);


        printf("\n������ '%c'�� �����Դϴ�. \n\n", currentPlayer);
        printf("��� �� ��ȣ(0~%d)�� �������� �����Ͽ� �Է��ϼ���.: ", BOARD_SIZE - 1);

        scanf("%d %d", &row, &col);
        getchar();  // scanf �Լ� ���� �����ڿ� �����ʴ� �ܾ���� �� �Լ��� ȣǮ�Ͽ� ���๮�ڸ� ��������,


        system("cls");  // ȭ�� �����


        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != '.') {
            printf("�߸��� �ൿ�Դϴ�. �ٽ� ������ �ּ���.\n");
            continue;
        }

        board[row][col] = currentPlayer;  // ����ڰ� ������ ��ġ(row,col)�� currentPlayer(�÷��̾� X/0) ���� �Ҵ��ϴ°�. 

        if (checkWin(board, row, col, currentPlayer)) {
            printBoard(board);
            printf("\n\n            ������ '%c'�� �¸�!\n\n", currentPlayer);
            break;
        }


        // �÷��̾ ��ü�մϴ�.
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';


    }

    printf("            ����ּż� �����մϴ�.\n");
    while (1) {
        // Ű���� �Է��� �ִ��� Ȯ��
        if (_kbhit()) { _getch();  clear(); break; }
    }
    clear();


    return 0;
}