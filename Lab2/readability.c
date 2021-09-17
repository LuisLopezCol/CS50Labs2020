#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //ask for the strimg
    string text = get_string("Text: ");
    int totalArray = strlen(text);
    float letters = 0;
    float words = 1; //to take into account the last word
    float sentences = 0;

    //Letters counter
    for(int i = 0; i < totalArray; i++)
    {
        if ((text[i] >=65 && text[i] <=90) || (text[i] >=97 && text[i] <=122))
        letters++;
    }
    //Words counter
    for(int i = 0; i < totalArray; i++)
    {
        if (text[i] == 32)
        words++;
    }
    //Setences counter
    for(int i = 0; i < totalArray; i++)
    {
        if (text[i] == 46 || text[i] == 33 ||text[i] == 63)
        sentences++;
    }
    //Coleman-Liau index
    float L = letters*100/words;
    float S = sentences*100/words;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //Compute grade"
    if (index < 1)
    {
        string grade = "Before Grade 1";
        printf("Grade %s\n", grade);
    }
    else if (index >16)
    {
        string grade = "16+";
        printf("Grade %s\n", grade);
    }
    else
    {
        int grade = index;
        printf("Grade %d\n", grade);
    }
    return 0;
}
