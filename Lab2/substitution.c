#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char const *argv[])
{

    //Validate that the user inputs one key
    if(argc != 2)
    {
        printf("Hey! we need one single key, make sure to type one (1) key after ./substitution in the Terminal and this key is not divided by spaces :)\n");
        return 1;
    }

    //Validate the key is 26 characters
    int argvlen = strlen(argv[1]); 
    if(argvlen != 26)
    {
        printf("Hey! the key must have 26 charecters/letters, bye.\n");
        return 1;
    }

    //Validate all characters are letters
    for(int i = 0; i < argvlen; i++)
    {
        char character = argv[1][i]; //I created this since isalpha needs a char or an int, take into account that argv[i] does not work becuase is a string
        if(isalpha(character) == 0)
        {
            printf("Hey, the key must have just letters!, bye.\n");
            return 1;
        }
    }

    //Validate none characters are repeated in the key
    for(int i = 0; i < argvlen; i++)
    {
        for(int y = 1; y < argvlen; y++)
        {
            if(i != y)
            {
                if(toupper(argv[1][i]) == toupper(argv[1][y])) //To upper in order to compare lower and upper
                {
                    return 1;
                }
            }
        }
    }

    //Ask for the plain text and calculate the lenght
    string plaintext = get_string("plaintext: ");
    int pltlen = strlen(plaintext);

    //Print the ciphertext
    printf("ciphertext: ");
    for(int x = 0; x < pltlen; x++)
    {
        int lct = 0;
        if(isupper((int) plaintext[x]) != 0) //If upper, print upper
        {
            int temp2 = plaintext[x];
            lct = temp2 - 65;
            printf("%c", toupper(argv[1][lct]));
        }
        else if((int) islower(plaintext[x]) != 0) //If lower print lower
        {
            int temp2 = plaintext[x];
            lct = temp2 - 97;
            printf("%c", tolower(argv[1][lct]));
        }
        else
        {
            printf("%c", plaintext[x]);
        }
    }

    //End of the program
    printf("\n");
    return 0;
}