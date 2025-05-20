//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define WORD_LEN 20

typedef struct {
    char word[WORD_LEN];
    int freq;
} WordFreq;

int compare(const void* a, const void* b) {
    WordFreq* w1 = (WordFreq*)a;
    WordFreq* w2 = (WordFreq*)b;
    return strcmp(w1->word, w2->word);
}

int main() {
    FILE* fp;
    char line[100];
    char* token;
    WordFreq* words = (WordFreq*)malloc(MAX_WORDS * sizeof(WordFreq));
    int num_words = 0;
    int i;

    // Open input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Read input file and count word frequencies
    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",.!?;:");
        while (token!= NULL) {
            if (strlen(token) > WORD_LEN) {
                token[WORD_LEN - 1] = '\0';
            }
            strcpy(words[num_words].word, token);
            words[num_words].freq++;
            num_words++;
            token = strtok(NULL, ",.!?;:");
        }
    }

    // Sort words by frequency
    qsort(words, num_words, sizeof(WordFreq), compare);

    // Print word frequencies
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].freq);
    }

    // Free memory
    free(words);

    // Close input file
    fclose(fp);

    return 0;
}