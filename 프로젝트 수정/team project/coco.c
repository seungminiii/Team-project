#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define COCO_X 0
#define COCO_Y 15
#define TREE_X 90
#define TREE_Y 25
#define 지렁_X 90
#define 지렁_Y 25
#define STONE_X 125
#define STONE_Y 17
#define COCO_BENT_X COCO_X                   // 닭 눕방
#define COCO_BENT_Y (COCO_Y + 6)





void setting();               // 커서이동, 콘솔창 설정
// void gotoxy(int x, int y);   
void start();
int game(int);
void scc(int);
int crashing();
void end(int);
void 지렁(int);                  // 지렁그리기
void 지렁1();                 //지렁지우기


//닭 관련 함수
void draw_coco(int);          // 닭그리기
void erase_coco();           // 닭지우기
void earase_foot();           // 발지우기
void draw_bent_coco(); // 숙이기 모션 그리기 함수
//void erase_bent_coco(); // 숙이기 모션 지우기 함수


//나무 관련 함수
void tree();                  //나무 오른쪽에서 왼쪽으로 이동시키는 함수
void draw_tree();            // 나무그리기
void erase_tree();           // 나무지우기


// 
void draw_stone(); // 돌 그리기 함수
void erase_stone(); // 돌 지우기 함수
void stone(); // 돌 이동 함수



int 지렁X = 지렁_X;
int treeX = TREE_X;
int cocoX = COCO_X;
int cocoY = COCO_Y;
int stoneX = STONE_X;
int bentX = COCO_BENT_X;




// 고개 숙이기
int isBent = 0; // 숙이기 여부를 나타내는 변수
int key = 0; //키보드 입력 받기


