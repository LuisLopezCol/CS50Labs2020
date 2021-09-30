#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //Check if the user prompts ./caesar and the key
    if (argc != 2)
    {
        printf("Need to type \"./Caesar\" and then the \"key\" in numbers\n");
        return 1;
    }

    //Check if all characters in the key are numbers
    string s = argv[1];
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        char c = s[i];
        if (isalpha(c))
        {
            printf("The key must be a number\n");
            return 1;
        }
    }

    //Check if the key is valid > than 0
    int key = atoi(argv[1]);
    if (key < 0)
    {
        printf("The key most be greater than 0\n");
        return 1;
    }

    //Prompt the user to input the plaintext
    string plaintext = get_string("plaintext: ");
    int n = strlen(plaintext);

    //Cipher each letter
    printf("ciphertext: ");
    for (int i = 0; i < n; i++)
    {
        char ch = plaintext[i];
        if (isalpha(ch) == 0)
        {
            printf("%c", ch);
        }
        else if (isupper(ch) != 0)
        {
            char temp = ((ch - 65) + key) % 26 + 65;
            printf("%c", temp);
        }
        else
        {
            char temp = (ch - 97 + key) % 26 + 97;
            printf("%c", temp);
        }
    }
    printf("\n");
    return 0;
}