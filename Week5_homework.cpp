#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void draw(int a[30][30])
{
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (a[i][j] == 0)//아직안열림
                printf("■");
            else if (a[i][j] == 1)//지뢰임
                printf("※");
            else if (a[i][j] == 2)//맞음
                printf("●");
        }
        printf("\n");
    }
}

int main()
{
    int map[30][30];
    int hide[30][30];
    srand((unsigned)time(NULL));
    int a, b, c, d, k;
    for (int i = 0; i < 30; i++)//배열 모든값 0으로 해줌
    {
        for (int j = 0; j < 30; j++)
        {
            map[i][j] = 0;
            hide[i][j] = 0;
        }
    }
    printf("생성할 지뢰개수를 입력해주세요(30x30)\n");
    scanf_s("%d", &k);
    for (int i = 0; i < k; i++)//지뢰생성
    {

        while (1)
        {
            a = rand() % 30;
            b = rand() % 30;
            if (map[a][b] == 1)
                ;
            else
            {
                map[a][b] = 1;
                break;
            }
        }

        map[a][b] = 1;

    }
    while (1)
    {
        draw(hide);
        printf("x좌표입력: ");
        scanf_s("%d", &c);
        printf("y좌표입력: ");
        scanf_s("%d", &d);

        c--;
        d--;

        if (c >= 30 || d >= 30 || c < 0 || d < 0)
        {
            printf("범위안의 숫자를입력해주세요\n");
            Sleep(1000);
        }
        else if (map[c][d] == 1)
        {
            hide[c][d] = 1;
            system("cls");
            draw(hide);
            printf("꽝입니다~ㅠㅠ\n");
            Sleep(2000);
            break;
        }
        else if (hide[c][d] == 2)
        {
            printf("이미 방문했습니다^^\n");
        }
        else if (map[c][d] == 0)
        {
            printf("맞았습니다~^^\n");
            hide[c][d] = 2;
        }

        Sleep(1000);
        system("cls");
    }
    printf("지뢰위치\n");
    draw(map);//게임 끝난후 지뢰위치 보여줌
}