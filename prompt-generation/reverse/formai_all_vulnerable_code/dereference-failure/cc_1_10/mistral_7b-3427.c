//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50

typedef struct {
    char *alien_word;
    char *human_word;
} TranslationPair;

void load_dictionary(TranslationPair dictionary[MAX_WORDS]) {
    FILE *file = fopen("dictionary.txt", "r");
    char line[MAX_LENGTH];
    int i = 0;

    if (file == NULL) {
        fprintf(stderr, "Error: Could not open dictionary file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        char *alien_start = strtok(line, " :");
        char *alien_end = strtok(NULL, "\n");
        char *human_start = strtok(alien_start, " ");
        char *human_end = strtok(NULL, "\n");

        if (i >= MAX_WORDS) {
            fprintf(stderr, "Error: Dictionary file contains too many words.\n");
            exit(EXIT_FAILURE);
        }

        dictionary[i].alien_word = malloc(strlen(alien_start) + 1);
        strcpy(dictionary[i].alien_word, alien_start);
        dictionary[i].human_word = malloc(strlen(human_start) + 1);
        strcpy(dictionary[i].human_word, human_start);
        i++;
    }

    fclose(file);
}

int translate_word(TranslationPair dictionary[MAX_WORDS], char *alien_word) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(dictionary[i].alien_word, alien_word) == 0) {
            printf("%s\n", dictionary[i].human_word);
            return 1;
        }
    }

    printf("Unknown word: %s\n", alien_word);
    return 0;
}

int main() {
    TranslationPair dictionary[MAX_WORDS];

    load_dictionary(dictionary);

    char alien_word[MAX_LENGTH];

    while (1) {
        printf("Enter an alien word or type 'quit' to exit: ");
        scanf("%s", alien_word);

        if (strcmp(alien_word, "quit") == 0) {
            break;
        }

        translate_word(dictionary, alien_word);
    }

    for (int i = 0; i < MAX_WORDS; i++) {
        free(dictionary[i].alien_word);
        free(dictionary[i].human_word);
    }

    return 0;
}