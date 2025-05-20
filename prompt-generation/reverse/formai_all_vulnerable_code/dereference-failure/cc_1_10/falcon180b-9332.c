//Falcon-180B DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

void my_error(char *str)
{
    fprintf(stderr, "Error: %s\n", str);
    exit(1);
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char line[MAX_LINE_SIZE];
    int count = 0;

    // Check for the correct number of arguments
    if (argc!= 3)
    {
        my_error("Incorrect number of arguments");
    }

    // Open the input file
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        my_error("Error opening file");
    }

    // Loop through each line in the file
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL)
    {
        // Check for the correct line format
        if (sscanf(line, "%d", &count)!= 1)
        {
            my_error("Invalid line format");
        }

        // Check for overflow
        if (count > 100)
        {
            my_error("Overflow error");
        }

        // Write the line to the output file
        fprintf(stdout, "%s", line);
    }

    // Close the input and output files
    fclose(fp);

    return 0;
}