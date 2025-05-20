//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MIN_PATTERN_LENGTH 3
#define BUFFER_SIZE 1024 * 1024

char *pattern;
char fileContent[BUFFER_SIZE];
int lineNumber = 0;
FILE *file;

// Function to transform the pattern to lowercase and remove special characters
void preparePattern() {
    int len = strlen(pattern);
    pattern[len] = '\0';
    int i = 0, j = 0;

    while (i < len && j < len) {
        if (isalpha(pattern[i])) {
            pattern[j] = pattern[i];
            i++;
            j++;
        } else if (pattern[i] == '.' || pattern[i] == '*') {
            i++;
        }
    }
    pattern[j] = '\0';
}

// Function to check if the pattern matches with the current line
int checkLine(char *line) {
    int patternLen = strlen(pattern);
    int lineLen = strlen(line);

    if (patternLen > lineLen)
        return 0;

    int i = 0, j = 0;
    while (i < patternLen && j < lineLen) {
        if (tolower(line[j]) != tolower(pattern[i])) {
            i++;
            continue;
        }

        i++;
        j++;
    }

    if (i == patternLen)
        return 1;

    return 0;
}

// Function to search for the pattern in the file
void searchFile() {
    rewind(file);
    char line[MAX_LINE_LENGTH];
    int patternLen = strlen(pattern);

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        lineNumber++;
        if (checkLine(line)) {
            printf("Pattern '%s' found in line %d\n", pattern, lineNumber);
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file_name> <pattern>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    pattern = argv[2];
    preparePattern();
    searchFile();

    fclose(file);
    return 0;
}