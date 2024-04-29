#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 6  // �ִ� �õ� Ƚ��
#define MAX_WORD_LEN 20  // �ִ� �ܾ� ����

// �ܾ� ���
char* words[] = { "hello" };  // ���ڿ� ������ �迭
int num_words = 1; // �ϳ��� �ܾ ���ԵǾ� ������ �ǹ�

// ��� �׸� ��� 
void printHangman(int tries);  // tries : ����ڰ� ������� Ʋ�� Ƚ��

int hanghang() {  // ������ ��ȯ�ϴ� ���� -> ��� ������ ������ ���
    printf("\033[0m");      // ���� ���� ����
    // srand  : �Լ��� ȣ���Ͽ� �õ�(seed)�� ����
    srand(time(NULL)); // ������ ���� �����ϱ� ���� ��� -> ���� �ð��� ������� �õ带 ����

    char guess[MAX_WORD_LEN];  // ����ڰ� ������ �ܾ�
    char word[MAX_WORD_LEN];  // ���ӿ��� ���õ� �ܾ�
    int wordIndex, wordLen, i; // �ܾ� ��Ͽ��� ���õ� �ܾ��� �ε���, ���õ� �ܾ��� ����
    int tries = 0;  // ������ ���� Ƚ��
    int found;  // �Է��� ���ڰ� �ܾ ���� ����
    char letter;  // �Է��� ����
    char guessedLetters[MAX_WORD_LEN] = "";  // �̹� �õ��� ����

    // �ܾ� ���� ����
    wordIndex = rand() % num_words; // rand() : �����ϰ� �ܾ ����
    strcpy(word, words[wordIndex]); // strcpy �Լ��� ����Ͽ� ���õ� �ܾ word�� ����, wordIndex �� ����
    wordLen = strlen(word); // ���õ� �ܾ��� ���̸� ���

    // guess �迭�� �ʱ�ȭ
    for (i = 0; i < wordLen; i++) // wordLen ������ ����� �ܾ��� ���̸�ŭ �ݺ��ϸ鼭 
        guess[i] = '_'; // guess �迭�� �� ��Ҹ� ������ھ�(_)�� �ʱ�ȭ
    guess[wordLen] = '\0'; // �� ���Ṯ�� -> ���ڿ��� ��

    printf("\n\n����� �����մϴ�.\n");

    while (tries < MAX_TRIES) {
        printf("\n�Է��� ���縵 ����: %s\n\n", guess);  // guess �迭�� ����� ����ǥ��
        printf("�Է��� ���縵: ");
        scanf(" %c", &letter);

        if (strchr(guessedLetters, letter) != NULL) {  // // �̹� �õ��� ���� �Է��� ��� guessedLetters �迭���� Ȯ��
            printf("�̹� �õ��� �����Դϴ�. �ٸ� ���ڸ� �Է����ּ���.\n");
            continue;
        }
        guessedLetters[strlen(guessedLetters)] = letter; // ����ڰ� �Է��� ���ڸ� guessedLetters �迭�� �߰�
        guessedLetters[strlen(guessedLetters)] = '\0'; // �� ���Ṯ�ڷ� �迭�� ���� �ν�

        found = 0;  // ������ 0���� �ʱ�ȭ -> �Է��� ���ڰ� �ܾ ���� ���� Ȯ������
        for (i = 0; i < wordLen; i++) {
            if (word[i] == letter) { // �Է±��ڿ� �ܾ� ��ġ���� Ȯ��
                guess[i] = letter;  // ��ġ�Ѵٸ� guess�迭�� ��������
                found = 1; // �ùٸ� ���� True
            }
        }

        if (!found) {  // �Է±��ڰ� ���Ե������� ��� 
            tries++; // Ʋ�� Ƚ�� ����
            system("cls");
            //�ִ� �õ� Ƚ������ ���� �õ� Ƚ���� �� ���� ���
            printf("\n\nƲ�Ƚ��ϴ�! ���� �Է� ��ȸ : %d\n", MAX_TRIES - tries);
            // ���� �õ� Ƚ���� ���� ��� �׸��� ���
            printHangman(tries);
        }
        else {
            system("cls");
            printf("\n\n�¾ҽ��ϴ�!\n");
            // ���� �õ� Ƚ���� ���� ��� �׸��� ���
            printHangman(tries);
        }

        // ��� ���ڸ� ���� ���
        if (strcmp(word, guess) == 0) {  // strcmp �Լ��� ����Ͽ� word�� guess�� ��
            system("cls");
            printf("\n\n\n�����մϴ�! �ϼ��� �ܾ�: %s\n", word);
            clear();
            break;
        }
    }

    // �õ� ������ Ƚ���� ��� ����� ���
    if (tries == MAX_TRIES) { // ���� �õ��� Ƚ�� = �ִ� �õ� Ƚ������ Ȯ��
        system("cls");
        printf("\n\n�ܾ�� %s �����ϴ�.\n", word);
        // ���� �õ� Ƚ���� ���� ��� �׸��� ���
        printHangman(tries);
        over();
    }


}

void printHangman(int tries) {
    switch (tries) {  // �õ�Ƚ���� �������� ����
        // �õ� Ƚ���� ���� �׸� ���
    case 0:
        printf("      ______\n");
        printf("     |      |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        break;
    case 1:
        printf("      ______\n");
        printf("     |      |\n");
        printf("   /\\_/\\    |\n");
        printf("  ( o.o )   |\n");
        printf("   >   <    |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        break;
    case 2:
        printf("      ______\n");
        printf("     |      |\n");
        printf("   /\\_/\\    |\n");
        printf("  ( o.o )   |\n");
        printf("   >   <    |\n");
        printf(" /          |\n");
        printf("/_/         |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        break;
    case 3:
        printf("      ______\n");
        printf("     |      |\n");
        printf("   /\\_/\\    |\n");
        printf("  ( o.o )   |\n");
        printf("   >   <    |\n");
        printf(" /          |\n");
        printf("/_/|   |    |\n");
        printf("   |   |    |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        break;
    case 4:
        printf("      ______\n");
        printf("     |      |\n");
        printf("   /\\_/\\    |\n");
        printf("  ( o.o )   |\n");
        printf("   >   <    |\n");
        printf(" /       \\  |\n");
        printf("/_/|   |\\_\\\ |\n");
        printf("   |   |    |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        printf("            |\n");
        break;
    case 5:
        printf("      ______\n");
        printf("     |      |\n");
        printf("   /\\_/\\    |\n");
        printf("  ( o.o )   |\n");
        printf("   >   <    |\n");
        printf(" /       \\  |\n");
        printf("/_/|   |\\_\\\ |\n");
        printf("   |   |    |\n");
        printf("  / __      |\n");
        printf(" /_/        |\n");
        printf("            |\n");
        printf("            |\n");
        break;
    case 6:
        printf("      ______\n");
        printf("     |      |\n");
        printf("   /\\_/\\    |\n");
        printf("  ( o.o )   |\n");
        printf("   >   <    |\n");
        printf(" /       \\  |\n");
        printf("/_/|   |\\_\\\ |\n");
        printf("   |   |    |\n");
        printf("  / ___ \\   |\n");
        printf(" /_/   \\_\\  |\n");
        printf("            |\n");
        printf("            |\n");
        break;
    default:  // case�� �ش����� �ʴ� ���
        printf("\n");
        break;
    }
}