//Falcon2-11B DATASET v1.0 Category: Temperature Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 100

typedef struct {
    int lineNum;
    char* line;
} Line;

typedef struct {
    char* word;
    char* meaning;
} Word;

void readLines(Line** lines, int* numLines) {
    *numLines = 0;
    FILE* fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Could not open file\n");
        exit(1);
    }
    char buffer[MAX_LINE_LEN];
    while (fgets(buffer, MAX_LINE_LEN, fp)) {
        Line* line = (Line*)malloc(sizeof(Line));
        if (line == NULL) {
            printf("Out of memory\n");
            exit(1);
        }
        line->lineNum = *numLines;
        line->line = strdup(buffer);
        if (line->line == NULL) {
            printf("Out of memory\n");
            exit(1);
        }
        (*lines)->line = line;
        (*lines) = (*lines)->line;
        (*numLines)++;
    }
    fclose(fp);
}

void displayLine(Line* line) {
    printf("Line %d: %s\n", line->lineNum, line->line);
}

int main() {
    Line* lines = NULL;
    int numLines = 0;
    readLines(&lines, &numLines);
    for (int i = 0; i < numLines; i++) {
        displayLine(lines + i);
    }
    free(lines);
    return 0;
}