//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000
#define MAX_SUGGESTIONS 5

typedef struct {
    char **words;
    int size;
} Dictionary;

void load_dictionary(Dictionary *dict, const char *filename);
void free_dictionary(Dictionary *dict);
int is_word_in_dictionary(Dictionary *dict, const char *word);
void suggest_corrections(Dictionary *dict, const char *word);
void add_word_to_dictionary(Dictionary *dict, const char *word);
int get_user_input(char *input, size_t size);
void remove_newline(char *str);

int main() {
    Dictionary dict;
    dict.words = malloc(MAX_DICTIONARY_SIZE * sizeof(char *));
    dict.size = 0;
    
    load_dictionary(&dict, "dictionary.txt");

    char input[MAX_WORD_LENGTH];
    printf("Enter a word to check (or 'exit' to quit):\n");
    
    while (1) {
        get_user_input(input, MAX_WORD_LENGTH);
        remove_newline(input);
        
        if (strcmp(input, "exit") == 0) {
            break;
        }

        if (is_word_in_dictionary(&dict, input)) {
            printf("'%s' is spelled correctly.\n", input);
        } else {
            printf("'%s' is not found in the dictionary.\n", input);
            printf("Suggestions: ");
            suggest_corrections(&dict, input);
        }
    }

    free_dictionary(&dict);

    return 0;
}

void load_dictionary(Dictionary *dict, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open dictionary file.\n");
        exit(EXIT_FAILURE);
    }

    while (dict->size < MAX_DICTIONARY_SIZE && !feof(file)) {
        dict->words[dict->size] = malloc(MAX_WORD_LENGTH);
        fgets(dict->words[dict->size], MAX_WORD_LENGTH, file);
        remove_newline(dict->words[dict->size]);
        dict->size++;
    }

    fclose(file);
}

void free_dictionary(Dictionary *dict) {
    for (int i = 0; i < dict->size; i++) {
        free(dict->words[i]);
    }
    free(dict->words);
}

int is_word_in_dictionary(Dictionary *dict, const char *word) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->words[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

void suggest_corrections(Dictionary *dict, const char *word) {
    int count = 0;
    for (int i = 0; i < dict->size && count < MAX_SUGGESTIONS; i++) {
        if (strncmp(dict->words[i], word, 3) == 0) { // Suggest based on first 3 letters
            printf("%s ", dict->words[i]);
            count++;
        }
    }
    if (count == 0) {
        printf("No suggestions available.");
    }
    printf("\n");
}

void add_word_to_dictionary(Dictionary *dict, const char *word) {
    if (dict->size < MAX_DICTIONARY_SIZE) {
        dict->words[dict->size] = malloc(MAX_WORD_LENGTH);
        strcpy(dict->words[dict->size], word);
        dict->size++;
    }
}

int get_user_input(char *input, size_t size) {
    printf("> ");
    return fgets(input, size, stdin) != NULL;
}

void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}