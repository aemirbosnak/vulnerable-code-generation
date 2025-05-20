//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000

// Function to read a line from the file
char* readLine(FILE* file) {
    char* line = (char*) malloc(MAX_LINE_LENGTH);
    fgets(line, MAX_LINE_LENGTH, file);
    return line;
}

// Function to read the file and store it in an array of lines
char** readFile(char* filename, int* numLines) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char** lines = (char**) malloc(MAX_LINES * sizeof(char*));
    int lineCount = 0;

    while ((lines[lineCount] = readLine(file))!= NULL) {
        lineCount++;
    }

    *numLines = lineCount;
    fclose(file);

    return lines;
}

// Function to print the lines of the file with line numbers
void printFile(char** lines, int numLines) {
    for (int i = 0; i < numLines; i++) {
        printf("%d: %s", i+1, lines[i]);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    int numLines;
    char** lines = readFile(filename, &numLines);
    printFile(lines, numLines);

    for (int i = 0; i < numLines; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}