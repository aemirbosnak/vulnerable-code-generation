//FormAI DATASET v1.0 Category: Log analysis ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void printHeader(char *filename)
{
    printf("***** Analyzing file: %s *****\n\n", filename);
}

void printFooter()
{
    printf("\n\n***** End of analysis *****\n");
}

void printLine(char *line)
{
    printf("Line: %s\n", line);
}

void printResult(int totalWarnings, int totalErrors)
{
    printf("\n\n***** Analysis Results *****\n\n");
    printf("Total Warnings: %d\n", totalWarnings);
    printf("Total Errors: %d\n", totalErrors);
}

int main(int argc, char *argv[])
{
    if (argc <= 1) {
        printf("Usage: %s [filename]\n", argv[0]);
        exit(1);
    }

    char filename[MAX_LINE_LENGTH];
    strcpy(filename, argv[1]);

    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open file: %s\n", filename);
        exit(1);
    }

    printHeader(filename);

    char line[MAX_LINE_LENGTH];
    int lineNum = 1;
    int totalWarnings = 0;
    int totalErrors = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char *posErrorMsg = strstr(line, "ERROR:");
        char *posWarnMsg = strstr(line, "WARNING:");

        if (posErrorMsg != NULL) {
            totalErrors++;
            printf("Line %d: ", lineNum);
            printLine(line);
        }

        if (posWarnMsg != NULL) {
            totalWarnings++;
            printf("Line %d: ", lineNum);
            printLine(line);
        }

        lineNum++;
    }

    fclose(fp);

    printFooter();

    printResult(totalWarnings, totalErrors);

    return 0;
}