//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_file(FILE *file, char *text) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            text[i++] = tolower(ch);
        }
    }

    text[i] = '\0';
}

void tokenize(char *text, char **tokens) {
    char *token = strtok(text, ",.?!;:\"'");
    int i = 0;

    while (token!= NULL) {
        tokens[i++] = token;
        token = strtok(NULL, ",.?!;:\"'");
    }
}

void count_words(char **tokens, WordFrequency *word_frequency) {
    int i;

    for (i = 0; i < MAX_WORDS && tokens[i]!= NULL; i++) {
        int j;
        for (j = 0; j < MAX_WORD_LENGTH && tokens[i][j]!= '\0'; j++) {
            if (isalpha(tokens[i][j])) {
                word_frequency[i].word[j] = tolower(tokens[i][j]);
            }
        }
        word_frequency[i].word[j] = '\0';
        word_frequency[i].count = 1;
    }
}

void print_word_frequency(WordFrequency *word_frequency) {
    int i;

    for (i = 0; i < MAX_WORDS && word_frequency[i].word[0]!= '\0'; i++) {
        printf("%s: %d\n", word_frequency[i].word, word_frequency[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char text[MAX_WORD_LENGTH * 1000];
    char *tokens[MAX_WORDS];
    WordFrequency word_frequency[MAX_WORDS];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    read_file(file, text);
    fclose(file);

    tokenize(text, tokens);
    count_words(tokens, word_frequency);
    print_word_frequency(word_frequency);

    return 0;
}