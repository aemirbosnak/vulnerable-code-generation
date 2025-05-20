//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <float.h>

#define MAX_SENTENCE_LENGTH 1024
#define MAX_DICT_SIZE 10000

typedef struct {
    char word[20];
    int frequency;
} word_t;

typedef struct {
    word_t words[MAX_DICT_SIZE];
    int size;
} dict_t;

dict_t *create_dict() {
    dict_t *dict = malloc(sizeof(dict_t));
    dict->size = 0;
    return dict;
}

void add_word(dict_t *dict, char *word) {
    if (dict->size >= MAX_DICT_SIZE) {
        printf("Error: Dictionary is full. Please add more words.\n");
        return;
    }
    strcpy(dict->words[dict->size].word, word);
    dict->words[dict->size].frequency = 1;
    dict->size++;
}

void check_spelling(char *sentence) {
    dict_t *dict = create_dict();
    char *word;
    int i, j;

    for (i = 0; sentence[i] != '\0'; i++) {
        word = sentence + i;
        for (j = 0; j < dict->size; j++) {
            if (strcmp(word, dict->words[j].word) == 0) {
                break;
            }
        }
        if (j == dict->size) {
            printf("Error: Unknown word: %s\n", word);
        }
    }

    free(dict);
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    check_spelling(sentence);
    return 0;
}