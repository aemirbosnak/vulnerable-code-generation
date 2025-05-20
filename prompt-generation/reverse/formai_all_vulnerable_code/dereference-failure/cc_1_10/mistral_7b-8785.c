//MISTRAL-7B DATASET v1.0 Category: File Synchronizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void readFile(FILE *file, char **lines, int *numLines) {
    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        lines[lineNumber] = malloc(strlen(line) + 1);
        strcpy(lines[lineNumber], line);
        lineNumber++;
        *numLines = lineNumber;
    }

    fclose(file);
}

void printDifferences(char *lineA, char *lineB) {
    if (strcmp(lineA, lineB) != 0) {
        printf("Line %d in fileA is different from fileB:\n", (int) (getLineNumber(lineA) + 1));
        printf("fileA: %s\n", lineA);
        printf("fileB: %s\n", lineB);
    }
}

int getLineNumber(char *line) {
    char *token;
    int lineNumber = 0;

    token = strtok(line, ":");
    while (token != NULL) {
        lineNumber++;
        token = strtok(NULL, ":");
    }

    return lineNumber;
}

int main() {
    FILE *fileA, *fileB;
    char *linesA = NULL, *linesB = NULL;
    int numLinesA = 0, numLinesB = 0;
    int i;

    fileA = fopen("fileA.txt", "r");
    readFile(fileA, &linesA, &numLinesA);

    fileB = fopen("fileB.txt", "r");
    readFile(fileB, &linesB, &numLinesB);

    if (numLinesA != numLinesB) {
        printf("Files have different number of lines.\n");
        exit(1);
    }

    for (i = 0; i < numLinesA; i++) {
        printDifferences(linesA[i], linesB[i]);
    }

    for (int j = 0; j < numLinesB; j++) {
        if (j >= numLinesA) {
            printf("Line %d in fileB is new.\n", j + 1);
        }
        free(linesB[j]);
    }

    for (int k = numLinesA; k < numLinesB; k++) {
        printf("Line %d in fileB is deleted.\n", k + 1 - numLinesA);
        free(linesB[k]);
    }

    for (int l = 0; l < numLinesA; l++) {
        free(linesA[l]);
    }
    free(linesA);
    free(linesB);
    fclose(fileA);
    fclose(fileB);

    return 0;
}