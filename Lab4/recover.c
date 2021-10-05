#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //Check command-line arguments && Open file for reading
    if (argc != 2)
    {
        printf("./recover card.raw");
        return 1;
    }

    FILE* raw = fopen(argv[1], "r");
    if (raw == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }

    unsigned char buffer[BLOCK_SIZE]; //You can also use uint8_t, also, u can create a typedef
    int filecount = 0; //To count the pictures
    FILE *output = NULL; //Pointer to the chunl of memory to store the data
    bool new_picture = false;
    char *filename = malloc(8 * sizeof(char)); //or char filename[8]; yo can use both.

    //Read the memory in chunks of 512 Bytes then check if it´s the beggining of a new pic
    while (fread(buffer, sizeof(char), BLOCK_SIZE, raw))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (new_picture) //We have found one new pic, so, close the last one
            {
                fclose(output);
            }
            else //Otherwise this is a new pic, we can start writing
            {
                new_picture = true;
            }
        
        //Name the new pic
        sprintf(filename, "%03d.jpg", filecount);
        output = fopen(filename, "a");
        filecount++;
        }
        
        if (output != NULL) //It`s not a new pic and also the memory is not NULL
        {
            fwrite(buffer, sizeof(char), BLOCK_SIZE, output);
        }
    }

    // Close files
    free(filename);
    fclose(raw);
    fclose(output);
}
