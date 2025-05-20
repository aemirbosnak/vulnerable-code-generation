//Falcon-180B DATASET v1.0 Category: System administration ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    char *word = malloc(MAX_WORD_LENGTH);
    char c;
    int i = 0;

    while ((c = fgetc(file))!= EOF) {
        if (isspace(c)) {
            word[i] = '\0';
            strcat(line, word);
            strcpy(word, "");
            i = 0;
        } else {
            if (i >= MAX_WORD_LENGTH - 1) {
                printf("Error: Word is too long.\n");
                exit(1);
            }
            word[i++] = tolower(c);
        }
    }

    if (i > 0) {
        word[i] = '\0';
        strcat(line, word);
    }

    free(word);
    return line;
}

void count_words(char *line) {
    char *word = strtok(line, " ");
    int count = 0;

    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    printf("Number of words: %d\n", count);
}

void count_chars(char *line) {
    int count = 0;

    while (*line!= '\0') {
        count++;
        line++;
    }

    printf("Number of characters: %d\n", count);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *line;

    if (argc < 2) {
        printf("Error: No file specified.\n");
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    line = read_line(file);
    count_words(line);
    count_chars(line);

    free(line);
    fclose(file);

    return 0;
}