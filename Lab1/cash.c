#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    float change = 0;
    int coins = 0;

    //Ask the user how much change is owed
    while (isdigit(change) != 0 || change <= 0)
    {
    change = get_float("Change owed: ");
    }

    //Converting change to dollars
    change = round(change * 100);

    //Compute the number of coins requiered
    while (change >= 25)
    {
        coins++;
        change -= 25;
    }
    while (change >= 10)
    {
        coins++;
        change -= 10;
    }
    while (change >= 5)
    {
        coins++;
        change -= 5;
    }
    while (change >= 1)
    {
        coins++;
        change -= 1;
    }
    printf("%d\n", coins);

    return 0;
}