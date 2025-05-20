//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_valid_word_char(char ch) {
    return isalnum(ch) || ch == '_';  // Allows alphanumeric characters and underscores
}

int add_word(WordCount words[], int *size, const char *word) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return *size;  // Word found, count incremented
        }
    }
    
    // Add new word
    strncpy(words[*size].word, word, MAX_WORD_LENGTH);
    words[*size].word[MAX_WORD_LENGTH - 1] = '\0';  // Null terminate
    words[*size].count = 1;
    (*size)++;
    return *size;  // New word added
}

void sort_words(WordCount words[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (words[i].count < words[j].count) {
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_word_counts(const WordCount words[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

void clean_input_string(char *input_str) {
    int length = strlen(input_str);
    for (int i = 0; i < length; i++) {
        if (!is_valid_word_char(input_str[i]) && input_str[i] != ' ') {
            input_str[i] = ' ';
        }
    }
}

void process_text(const char *text) {
    WordCount words[MAX_WORDS];
    int size = 0;
    char buffer[MAX_WORD_LENGTH];
    char *token;

    // Clean the input string to ensure valid words
    char *cleaned_text = strdup(text);
    clean_input_string(cleaned_text);

    // Convert to lowercase for case insensitive counting
    to_lowercase(cleaned_text);
    
    // Tokenize the cleaned string using space as delimiter
    token = strtok(cleaned_text, " ");
    while (token != NULL) {
        if (strlen(token) > 0) {
            add_word(words, &size, token);
        }
        token = strtok(NULL, " ");
    }

    // Sort words by frequency
    sort_words(words, size);

    // Print word counts
    printf("Word frequency count:\n");
    print_word_counts(words, size);

    free(cleaned_text);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return 1;
    }

    // Concatenate all the case arguments into a single text string
    char input_text[4096] = ""; // Buffer for concatenated input
    for (int i = 1; i < argc; i++) {
        strcat(input_text, argv[i]);
        if (i < argc - 1) {
            strcat(input_text, " ");
        }
    }

    // Process the text for word frequency count
    process_text(input_text);

    return 0;
}