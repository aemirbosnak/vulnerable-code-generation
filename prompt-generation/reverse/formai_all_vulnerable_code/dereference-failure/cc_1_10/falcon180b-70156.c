//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DIC_FILE "dictionary.txt"
#define WORD_LEN_MAX 20

typedef struct {
    char word[WORD_LEN_MAX];
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency *words;
    int length;
} Dictionary;

void loadDictionary(Dictionary *dict) {
    FILE *fp;
    char line[100];
    char *word;
    int i = 0;

    fp = fopen(DIC_FILE, "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file\n");
        exit(1);
    }

    while (fgets(line, 100, fp)!= NULL) {
        word = strtok(line, " ");
        while (word!= NULL) {
            if (i >= dict->length) {
                dict->length += 10;
                dict->words = realloc(dict->words, dict->length * sizeof(WordFrequency));
            }
            strcpy(dict->words[i].word, word);
            dict->words[i].frequency = 0;
            i++;
            word = strtok(NULL, " ");
        }
    }

    fclose(fp);
}

int compareWords(const void *a, const void *b) {
    const WordFrequency *word1 = a;
    const WordFrequency *word2 = b;

    return strcmp(word1->word, word2->word);
}

void sortDictionary(Dictionary *dict) {
    qsort(dict->words, dict->length, sizeof(WordFrequency), compareWords);
}

int isWordInDictionary(Dictionary *dict, char *word) {
    int i;
    for (i = 0; i < dict->length; i++) {
        if (strcmp(dict->words[i].word, word) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *fp;
    char line[1000];
    char *word;
    int i, j;
    Dictionary dict;

    loadDictionary(&dict);
    sortDictionary(&dict);

    fp = fopen("text.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open input file\n");
        exit(1);
    }

    while (fgets(line, 1000, fp)!= NULL) {
        word = strtok(line, " ");
        while (word!= NULL) {
            if (!isWordInDictionary(&dict, word)) {
                printf("Possible spelling error: %s\n", word);
            }
            word = strtok(NULL, " ");
        }
        printf("\n");
    }

    fclose(fp);

    return 0;
}