//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100
#define DELIMITERS " ,.!?\"\n\t;:-()[]{}"

typedef struct {
    char **words;
    int count;
} WordArray;

WordArray* create_word_array(int size) {
    WordArray *wordArray = (WordArray *)malloc(sizeof(WordArray));
    wordArray->words = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        wordArray->words[i] = (char *)malloc(MAX_WORD_LENGTH * sizeof(char));
    }
    wordArray->count = 0;
    return wordArray;
}

void free_word_array(WordArray *wordArray) {
    for (int i = 0; i < wordArray->count; i++) {
        free(wordArray->words[i]);
    }
    free(wordArray->words);
    free(wordArray);
}

void add_word(WordArray *wordArray, const char *word) {
    if (wordArray->count < MAX_WORDS) {
        strcpy(wordArray->words[wordArray->count], word);
        wordArray->count++;
    }
}

int contains_word(WordArray *wordArray, const char *word) {
    for (int i = 0; i < wordArray->count; i++) {
        if (strcmp(wordArray->words[i], word) == 0) {
            return 1; // Word is found
        }
    }
    return 0; // Word not found
}

void count_words_in_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    WordArray *wordArray = create_word_array(MAX_WORDS);
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file)) {
        char *token = strtok(buffer, DELIMITERS);
        while (token) {
            if (!contains_word(wordArray, token)) {
                add_word(wordArray, token);
            }
            token = strtok(NULL, DELIMITERS);
        }
    }

    fclose(file);

    printf("Unique words in file '%s':\n", filename);
    for (int i = 0; i < wordArray->count; i++) {
        printf("%s\n", wordArray->words[i]);
    }
    
    printf("\nTotal unique words: %d\n", wordArray->count);

    free_word_array(wordArray);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    count_words_in_file(argv[1]);

    return EXIT_SUCCESS;
}