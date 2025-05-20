//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: expert-level
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readDictionary(char* filename, WordCount dictionary[MAX_WORDS]) {
    FILE* file = fopen(filename, "r");
    char line[MAX_WORD_LENGTH];
    int i = 0;
    while (fgets(line, MAX_WORD_LENGTH, file)) {
        char* word = strtok(line, " \t\n\r\f\v");
        while (word!= NULL) {
            strcpy(dictionary[i].word, word);
            dictionary[i].count = 0;
            i++;
            if (i >= MAX_WORDS) {
                printf("Dictionary too large. Exiting.\n");
                exit(1);
            }
            word = strtok(NULL, " \t\n\r\f\v");
        }
    }
    fclose(file);
}

int compareWords(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

void spellCheck(char* filename, WordCount dictionary[MAX_WORDS]) {
    FILE* file = fopen(filename, "r");
    char line[MAX_WORD_LENGTH];
    char* word;
    while (fgets(line, MAX_WORD_LENGTH, file)) {
        word = strtok(line, " \t\n\r\f\v");
        while (word!= NULL) {
            int i;
            for (i = 0; i < MAX_WORDS; i++) {
                if (strcmp(word, dictionary[i].word) == 0) {
                    dictionary[i].count++;
                    break;
                }
            }
            if (i == MAX_WORDS) {
                printf("Unknown word: %s\n", word);
            }
            word = strtok(NULL, " \t\n\r\f\v");
        }
    }
    fclose(file);

    qsort(dictionary, MAX_WORDS, sizeof(WordCount), compareWords);

    for (int i = 0; i < MAX_WORDS; i++) {
        if (dictionary[i].count > 0) {
            printf("%s: %d\n", dictionary[i].word, dictionary[i].count);
        }
    }
}

int main() {
    WordCount dictionary[MAX_WORDS];
    readDictionary("dictionary.txt", dictionary);
    spellCheck("document.txt", dictionary);
    return 0;
}