//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

typedef struct {
    Word *words;
    int word_count;
} Dictionary;

void load_dictionary(Dictionary *dict, FILE *fp) {
    char line[MAX_WORD_LENGTH];
    Word word;

    dict->word_count = 0;
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        if (line[0]!= '\n') {
            strcpy(word.word, line);
            word.is_correct = true;
            dict->words[dict->word_count++] = word;
        }
    }
}

void check_word(Dictionary dict, char *word) {
    int i;
    bool is_correct = false;

    for (i = 0; i < dict.word_count; i++) {
        if (strcasecmp(dict.words[i].word, word) == 0) {
            is_correct = dict.words[i].is_correct;
            break;
        }
    }

    if (!is_correct) {
        printf("Possible spelling mistake: %s\n", word);
    }
}

int main() {
    FILE *fp;
    char line[MAX_WORD_LENGTH];
    Dictionary dict;

    fp = fopen("dictionary.txt", "r");

    if (fp == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    load_dictionary(&dict, fp);
    fclose(fp);

    while (fgets(line, MAX_WORD_LENGTH, stdin)!= NULL) {
        char *word = strtok(line, " \t\n\r\f\v,.?!;:");

        while (word!= NULL) {
            check_word(dict, word);
            word = strtok(NULL, " \t\n\r\f\v,.?!;:");
        }
    }

    return 0;
}