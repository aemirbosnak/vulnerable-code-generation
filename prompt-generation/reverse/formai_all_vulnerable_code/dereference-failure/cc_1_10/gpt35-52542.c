//FormAI DATASET v1.0 Category: Spell checking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50
#define MAX_DICT_WORDS 10000

int dictionary_size = 0;

char** load_dictionary(void);
void unload_dictionary(char**);
int check_word(char*, char**);

int main(void) {
    char** dictionary = load_dictionary();
    char word[MAX_WORD_SIZE];

    while (1) {
        printf("Enter word to check: ");
        scanf("%s", word);

        if (check_word(word, dictionary)) {
            printf("Correct spelling.\n");
        } else {
            printf("Incorrect spelling.\n");
        }
    }

    unload_dictionary(dictionary);
    return 0;
}

char** load_dictionary(void) {
    char** dictionary = malloc(sizeof(char*) * MAX_DICT_WORDS);

    FILE* dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Unable to open dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_SIZE];
    while (fscanf(dict_file, "%s", word) != EOF) {
        dictionary[dictionary_size] = malloc(strlen(word) + 1);

        if (dictionary[dictionary_size] == NULL) {
            printf("Unable to allocate memory for dictionary.\n");
            exit(1);
        }

        strcpy(dictionary[dictionary_size], word);
        dictionary_size++;
    }

    return dictionary;
}

void unload_dictionary(char** dictionary) {
    for (int i = 0; i < dictionary_size; i++) {
        free(dictionary[i]);
    }

    free(dictionary);
}

int check_word(char* word, char** dictionary) {
    // make word lowercase for comparison
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    // check if word is in dictionary
    for (int i = 0; i < dictionary_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }

    return 0;
}