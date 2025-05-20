//FormAI DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printTabs(int numOfTabs);
void printStringUntil(char* str, char delimiter);
int getNextLine(char** lines, int currentLine, int linesCount);
void tabify(char** lines, int linesCount);

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    char* fileName = argv[1];
    FILE* file = fopen(fileName, "r");
    if(file == NULL) {
        printf("%s: No such file or directory\n", fileName);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* fileContent = malloc(fileSize + 1);
    fread(fileContent, fileSize, 1, file);
    fileContent[fileSize] = 0;
    fclose(file);

    char* line = strtok(fileContent, "\n");
    char** lines = NULL;
    int linesCount = 0;
    while(line != NULL) {
        linesCount++;
        lines = realloc(lines, linesCount * sizeof(*lines));
        lines[linesCount - 1] = line;
        line = strtok(NULL, "\n");
    }

    tabify(lines, linesCount);

    for(int i = 0; i < linesCount; i++) {
        printf("%s\n", lines[i]);
    }

    free(lines);
}

void printTabs(int numOfTabs) {
    for(int i = 0; i < numOfTabs; i++) {
        printf("\t");
    }
}

void printStringUntil(char* str, char delimiter) {
    for(int i = 0; str[i] != delimiter && str[i] != 0; i++) {
        printf("%c", str[i]);
    }
}

int getNextLine(char** lines, int currentLine, int linesCount) {
    for(int i = currentLine + 1; i < linesCount; i++) {
        if(strlen(lines[i]) > 0) {
            return i;
        }
    }

    return -1;
}

void tabify(char** lines, int linesCount) {
    int numberOfTabs = 0;
    for(int i = 0; i < linesCount; i++) {
        for(int j = 0; j < strlen(lines[i]); j++) {
            if(lines[i][j] == '<') {
                if(lines[i][j + 1] != '/') {
                    printTabs(numberOfTabs);
                    printf("%c", lines[i][j]);
                    if(lines[i][j + 1] != ' ') {
                        printf("\n");
                        numberOfTabs++;
                        printTabs(numberOfTabs);
                    }
                }
                else {
                    numberOfTabs--;
                    printTabs(numberOfTabs);
                    printf("%c", lines[i][j]);
                }
            }
            else if(lines[i][j] == '>') {
                printf("%c", lines[i][j]);
                if(j < strlen(lines[i]) - 1 && lines[i][j + 1] != '<') {
                    printf("\n");
                    printTabs(numberOfTabs);
                }
            }
            else {
                printf("%c", lines[i][j]);
            }

            if(j == strlen(lines[i]) - 1 && lines[i][j] != '>') {
                int nextLine = getNextLine(lines, i, linesCount);
                if(nextLine != -1 && lines[nextLine][0] == '<') {
                    printf("\n");
                    numberOfTabs++;
                    printTabs(numberOfTabs);
                }
            }
        }
        printf("\n");
    }
}