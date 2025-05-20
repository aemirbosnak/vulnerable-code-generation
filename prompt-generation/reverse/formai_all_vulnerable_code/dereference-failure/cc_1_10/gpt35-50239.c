//FormAI DATASET v1.0 Category: Text processing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Declare Functions
int my_toupper(int c);
int my_tolower(int c);

//Main Program
int main()
{
    FILE *fpIn, *fpOut;
    char c;
    int option, i;
    char fileName[20];

    printf("Enter the name of the file to process (including extension): ");
    scanf("%s", fileName);

    fpIn = fopen(fileName, "r");
    if (fpIn == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    fpOut = fopen("output.txt", "w");
    if (fpOut == NULL)
    {
        printf("Error creating output file!\n");
        return 1;
    }

    // Display menu
    printf("Please select an option:\n");
    printf("1 - Convert all text to uppercase\n");
    printf("2 - Convert all text to lowercase\n");
    scanf("%d", &option);

    // Process text based on selected option
    i = 0;
    while ((c = fgetc(fpIn)) != EOF)
    {
        if (option == 1)
            fputc(my_toupper(c), fpOut);
        else if (option == 2)
            fputc(my_tolower(c), fpOut);
        i++;
    }

    // Print Success Message
    printf("%d characters have been processed.", i);

    fclose(fpIn);
    fclose(fpOut);

    return 0;
}

// Functions Implementation
int my_toupper(int c)
{
    if (islower(c))
        return c - 32;
    else
        return c;
}

int my_tolower(int c)
{
    if (isupper(c))
        return c + 32;
    else
        return c;
}