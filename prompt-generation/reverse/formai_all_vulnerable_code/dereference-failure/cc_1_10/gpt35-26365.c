//FormAI DATASET v1.0 Category: Text processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
This program processes a text file by removing all vowels from each word inside the file.
*/

char* removeVowels(char* input)
{
    char* output;
    int i, j;

    output = (char*)malloc(sizeof(char) * strlen(input));
    strcpy(output, input);

    for(i = j = 0; input[i] != '\0'; i++)
    {
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U')
            continue;

        output[j++] = input[i];
    }

    output[j] = '\0';

    return output;
}

int main()
{
    FILE *inFile, *outFile;
    char inFileName[50], outFileName[50];
    char word[50], c;

    printf("Enter input file name: ");
    scanf("%s", inFileName);

    printf("Enter output file name: ");
    scanf("%s", outFileName);

    inFile = fopen(inFileName, "r");
    outFile = fopen(outFileName, "w");

    if(inFile == NULL)
    {
        printf("Error! Unable to open input file.");
        exit(1);
    }

    while((c = fgetc(inFile)) != EOF)
    {
        if(c == ' ' || c == '\n')
        {
            word[strlen(word)] = '\0';
            fprintf(outFile, "%s ", removeVowels(word));
            memset(&word[0], 0, sizeof(word));
        }
        else
        {
            strncat(word, &c, 1);
        }
    }

    fclose(inFile);
    fclose(outFile);

    return 0;
}