//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define WORD_LEN 50
#define DICTIONARY_SIZE 100000

typedef struct Word {
    char word[WORD_LEN];
    struct Word *next;
} Word;

Word *dictionary = NULL;
Word *current_word = NULL;
bool word_found = false;

void load_dictionary() {
    FILE *file;
    char filename[100] = "dictionary.txt";
    char word[WORD_LEN];

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s%*c", word) != EOF) {
        Word *new_word = (Word *) malloc(sizeof(Word));
        strcpy(new_word->word, word);
        new_word->next = dictionary;
        dictionary = new_word;
    }

    fclose(file);
}

bool is_valid_word(char *word) {
    current_word = dictionary;

    while (current_word != NULL) {
        if (strcmp(current_word->word, word) == 0) {
            word_found = true;
            break;
        }
        current_word = current_word->next;
    }

    return word_found;
}

void check_spell(char *input_string) {
    char *token = strtok(input_string, " ");
    char *word;
    bool is_valid = true;

    while (token != NULL) {
        word = (char *) malloc(strlen(token) + 1);
        strcpy(word, token);

        if (!is_valid_word(word)) {
            printf("Error: %s is not a valid word.\n", word);
            is_valid = false;
        }

        free(word);
        token = strtok(NULL, " ");
    }

    if (is_valid) {
        printf("No errors found.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_dictionary();
    check_spell(argv[1]);

    return EXIT_SUCCESS;
}