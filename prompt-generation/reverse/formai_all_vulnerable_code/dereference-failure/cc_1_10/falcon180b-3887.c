//Falcon-180B DATASET v1.0 Category: File handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define DELIMITER " \t\n\r\f\v"

typedef struct {
    char *word;
    int length;
} Word;

typedef struct {
    Word *words;
    int count;
} Line;

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    Line *lines = NULL;
    int line_count = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        lines = realloc(lines, sizeof(Line) * ++line_count);
        lines[line_count - 1].words = NULL;
        lines[line_count - 1].count = 0;

        char *token = strtok(line, DELIMITER);
        while (token!= NULL) {
            int length = strlen(token);
            if (length > MAX_WORD_LENGTH) {
                printf("Warning: word '%s' is too long and will be truncated.\n", token);
                length = MAX_WORD_LENGTH;
            }

            Word *word = malloc(sizeof(Word));
            word->word = malloc(length + 1);
            strncpy(word->word, token, length);
            word->word[length] = '\0';
            word->length = length;

            lines[line_count - 1].words = realloc(lines[line_count - 1].words, sizeof(Word) * ++lines[line_count - 1].count);
            lines[line_count - 1].words[lines[line_count - 1].count - 1] = *word;

            token = strtok(NULL, DELIMITER);
        }
    }

    fclose(file);

    printf("Total lines: %d\n", line_count);

    for (int i = 0; i < line_count; i++) {
        printf("Line %d:\n", i + 1);
        for (int j = 0; j < lines[i].count; j++) {
            printf("Word %d: '%s' (%d characters)\n", j + 1, lines[i].words[j].word, lines[i].words[j].length);
        }
        printf("\n");
    }

    return 0;
}