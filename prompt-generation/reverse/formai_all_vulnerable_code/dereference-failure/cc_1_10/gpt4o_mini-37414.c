//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER 1024
#define MAX_WORDS 500

typedef struct {
    char *word;
    int count;
} WordCount;

void initialize_word_count(WordCount *wc, int size) {
    for (int i = 0; i < size; i++) {
        wc[i].word = NULL;
        wc[i].count = 0;
    }
}

void add_word(WordCount *wc, const char *word, int *size) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(wc[i].word, word) == 0) {
            wc[i].count++;
            return;
        }
    }
    
    if (*size < MAX_WORDS) {
        wc[*size].word = malloc(strlen(word) + 1);
        strcpy(wc[*size].word, word);
        wc[*size].count = 1;
        (*size)++;
    }
}

void free_word_count(WordCount *wc, int size) {
    for (int i = 0; i < size; i++) {
        free(wc[i].word);
    }
}

void print_word_count(WordCount *wc, int size) {
    printf("---- Word Count Report ----\n");
    for (int i = 0; i < size; i++) {
        if (wc[i].count > 0) {
            printf("%s: %d\n", wc[i].word, wc[i].count);
        }
    }
    printf("---------------------------\n");
}

char *transform_input(const char *input) {
    char *cleaned_input = malloc(strlen(input) + 1);
    int j = 0;
    for (int i = 0; input[i]; i++) {
        if (isalnum(input[i]) || ispunct(input[i])) {
            cleaned_input[j++] = tolower(input[i]);
        } else {
            cleaned_input[j++] = ' ';
        }
    }
    cleaned_input[j] = '\0';
    return cleaned_input;
}

void count_words(const char *input, WordCount *wc) {
    int word_count_size = 0;
    char *cleaned_input = transform_input(input);
    char *token = strtok(cleaned_input, " ");
    
    while (token != NULL) {
        if (strlen(token) > 0) {
            add_word(wc, token, &word_count_size);
        }
        token = strtok(NULL, " ");
    }
    
    free(cleaned_input);
    print_word_count(wc, word_count_size);
}

int main(int argc, char *argv[]) {
    printf("----- Future Word Count Tool -----\n");
    if (argc < 2) {
        printf("Error: No input text provided. Use: %s '<text>'\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    WordCount *word_counts = malloc(sizeof(WordCount) * MAX_WORDS);
    initialize_word_count(word_counts, MAX_WORDS);
    
    for (int i = 1; i < argc; i++) {
        count_words(argv[i], word_counts);
    }
    
    free_word_count(word_counts, MAX_WORDS);
    free(word_counts);
    return EXIT_SUCCESS;
}