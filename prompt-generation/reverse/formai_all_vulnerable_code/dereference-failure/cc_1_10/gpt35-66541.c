//FormAI DATASET v1.0 Category: Text processing ; Style: Ken Thompson
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 1000

char *read_file(const char *filename);
void write_file(const char *filename, const char *content);
void process_text(char *text);
void count_words(char *text, int *words, int *characters);
char *uppercase(char *text);
char *lowercase(char *text);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    char *text = read_file(argv[1]);
    if (!text) {
        printf("Unable to read file %s\n", argv[1]);
        return 2;
    }

    process_text(text);

    write_file(argv[2], text);

    printf("Text processed successfully.\n");

    free(text);

    return 0;
}

char *read_file(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        return NULL;
    }

    char * buffer = (char*)malloc(MAX_BUF * sizeof(char));

    int i = 0;
    int c;
    while ((c = fgetc(f)) != EOF) {
        buffer[i++] = c;
    }
    buffer[i] = '\0';

    fclose(f);

    return buffer;
}

void write_file(const char *filename, const char *content) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        printf("Unable to write to file %s\n", filename);
        return;
    }

    fputs(content, f);

    fclose(f);
}

void process_text(char *text) {
    int words, characters;
    count_words(text, &words, &characters);

    char *upper = uppercase(text);
    char *lower = lowercase(text);

    printf("Number of words: %d\n", words);
    printf("Number of characters: %d\n", characters);

    strcat(text, upper);
    strcat(text, lower);

    free(upper);
    free(lower);
}

void count_words(char *text, int *words, int *characters) {
    *words = 0;
    *characters = 0;

    int in_word = 0;
    for (int i = 0; text[i]; i++) {
        if (isspace(text[i])) {
            in_word = 0;
        } else {
            if (!in_word) {
                (*words)++;
            }
            in_word = 1;
        }
        (*characters)++;
    }
}

char *uppercase(char *text) {
    char *new_text = (char*)malloc(MAX_BUF * sizeof(char));
    strncpy(new_text, text, MAX_BUF);

    for (int i = 0; new_text[i]; i++) {
        new_text[i] = toupper(new_text[i]);
    }

    return new_text;
}

char *lowercase(char *text) {
    char *new_text = (char*)malloc(MAX_BUF * sizeof(char));
    strncpy(new_text, text, MAX_BUF);

    for (int i = 0; new_text[i]; i++) {
        new_text[i] = tolower(new_text[i]);
    }

    return new_text;
}