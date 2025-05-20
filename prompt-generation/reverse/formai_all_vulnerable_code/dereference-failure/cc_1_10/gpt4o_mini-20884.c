//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000
#define DICTIONARY_FILE "cyber.dict"
#define WORDLIST_FILE "cyber.input"

typedef struct {
    char **words;
    int count;
} Dictionary;

Dictionary load_dictionary(const char *filename) {
    Dictionary dict;
    dict.words = malloc(MAX_WORDS * sizeof(char *));
    dict.count = 0;

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open dictionary file");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_WORD_LENGTH];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
        dict.words[dict.count] = malloc(strlen(buffer) + 1);
        strcpy(dict.words[dict.count], buffer);
        dict.count++;
    }
    fclose(file);
    return dict;
}

void free_dictionary(Dictionary *dict) {
    for (int i = 0; i < dict->count; i++) {
        free(dict->words[i]);
    }
    free(dict->words);
}

int compare_strings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int is_word_in_dictionary(const char *word, Dictionary *dict) {
    return bsearch(&word, dict->words, dict->count, sizeof(char *), compare_strings) != NULL;
}

char *to_lower(const char *str) {
    char *lower = malloc(strlen(str) + 1);
    for (int i = 0; str[i]; i++) {
        lower[i] = tolower((unsigned char)str[i]);
    }
    lower[strlen(str)] = '\0';
    return lower;
}

void spell_check(const char *input_file, Dictionary *dict) {
    FILE *file = fopen(input_file, "r");
    if (!file) {
        perror("Could not open input file");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        char *word = strtok(buffer, " ");
        while (word) {
            char *lower_word = to_lower(word);
            if (!is_word_in_dictionary(lower_word, dict)) {
                printf("☠️ Misspelled word: '%s'\n", word);
            }
            free(lower_word);
            word = strtok(NULL, " ");
        }
    }
    fclose(file);
}

void display_welcome_message() {
    printf("**********************************\n");
    printf("  Welcome to the Cyber Spell Check\n");
    printf("  Enter the neon-lit world of text\n");
    printf("  where every word counts. 💻\n");
    printf("**********************************\n");
}

int main(int argc, char *argv[]) {
    display_welcome_message();

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Dictionary dictionary = load_dictionary(DICTIONARY_FILE);
    spell_check(argv[1], &dictionary);
    free_dictionary(&dictionary);

    printf("⚡ Done! Your words now shine brighter than neon! ⚡\n");
    return 0;
}