#include <stdio.h>
#include <cs50.h>

void imprimirNumerales(int height, int i);

int main()
{
    int height = 0;
    while(height <= 0 || height > 8)
    {
        height = get_int("Height: ");
    }

    for (int i = 1; i <= height; i++)
    {
        for (int y = 1; y <= (height-i); y++)
        {
            printf(" ");
        }
        for (int y = 1; y <= (i); y++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
