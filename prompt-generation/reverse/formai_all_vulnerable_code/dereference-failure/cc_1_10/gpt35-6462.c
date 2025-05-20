//FormAI DATASET v1.0 Category: HTML beautifier ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *inputFile;
    FILE *outputFile;

    inputFile = fopen("input.html", "r");

    if (inputFile == NULL)
    {
        printf("Error opening input file\n");
        exit(1);
    }

    outputFile = fopen("output.html", "w");

    if (outputFile == NULL)
    {
        printf("Error creating output file\n");
        exit(1);
    }

    char previous = '\0';
    char current;

    while ((current = fgetc(inputFile)) != EOF)
    {
        if (isspace(current) && previous == '\n')
        {
            continue;
        }

        fputc(current, outputFile);

        if (current == '>')
        {
            fputc('\n', outputFile);
        }

        previous = current;
    }

    printf("HTML code formatted successfully!");

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}