int coco()
{
    int tic = 0; //게임 내 시간 단위이자 점수 결정 요소
    int crash = 0; //충돌 체크

    setting();
    start();

    while (1) {

        tic = game(tic);

        //'스페이스 바' 누르면 점프
        if (_kbhit()) {
            key = _getch();
            if (key == 32 && cocoY - 15 == 0) { //'스페이스 바'가 눌리고 닭이 바닥에 있을 때

                int h = 0; //점프 높이 초기화

                while (h < 9) { //y축으로 8칸 상승 == 점프높이
                    erase_coco();
                    cocoY--;
                    tic = game(tic);
                    crash = crashing();
                    if (crash == -1)
                        break;
                    h++;
                }

                while (h > 0) { //y축으로 8칸 하강
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
        if (crash == -1) //충돌 시 탈출
            break;

    }

    end(tic);

    system("pause>>null");
    return 0;
}
int game(int tic) { //게임화면 메인 요소
    scc(tic);
    tree();
    draw_coco(tic);
    지렁(tic);
    stone();

    Sleep(20); //0.02초      //딜레이 예상
    tic++;

    return tic;
}

int crashing() { //충돌 판정   //난이도 '하'
    // (가로1 && 가로2) && 세로
    // 가로1: 나무가 가로 11칸보다 뒤에 있음
    // 가로2: 나무가 가로 15칸보다 앞에 있음
    // 가로1 && 가로2: 나무가 가로 11칸과 15칸 사이에 있음
    // 세로: 닭 발 3칸이 나무 5칸 보다 높이가 같거나 낮을 때
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

    //몸통 그리기
    gotoxy(cocoX, cocoY);         printf("\n");
    gotoxy(cocoX, cocoY + 1);      printf("          ■■■■\n");
    gotoxy(cocoX, cocoY + 2);      printf("          ■■■■■\n");
    gotoxy(cocoX, cocoY + 3);      printf("          ■■■■■\n");
    gotoxy(cocoX, cocoY + 4);      printf("         ■         ■\n");
    gotoxy(cocoX, cocoY + 5);      printf("       ■             ■\n");
    gotoxy(cocoX, cocoY + 6);      printf("  ■■■     ■    ■ ■\n");
    gotoxy(cocoX, cocoY + 7);      printf("  ■  ■       ■■■ ■\n");
    gotoxy(cocoX, cocoY + 8);      printf("  ■                  ■\n");
    gotoxy(cocoX, cocoY + 9);      printf("  ■                  ■\n");
    gotoxy(cocoX, cocoY + 10);      printf("    ■                ■\n");
    gotoxy(cocoX, cocoY + 11);      printf("      ■             ■\n");
    gotoxy(cocoX, cocoY + 12);      printf("        ■■ ■■ ■\n");

    // 숙이는 모션
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
        gotoxy(cocoX, cocoY + 10);      printf("   ■■■■■■■     \n");
        gotoxy(cocoX, cocoY + 11);      printf(" ■■■■■■■■■■ \n");
        gotoxy(cocoX, cocoY + 12);      printf(" ■■■■■■■■■■ \n");
        gotoxy(cocoX, cocoY + 13);      printf("   ■■■■■■■     \n");
        isBent = 1;
    }
    else {
        if (isBent) {
            erase_coco();
            isBent = 0;
        }
    }


    //발 구르기 구현
    if (toc >= 0 && toc <= 3) { // 4 tic 동안 유지
        earase_foot();
        gotoxy(cocoX, cocoY + 13); //발 그리기
        printf("           ■\n");
    }
    else if (toc >= 0 && toc <= 5) {
        earase_foot();
        gotoxy(cocoX, cocoY + 13); //발 그리기
        printf("                ■\n");
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



void 지렁(int tic) { //지렁이 그리기---------------------------------------------------------------------------------------------------지렁이

    int toc = tic % 8;

    //발 구르기 구현
    if (toc >= 0 && toc <= 3) //4tic 동안 유지
    {
        지렁1();
        gotoxy(지렁X, 지렁_Y + 1);  printf("       ■■      \n");
        gotoxy(지렁X, 지렁_Y + 2);  printf("    ■      ■   \n");
        gotoxy(지렁X, 지렁_Y + 3);  printf("■■          ■ \n");
    }
    else
    {
        지렁1();
        gotoxy(지렁X, 지렁_Y + 1);  printf("                 \n");
        gotoxy(지렁X, 지렁_Y + 2);  printf("                 \n");
        gotoxy(지렁X, 지렁_Y + 3);  printf("■■■■■■■■ \n");

    }
}

void 지렁1() { //발 지우기
    gotoxy(지렁X, 6);
    printf("                                             \n");
    printf("                                             \n");
    printf("                                               ");
}
void 지렁2() { //발 지우기
    gotoxy(지렁X, 6);
    printf("                                             \n");
    printf("                                             \n");
    printf("                                               ");
}



//------------------------------------------------------------------------------------------------------------------------------------------



void draw_tree() { //나무 그리기--------------------------------------------------------------------------------------------------------draw_tree
    gotoxy(treeX + 2, TREE_Y);         printf(" ■■\n");
    gotoxy(treeX, TREE_Y + 1);        printf("■ ■■ ■\n");
    gotoxy(treeX, TREE_Y + 2);        printf("■■■■■\n");
    gotoxy(treeX + 2, TREE_Y + 3);      printf(" ■■\n");
    gotoxy(treeX + 2, TREE_Y + 4);      printf(" ■■");
}

void erase_tree() { //나무 지우기
    gotoxy(treeX + 3, TREE_Y);        printf("     \n");
    gotoxy(treeX + 1, TREE_Y + 1);   printf("          \n");
    gotoxy(treeX + 1, TREE_Y + 2);   printf("          \n");
    gotoxy(treeX + 3, TREE_Y + 3);     printf("     \n");
    gotoxy(treeX + 3, TREE_Y + 4);      printf("     ");
}

void tree() { //나무 오른쪽에서 왼쪽으로 이동
    treeX--; //왼쪽으로 한 칸 이동
    erase_tree(); //지우고
    draw_tree(); //그리기

    if (treeX == 0)
        treeX = TREE_X; //나무가 왼쪽 끝으로 이동하면 초기화
}

// 돌그리기
void draw_stone() {
    gotoxy(stoneX + 1, STONE_Y); printf("▲▲▲▲");
}

void erase_stone() {
    gotoxy(stoneX + 1, STONE_Y); printf("           ");
}

void stone() {

    stoneX--;
    erase_stone();
    draw_stone();

    if (stoneX == 0)
        stoneX = STONE_X; // 화면을 벗어나면 초기 위치로 이동
}



void gotoxy(int x, int y) //----------------------------------------------------------------------------------------------------------gotoxy 
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setting() {  // ----------------------------------------------------------------------------------------------------------------setting
    //콘솔창 설정
    system("title Jumping coco by.woo");
    system("mode con:cols=150 lines=30");

    //커서 설정
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.dwSize = 1;
    ConsoleCursor.bVisible = 0; //커서 숨김
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void start() { //시작 화면
    while (1) {
        gotoxy(30, 10);
        printf("Press 'Space bar' to start the game");
        draw_coco(0);

        if (_kbhit()) {
            key = _getch();
            if (key == 32) { //'스페이스 바' 입력 확인
                system("cls");
                break;
            }
        }
    }
}

void scc(int tic) { //점수 출력
    gotoxy(45, 1);
    printf("score : %4d", tic / 5 * 10); // tic/5 당 10점      //필드 폭 4칸 확보 (n천점까지)
}

void end(int tic) { //엔딩 화면
    system("cls");
    over();

    gotoxy(40, 20);
    printf("final score : %4d", tic / 5 * 10); //최종 점수
}