//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_valid_character(char c) {
    return isalpha(c) || c == '\'';
}

void clean_word(char *word) {
    char *start = word;
    char *end = word + strlen(word) - 1;

    while (*start && !is_valid_character(*start)) {
        start++;
    }
    
    while (end > start && !is_valid_character(*end)) {
        end--;
    }
    
    if (start > end) {
        *start = '\0'; // no valid characters
    } else {
        memmove(word, start, end - start + 1);
        word[end - start + 1] = '\0';
    }
}

int add_word(WordFrequency *words, int *size, const char *new_word) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(words[i].word, new_word) == 0) {
            words[i].count++;
            return 0; // word already exists
        }
    }

    if (*size < MAX_WORDS) {
        strcpy(words[*size].word, new_word);
        words[*size].count = 1;
        (*size)++;
        return 1; // new word added
    }

    return -1; // unable to add new word
}

void print_word_frequencies(WordFrequency *words, int size) {
    printf("\nWord Frequency:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    WordFrequency words[MAX_WORDS];
    int size = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%99s", word) == 1) {
        clean_word(word);
        if (strlen(word) > 0) {
            to_lowercase(word);
            if (add_word(words, &size, word) == -1) {
                fprintf(stderr, "Reached maximum word limit!\n");
                fclose(file);
                return EXIT_FAILURE;
            }
        }
    }

    fclose(file);

    print_word_frequencies(words, size);
    return EXIT_SUCCESS;
}