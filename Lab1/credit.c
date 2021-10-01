#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
//***Prompt the user to type the card number and Check if it's a valid card
    long cardNumber = get_long("Number: ");
    while (cardNumber <= 0) //Check if the user prompted a negative number, if so, ask him again
    {
    cardNumber = get_long("Number: ");
    }

//***Compute the amount of digits
    long tempCard1 = cardNumber; //New varaible created to not affect the original Card number
    int count = 1;
    while (tempCard1 > 10)
    {
        tempCard1 = round(tempCard1/10);
        count++;
    }

//***Validate if the Luhn’s Algorithm is applied
    long tempCard2 = cardNumber;//New varaible created to not affect the original Card number
    int checkSum = 0;
    for (int i = 0; i < count; )
    {
    //First digit must be added with no change
        long temp = 0;
        if(i < count) //To ensure to not touch forbidden memory
        {
            temp = tempCard2 % 10;
            checkSum += (int)temp;
            tempCard2 /= 10;
            i++;
        }
    //Second digit must be multiplied by 2 and then added as per CS50 requiered
        temp = tempCard2 % 10;
        long tempSum = temp * 2;
        if (tempSum >= 10)//If greater than 10, each digit must be added appart
        {
            checkSum += (int)tempSum / 10;
            checkSum += (int)tempSum % 10;
        }
        else
        {
            checkSum += (int)tempSum; //If less than 10, the whole number can be added
        }
        tempCard2 /= 10;
        i++;
    //Then repeat the process for the rest of the digits
    }
    //After compute the final sum, check if the last digit is 0 in order to see if the algorithm is applied
        if ((checkSum % 10) != 0)//If greater than 10, each digit must be added appart
        {
            printf("INVALID\n");
            return 0;
        }

//***Check which creditor is it and then check if the credit card is valid with the first digits
    if (count == 15)
    {
        long AMEX = cardNumber;
        for (int i = 0; i < (count - 2); i++) //To check only the first two numbers
        {
           AMEX = AMEX/10;
        }
        if(AMEX == 34 || AMEX == 37)
        {
        printf("AMEX\n");
        return 0;
        }
    }

    if (count == 16)
    {
        long MC = cardNumber;
        for (int i = 0; i < (count - 2); i++) //To check only the first two numbers
        {
           MC = MC/10;
        }
        if(MC >= 51 && MC <= 55)
        {
        printf("MASTERCARD\n");
        return 0;
        }
    }

    if (count == 13 || count == 16)
    {
        long VISA = cardNumber;
        for (int i = 0; i < (count - 1); i++) //To check only the first two numbers
        {
           VISA = VISA/10;
        }
        if(VISA == 4)
        {
        printf("VISA\n");
        return 0;
        }
    }
        printf("INVALID\n");
        return 0;
}