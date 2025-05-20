//Falcon-180B DATASET v1.0 Category: File handling ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_WORD_SIZE 100

char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_SIZE);
    char *ptr = line;
    int c;
    while ((c = fgetc(file))!= EOF && ptr - line < MAX_LINE_SIZE - 1) {
        *ptr++ = c;
    }
    *ptr = '\0';
    return line;
}

char *read_word(char *line) {
    char *word = malloc(MAX_WORD_SIZE);
    char *ptr = word;
    while (isspace(*line)) {
        line++;
    }
    while (!isspace(*line) && ptr - word < MAX_WORD_SIZE - 1) {
        *ptr++ = *line++;
    }
    *ptr = '\0';
    return word;
}

int main() {
    FILE *file;
    char *line;
    char *word;
    int count = 0;
    int word_count = 0;

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while ((line = read_line(file))!= NULL) {
        word = read_word(line);
        while (word!= NULL) {
            printf("%s ", word);
            word_count++;
            word = read_word(line);
        }
        printf("\n");
        count++;
    }

    printf("Total number of words: %d\n", word_count);
    printf("Total number of lines: %d\n", count);

    fclose(file);
    return 0;
}