//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

typedef struct {
    int num_words;
    Word words[MAX_WORDS];
} Dictionary;

void load_dictionary(Dictionary* dict) {
    FILE* file = fopen("dictionary.txt", "r");
    char line[MAX_WORD_LENGTH];
    int i = 0;
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        strtok(line, " ");
        while (strtok(NULL, " ")!= NULL) {
            if (i >= MAX_WORDS) {
                break;
            }
            strcpy(dict->words[i].word, line);
            dict->words[i].is_correct = true;
            i++;
        }
    }
    fclose(file);
}

bool is_word_correct(Dictionary* dict, char* word) {
    int i = 0;
    while (i < dict->num_words && strcmp(dict->words[i].word, word)!= 0) {
        i++;
    }
    return dict->words[i].is_correct;
}

void correct_word(char* word) {
    char* correct_word = NULL;
    int i = 0;
    while (i < strlen(word)) {
        if (isalpha(word[i])) {
            correct_word = realloc(correct_word, strlen(correct_word) + 1);
            strcat(correct_word, toupper(word[i]));
        }
        i++;
    }
    if (correct_word!= NULL) {
        printf("%s\n", correct_word);
    } else {
        printf("No suggestions\n");
    }
}

int main() {
    Dictionary dict;
    load_dictionary(&dict);
    char input[MAX_WORD_LENGTH];
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        int i = 0;
        char* word = strtok(input, " ");
        while (word!= NULL) {
            if (!is_word_correct(&dict, word)) {
                correct_word(word);
            }
            word = strtok(NULL, " ");
        }
    }
    return 0;
}