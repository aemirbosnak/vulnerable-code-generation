//Falcon-180B DATASET v1.0 Category: Text processing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, char *text) {
    fseek(file, 0, SEEK_SET);
    fread(text, sizeof(char), MAX_WORDS, file);
    text[MAX_WORDS - 1] = '\0';
}

void tokenize(char *text, char **tokens) {
    char *token = strtok(text, ",.?!;:");
    int i = 0;
    while (token!= NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, ",.?!;:");
    }
}

void count_words(char **tokens, WordCount *word_counts) {
    int i = 0;
    while (i < MAX_WORDS && tokens[i]!= NULL) {
        int j = 0;
        while (j < MAX_WORD_LENGTH && tokens[i][j]!= '\0') {
            word_counts[i].word[j] = tokens[i][j];
            j++;
        }
        word_counts[i].word[j] = '\0';
        word_counts[i].count = 1;
        i++;
    }
}

void print_word_counts(WordCount *word_counts) {
    int i = 0;
    while (i < MAX_WORDS && word_counts[i].word[0]!= '\0') {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        i++;
    }
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char text[MAX_WORDS];
    read_file(file, text);

    char *tokens[MAX_WORDS];
    tokenize(text, tokens);

    WordCount word_counts[MAX_WORDS];
    count_words(tokens, word_counts);

    print_word_counts(word_counts);

    return 0;
}