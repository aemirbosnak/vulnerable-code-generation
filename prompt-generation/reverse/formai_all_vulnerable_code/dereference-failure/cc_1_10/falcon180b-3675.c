//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define WORD_LEN 20

typedef struct {
    char word[WORD_LEN];
    int count;
} WordFrequency;

int compare(const void *a, const void *b) {
    int result = strcmp(*(char **)a, *(char **)b);
    return result;
}

void countWords(char *text, WordFrequency *wordFreq) {
    int len = strlen(text);
    char *word = malloc(WORD_LEN * sizeof(char));
    int i = 0;
    while (i < len) {
        if (isalpha(text[i])) {
            strcpy(word, "");
            while (isalpha(text[i])) {
                strcat(word, tolower(text[i]));
                i++;
            }
            word[strlen(word) - 1] = '\0';
            WordFrequency *found = bsearch(word, wordFreq, MAX_WORDS, sizeof(WordFrequency), compare);
            if (found == NULL) {
                found = wordFreq + MAX_WORDS - 1;
                strcpy(found->word, word);
                found->count = 1;
            } else {
                found->count++;
            }
        } else {
            i++;
        }
    }
    free(word);
}

void printWordFrequency(WordFrequency *wordFreq) {
    qsort(wordFreq, MAX_WORDS, sizeof(WordFrequency), compare);
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(wordFreq[i].word, "")!= 0) {
            printf("%s: %d\n", wordFreq[i].word, wordFreq[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }
    char *text = malloc(1000000 * sizeof(char));
    fseek(file, 0L, SEEK_END);
    int len = ftell(file);
    rewind(file);
    fread(text, sizeof(char), len, file);
    fclose(file);
    WordFrequency wordFreq[MAX_WORDS];
    countWords(text, wordFreq);
    printWordFrequency(wordFreq);
    free(text);
    return 0;
}