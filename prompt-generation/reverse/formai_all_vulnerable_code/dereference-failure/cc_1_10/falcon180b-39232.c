//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *content;
    int length;
} Word;

typedef struct {
    Word *words;
    int num_words;
    int current_word;
} Line;

void init_line(Line *line) {
    line->num_words = 0;
    line->current_word = 0;
    line->words = (Word *) malloc(MAX_WORD_LENGTH * sizeof(Word));
}

void add_word(Line *line, char *word) {
    Word *new_word = (Word *) malloc(sizeof(Word));
    strcpy(new_word->content, word);
    new_word->length = strlen(word);
    line->words[line->num_words++] = *new_word;
}

void print_line(Line *line) {
    for (int i = 0; i < line->num_words; i++) {
        printf("%s ", line->words[i].content);
    }
    printf("\n");
}

void free_line(Line *line) {
    for (int i = 0; i < line->num_words; i++) {
        free(line->words[i].content);
    }
    free(line->words);
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    Line current_line;

    file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    init_line(&current_line);

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            add_word(&current_line, word);
            word = strtok(NULL, " ");
        }
        print_line(&current_line);
        init_line(&current_line);
    }

    fclose(file);

    return 0;
}