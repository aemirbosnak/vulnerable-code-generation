//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

/* Function to read a line from the file */
char* readLine(FILE* file) {
    char* line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    fgets(line, MAX_LINE_LENGTH, file);
    return line;
}

/* Function to count the number of words in a string */
int countWords(char* str) {
    int count = 0;
    char* word = strtok(str, " \t\n\r\f\v");

    while (word!= NULL) {
        count++;
        word = strtok(NULL, " \t\n\r\f\v");
    }

    return count;
}

/* Function to print a formatted line of text */
void printLine(char* line, int lineNumber) {
    int wordCount = countWords(line);
    int wordSpacing = (MAX_LINE_LENGTH - wordCount * 2) / wordCount;

    printf("%d: ", lineNumber);

    char* word = strtok(line, " \t\n\r\f\v");
    while (word!= NULL) {
        printf("%s ", word);
        for (int i = strlen(word); i < wordSpacing; i++) {
            printf(" ");
        }
        word = strtok(NULL, " \t\n\r\f\v");
    }

    printf("\n");
}

/* Function to read the file and print formatted lines of text */
void readAndPrintFile(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    int lineNumber = 1;
    char* line;

    while ((line = readLine(file))!= NULL) {
        printLine(line, lineNumber);
        lineNumber++;
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];
    readAndPrintFile(filename);

    return 0;
}