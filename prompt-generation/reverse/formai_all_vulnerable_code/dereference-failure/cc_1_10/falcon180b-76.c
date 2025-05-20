//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *name;
    int length;
    int is_valid;
} Word;

void sanitize_string(char *str) {
    int i, j;
    for (i = 0; i < strlen(str); i++) {
        if (!isalnum(str[i])) {
            for (j = i; j < strlen(str); j++) {
                str[j] = str[j + 1];
            }
            str[--i] = '\0';
        }
    }
}

int is_valid_name(char *name) {
    int i;
    for (i = 0; i < strlen(name); i++) {
        if (!isalnum(name[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char line[MAX_LINE_LENGTH];
    Word *words = NULL;
    int num_words = 0;
    int word_index;
    int i;

    printf("Enter a line of text:\n");
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Sanitize input
    sanitize_string(line);

    // Tokenize input
    char *token = strtok(line, " ");
    while (token!= NULL) {
        Word *new_word = (Word*) malloc(sizeof(Word));
        new_word->name = strdup(token);
        new_word->length = strlen(token);
        new_word->is_valid = is_valid_name(token);
        words = (Word*) realloc(words, sizeof(Word) * ++num_words);
        words[num_words - 1] = *new_word;
        token = strtok(NULL, " ");
    }

    // Print valid words
    for (i = 0; i < num_words; i++) {
        if (words[i].is_valid) {
            printf("%s\n", words[i].name);
        }
    }

    // Free memory
    for (i = 0; i < num_words; i++) {
        free(words[i].name);
    }
    free(words);

    return 0;
}