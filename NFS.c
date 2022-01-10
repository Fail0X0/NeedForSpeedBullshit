#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define width 51
#define length 30

void ausgabe(char arr[length][width])
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c", arr[i][j]);
        }
    }
}

void create(char arr[length][width])
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            arr[i][j] = '-';

            if (j + 1 == width)
                arr[i][j] = '\n';
        }
    }
}

int main()
{
    char chr;
    char arr[length][width];
    char cursor = 'A';
    int x = length / 2;
    int y = width / 2;

    for (int i = 0; i < 400; i++)
    {

        printf("use w,a,s,d to drive and l to leave the game.\n\n");
        create(&arr);
        arr[x][y] = cursor;
        ausgabe(&arr);

        scanf("%c", &chr);
        system("cls");
        arr[x][y] = '-';

        switch (chr)
        {
        case 'w':
        {
            if (x > 0)
                x--;
            break;
        }
        case 's':
        {
            if (x < length - 1)
                x++;
            break;
        }
        case 'a':
        {
            if (y > 0)
                y--;
            break;
        }
        case 'd':
        {
            if (y < width - 2)
                y++;
            break;
        }
        case 'l':
        {
            return 1;
            break;
        }
        default:
        {
            break;
        }
        }
    }
    return 0;
}