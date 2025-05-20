//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_WORDS 10000
#define MAX_INPUT_LENGTH 1000

typedef struct {
    char **words;
    int count;
} Dictionary;

Dictionary* load_dictionary(const char* filename) {
    Dictionary* dict = (Dictionary*)malloc(sizeof(Dictionary));
    dict->words = (char**)malloc(MAX_DICTIONARY_WORDS * sizeof(char*));
    dict->count = 0;
    
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file '%s'.\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dict->words[dict->count]) != EOF) {
        dict->words[dict->count] = strdup(dict->words[dict->count]);
        dict->count++;
        if (dict->count >= MAX_DICTIONARY_WORDS) {
            break;
        }
    }

    fclose(file);
    return dict;
}

int is_word_in_dictionary(Dictionary* dict, const char* word) {
    for (int i = 0; i < dict->count; i++) {
        if (strcasecmp(dict->words[i], word) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

void check_spelling(const char* input_filename, Dictionary* dict) {
    FILE* file = fopen(input_filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open input file '%s'.\n", input_filename);
        return;
    }

    char buffer[MAX_INPUT_LENGTH];
    while (fgets(buffer, MAX_INPUT_LENGTH, file)) {
        char* token = strtok(buffer, " \n");
        while (token) {
            // Remove punctuation
            for (int i = 0; token[i]; i++) {
                if (ispunct((unsigned char)token[i])) {
                    token[i] = '\0';
                }
            }
            if (!is_word_in_dictionary(dict, token)) {
                printf("Misspelled: '%s'\n", token);
            }
            token = strtok(NULL, " \n");
        }
    }

    fclose(file);
}

void free_dictionary(Dictionary* dict) {
    for (int i = 0; i < dict->count; i++) {
        free(dict->words[i]);
    }
    free(dict->words);
    free(dict);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* dictionary_file = argv[1];
    const char* input_file = argv[2];

    Dictionary* dict = load_dictionary(dictionary_file);
    check_spelling(input_file, dict);
    free_dictionary(dict);

    return EXIT_SUCCESS;
}