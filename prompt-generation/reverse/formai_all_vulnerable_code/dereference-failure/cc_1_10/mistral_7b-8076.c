//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define WORD_DELIMITERS " ,.!?:;\"()[]{}<>\n"

void removeDelimiters(char* str, char* delimiters) {
    int i = 0, j = 0;

    while (str[i] != '\0') {
        if (!strchr(delimiters, str[i])) {
            str[j++] = str[i];
        }

        i++;
    }

    str[j] = '\0';
}

int countWords(char* str, char* delimiters) {
    int count = 0, i = 0;

    while (str[i] != '\0') {
        if (isspace(str[i])) {
            if (strlen(str + i) > 0) {
                count++;
            }
            i++;

            while (isspace(str[i])) {
                i++;
            }

            continue;
        }

        if (strlen(str + i) > 0) {
            removeDelimiters(str + i, delimiters);
            i += strlen(str + i);
        }
    }

    if (strlen(str + i) > 0) {
        count++;
    }

    return count;
}

int main(int argc, char* argv[]) {
    char* inputStr = NULL;
    char* delimiters = NULL;
    int i = 0, wordCount = 0;

    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    inputStr = (char*) calloc(MAX_LINE_LENGTH, sizeof(char));

    if (inputStr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    strcpy(inputStr, argv[1]);

    delimiters = (char*) calloc(strlen(WORD_DELIMITERS) + 1, sizeof(char));

    if (delimiters == NULL) {
        printf("Memory allocation failed!\n");
        free(inputStr);
        return 1;
    }

    strcpy(delimiters, WORD_DELIMITERS);

    wordCount = countWords(inputStr, delimiters);

    printf("Number of words: %d\n", wordCount);

    free(inputStr);
    free(delimiters);

    return 0;
}