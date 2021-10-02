#include <stdio.h>

void imprimirEspacios(int height, int i);
void imprimirNumerales(int height, int i);

int main()
{
    int height = 0;
    
    while(height <= 0 || height >= 9)
    {
        printf("Height: ");
        scanf("%d", &height);
    }
    
    for (int i = 1; i <= height; i++)
    {
        imprimirEspacios(height, i);
        imprimirNumerales(height, i);
        printf("  ");
        imprimirNumerales(height, i);
        printf("\n");
    }


    return 0;
}

void imprimirEspacios(int height, int i)
{
        //primer espacio
        for (int y = 1; y <= (height-i); y++)
        {
            printf(" ");
        }
}
void imprimirNumerales(int height, int i)
{
        //primer espacio
        for (int y = 1; y <= (i); y++)
        {
            printf("#");
        }
}