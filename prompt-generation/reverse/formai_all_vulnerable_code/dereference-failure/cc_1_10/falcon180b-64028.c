//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20
#define MAX_DICTIONARY_SIZE 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

typedef struct {
    Word *words;
    int size;
} Dictionary;

void init_dictionary(Dictionary *dict) {
    dict->words = (Word *)malloc(MAX_DICTIONARY_SIZE * sizeof(Word));
    dict->size = 0;
}

void add_word(Dictionary *dict, char *word, bool is_correct) {
    if (dict->size >= MAX_DICTIONARY_SIZE) {
        printf("Dictionary is full.\n");
        return;
    }

    strcpy(dict->words[dict->size].word, word);
    dict->words[dict->size].is_correct = is_correct;
    dict->size++;
}

bool is_correct_word(Dictionary *dict, char *word) {
    int i;
    for (i = 0; i < dict->size; i++) {
        if (strcmp(dict->words[i].word, word) == 0) {
            return dict->words[i].is_correct;
        }
    }
    return false;
}

void check_file(FILE *file, Dictionary *dict) {
    char word[MAX_WORD_LENGTH];
    char line[100];

    while (fgets(line, sizeof(line), file)!= NULL) {
        int i;
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                strncat(word, &line[i], 1);
            } else {
                if (strlen(word) > 0) {
                    if (!is_correct_word(dict, word)) {
                        printf("Incorrect word: %s\n", word);
                    }
                }
                word[0] = '\0';
            }
        }
    }
}

int main() {
    FILE *file;
    Dictionary dict;

    init_dictionary(&dict);

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    check_file(file, &dict);

    free(dict.words);
    fclose(file);

    return 0;
}