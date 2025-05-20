//Falcon2-11B DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *infile, *outfile;

    char line[256];
    char *word = NULL;
    int numWords = 0, numChars = 0, numLines = 0;

    infile = fopen("input.txt", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "Could not open input file.\n");
        exit(1);
    }

    outfile = fopen("output.txt", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "Could not open output file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), infile))
    {
        // Remove leading and trailing whitespace from the line
        memset(line, 0, sizeof(line));
        line[strcspn(line, "\r\n")] = 0;

        // Count words in the line
        word = strtok(line, " \t\n");
        while (word!= NULL)
        {
            numWords++;
            word = strtok(NULL, " \t\n");
        }

        // Count characters in the line
        numChars += strlen(line);

        // Count lines in the file
        fgets(line, sizeof(line), infile);
        numLines++;
    }

    fclose(infile);
    fclose(outfile);

    // Print results to stdout
    printf("Number of words: %d\n", numWords);
    printf("Number of characters: %d\n", numChars);
    printf("Number of lines: %d\n", numLines);

    return 0;
}