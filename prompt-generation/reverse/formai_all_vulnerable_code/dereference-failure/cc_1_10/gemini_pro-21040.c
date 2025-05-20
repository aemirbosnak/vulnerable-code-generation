//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct dictionary {
    char** words;
    int size;
};

struct dictionary* create_dictionary(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    struct dictionary* dictionary = malloc(sizeof(struct dictionary));
    dictionary->size = 0;
    dictionary->words = NULL;

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        char* word = malloc(strlen(line) + 1);
        strcpy(word, line);
        word[strlen(word) - 1] = '\0';

        dictionary->words = realloc(dictionary->words, (dictionary->size + 1) * sizeof(char*));
        dictionary->words[dictionary->size] = word;
        dictionary->size++;
    }

    fclose(file);

    return dictionary;
}

void free_dictionary(struct dictionary* dictionary) {
    for (int i = 0; i < dictionary->size; i++) {
        free(dictionary->words[i]);
    }
    free(dictionary->words);
    free(dictionary);
}

bool is_word_in_dictionary(struct dictionary* dictionary, char* word) {
    for (int i = 0; i < dictionary->size; i++) {
        if (strcmp(dictionary->words[i], word) == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    struct dictionary* dictionary = create_dictionary("words.txt");

    char input[1024];
    printf("Enter a string: ");
    scanf("%s", input);

    char* word = strtok(input, " ,.-");
    while (word != NULL) {
        if (!is_word_in_dictionary(dictionary, word)) {
            printf("%s is not a word.\n", word);
        }

        word = strtok(NULL, " ,.-");
    }

    free_dictionary(dictionary);

    return 0;
}