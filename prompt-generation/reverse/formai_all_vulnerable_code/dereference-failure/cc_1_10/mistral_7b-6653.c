//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define WORD_LENGTH 5

void process_line(char line[], int *count) {
    int i, j, word_index = 0;
    char word[WORD_LENGTH + 1];

    for (i = 0; i < strlen(line); i++) {
        if (isspace(line[i])) {
            if (word_index > 0) {
                if (strcmp(word, "CEDARS") == 0) {
                    (*count)++;
                }
                word_index = 0;
                memset(word, 0, WORD_LENGTH + 1);
            }
            continue;
        }
        word[word_index++] = tolower(line[i]);
    }

    if (word_index > 0 && strcmp(word, "cedars") == 0) {
        (*count)++;
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int count = 0;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        process_line(line, &count);
    }

    fclose(file);

    printf("Sherlock Holmes here, dear Watson. I've counted the occurrences\n");
    printf("of the elusive word 'cedars' in the given file. The count is %d.\n", count);

    return 0;
}