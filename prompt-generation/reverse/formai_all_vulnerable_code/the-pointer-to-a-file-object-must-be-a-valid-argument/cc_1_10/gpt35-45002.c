//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_SIZE 100

typedef struct {
    char alien[MAX_WORD_LENGTH];
    char english[MAX_WORD_LENGTH];
} DictionaryEntry;

typedef struct {
    DictionaryEntry entries[MAX_DICTIONARY_SIZE];
    int size;
} Dictionary;

Dictionary dictionary;

void load_dictionary(char* filename) {
    FILE* file = fopen(filename, "r");
    char line[MAX_WORD_LENGTH * 2];
    dictionary.size = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        char* token = strtok(line, ",");
        strcpy(dictionary.entries[dictionary.size].alien, token);
        token = strtok(NULL, ",");
        token[strlen(token) - 1] = '\0'; // remove newline character
        strcpy(dictionary.entries[dictionary.size].english, token);
        dictionary.size++;
    }
    fclose(file);
}

void translate(char* alien_word) {
    for (int i = 0; i < dictionary.size; i++) {
        if (strcmp(alien_word, dictionary.entries[i].alien) == 0) {
            printf("%s\n", dictionary.entries[i].english);
            return;
        }
    }
    printf("Unknown word\n");
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s dictionary_file\n", argv[0]);
        return 1;
    }
    load_dictionary(argv[1]);
    char word[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter an alien word (or type exit to quit): ");
        scanf("%s", word);
        if (strcmp(word, "exit") == 0) {
            break;
        }
        translate(word);
    }
    return 0;
}