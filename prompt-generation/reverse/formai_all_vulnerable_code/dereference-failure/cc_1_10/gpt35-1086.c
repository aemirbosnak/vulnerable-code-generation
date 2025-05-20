//FormAI DATASET v1.0 Category: Compression algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *inputFile, char *outputFile);

int main()
{
    char inputFile[100], outputFile[100];
    
    printf("Enter the name of input file: ");
    scanf("%s",inputFile);
    
    printf("Enter the name of output file: ");
    scanf("%s",outputFile);
    
    compress(inputFile, outputFile);
    
    printf("File compressed successfully!\n");
    
    return 0;
}

void compress(char *inputFile, char *outputFile)
{
    FILE *input, *output;
    int count = 1;
    char prevChar, currChar;
    
    input = fopen(inputFile, "r");
    output = fopen(outputFile, "w");
    
    if(input == NULL || output == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    
    prevChar = fgetc(input);
    
    while(prevChar != EOF)
    {
        currChar = fgetc(input);
        
        if(currChar == prevChar)
        {
            count++;
        }
        else
        {
            fprintf(output, "%d%c", count, prevChar);
            count = 1;
            prevChar = currChar;
        }
    }
    
    fclose(input);
    fclose(output);
}