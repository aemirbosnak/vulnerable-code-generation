//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_LENGTH 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int is_correct;
} Word;

typedef struct {
    Word *words;
    int length;
} Dictionary;

void init_dictionary(Dictionary *dict) {
    dict->words = malloc(MAX_DICTIONARY_LENGTH * sizeof(Word));
    dict->length = 0;
}

void add_word(Dictionary *dict, char *word) {
    Word *new_word = dict->words + dict->length;
    strcpy(new_word->word, word);
    new_word->is_correct = 1;
    dict->length++;
}

int is_correct_word(Dictionary *dict, char *word) {
    Word *entry = dict->words;
    while (entry->is_correct && strcmp(entry->word, word)!= 0) {
        entry++;
    }
    return entry->is_correct;
}

int main() {
    FILE *file;
    char text[100000];
    char word[MAX_WORD_LENGTH];
    int is_correct;
    Dictionary dict;
    init_dictionary(&dict);

    // Load dictionary from file
    file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error loading dictionary\n");
        exit(1);
    }
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        add_word(&dict, line);
    }
    fclose(file);

    // Load text to check
    file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Error loading text\n");
        exit(1);
    }
    fgets(text, 100000, file);
    fclose(file);

    // Check spelling
    char *word_start = strtok(text, " ");
    while (word_start!= NULL) {
        strcpy(word, word_start);
        is_correct = is_correct_word(&dict, word);
        if (!is_correct) {
            printf("Possible spelling mistake: %s\n", word);
        }
        word_start = strtok(NULL, " ");
    }

    return 0;
}