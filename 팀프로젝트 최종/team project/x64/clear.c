#include <stdio.h>
#include <Windows.h>

void clear() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   // �ܼ� â�� �ؽ�Ʈ ������ ����
    SetConsoleTextAttribute(hConsole, 0x0B); // ���� û�� �������� ����

    printf("\n\n\n\n");
    printf("             ########    ###         #########       ###       #########     ###\n");
    printf("            ###    ###   ###         ###           ##   ##     ###    ###    ###\n");
    printf("            ###          ###         ###          ###   ###    ###    ###    ###\n");
    printf("            ###          ###         #########   ###########   #########     ###\n");
    printf("            ###          ###         ###         ###     ###   ###   ###        \n");
    printf("            ###    ###   ###         ###         ###     ###   ###    ###    ###\n");
    printf("             ########    #########   #########   ###     ###   ###     ###   ###\n");


}
