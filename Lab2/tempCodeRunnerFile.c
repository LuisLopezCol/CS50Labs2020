scrabble.c

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main (void)
{
// Get input from players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    printf ("Score Player 1: %d\n", compute_score(word1));
    printf ("Score Player 2: %d\n", compute_score(word2));

    if (compute_score(word1)<compute_score(word2))
    {
        printf ("Player 2 wins!!!\n");
    }
    else if (compute_score(word1)>compute_score(word2))
    {
        printf ("Player 1 wins!!!\n");
    }
    else
        printf ("Tied:\n");

    return 0;
}

int compute_score(string word)
{
    int locationLow = 97, locationCap = 65, Total = 0;
    int ii = strlen(word);
    for (int i = 0; i < ii; i++)
    {
        if (islower(word[i]) && word[i] <= 122 && word[i] >= 97)
        {
            Total += POINTS[(int)word[i]-locationLow];
        }
        else if (word[i] <= 90 && word[i] >= 65)
            Total += POINTS[(int)word[i]-locationCap];
    }
    return Total;
}
