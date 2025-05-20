//Falcon-180B DATASET v1.0 Category: Text processing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *file, struct word_count words[], int *num_words) {
    char line[1000];
    char *word = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file))!= -1) {
        char *token = strtok_r(line, " \t\n\r\f\v", &word);
        while (token!= NULL) {
            if (*num_words >= MAX_WORDS) {
                printf("Error: Maximum number of words (%d) exceeded.\n", MAX_WORDS);
                exit(1);
            }
            strcpy(words[*num_words].word, token);
            words[*num_words].count = 1;
            (*num_words)++;
            token = strtok_r(NULL, " \t\n\r\f\v", &word);
        }
    }
}

void sort_words(struct word_count words[], int num_words) {
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) > 0) {
                struct word_count temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_word_counts(struct word_count words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *file = NULL;
    char filename[100];
    int num_words = 0;
    struct word_count words[MAX_WORDS];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    read_file(file, words, &num_words);
    fclose(file);

    sort_words(words, num_words);
    print_word_counts(words, num_words);

    return 0;
}