//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define INITIAL_WORDS_COUNT 10

typedef struct {
    char** words;
    int* counts;
    int size;
    int capacity;
} WordCount;

// Function prototypes
WordCount* create_wordcount();
void add_word(WordCount* wc, const char* word);
void free_wordcount(WordCount* wc);
void print_statistics(WordCount* wc, int total_words, int total_lines, int total_chars);
void to_lowercase(char* str);
int is_valid_char(char c);
void process_file(const char* filename);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_file(argv[1]);
    return EXIT_SUCCESS;
}

void process_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    WordCount* word_count = create_wordcount();
    char line[1024];
    int total_words = 0, total_lines = 0, total_chars = 0;

    while (fgets(line, sizeof(line), file)) {
        total_lines++;
        total_chars += strlen(line);
        
        char* token = strtok(line, " \n\t\r");
        while (token) {
            to_lowercase(token);
            add_word(word_count, token);
            total_words++;
            token = strtok(NULL, " \n\t\r");
        }
    }

    fclose(file);
    print_statistics(word_count, total_words, total_lines, total_chars);
    free_wordcount(word_count);
}

WordCount* create_wordcount() {
    WordCount* wc = malloc(sizeof(WordCount));
    wc->size = 0;
    wc->capacity = INITIAL_WORDS_COUNT;
    wc->words = malloc(wc->capacity * sizeof(char*));
    wc->counts = malloc(wc->capacity * sizeof(int));
    return wc;
}

void add_word(WordCount* wc, const char* word) {
    for (int i = 0; i < wc->size; i++) {
        if (strcmp(wc->words[i], word) == 0) {
            wc->counts[i]++;
            return;
        }
    }
    
    if (wc->size >= wc->capacity) {
        wc->capacity *= 2;
        wc->words = realloc(wc->words, wc->capacity * sizeof(char*));
        wc->counts = realloc(wc->counts, wc->capacity * sizeof(int));
    }

    wc->words[wc->size] = strdup(word);
    wc->counts[wc->size] = 1;
    wc->size++;
}

void free_wordcount(WordCount* wc) {
    for (int i = 0; i < wc->size; i++) {
        free(wc->words[i]);
    }
    free(wc->words);
    free(wc->counts);
    free(wc);
}

void print_statistics(WordCount* wc, int total_words, int total_lines, int total_chars) {
    printf("Total lines: %d\n", total_lines);
    printf("Total words: %d\n", total_words);
    printf("Total characters: %d\n", total_chars);
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wc->size; i++) {
        printf("%s: %d\n", wc->words[i], wc->counts[i]);
    }
}

void to_lowercase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int is_valid_char(char c) {
    return isalnum(c) || c == '\'' || c == '-';
}