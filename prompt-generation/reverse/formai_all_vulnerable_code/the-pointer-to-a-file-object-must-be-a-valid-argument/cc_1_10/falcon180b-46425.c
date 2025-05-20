//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int len;
} Word;

int compareWords(const void* a, const void* b) {
    const Word* wordA = (const Word*)a;
    const Word* wordB = (const Word*)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    // Read in file
    FILE* fp = fopen("input.txt", "r");
    char line[MAX_WORD_LEN];
    char word[MAX_WORD_LEN];
    int wordCount = 0;
    Word words[MAX_WORDS];

    while (fgets(line, MAX_WORD_LEN, fp)!= NULL) {
        char* token = strtok(line, " ");
        while (token!= NULL) {
            strcpy(word, token);
            int len = strlen(word);
            if (len > 0 && isalpha(word[0])) {
                if (wordCount >= MAX_WORDS) {
                    printf("Error: Maximum number of words reached.\n");
                    exit(1);
                }
                strcpy(words[wordCount].word, word);
                words[wordCount].len = len;
                wordCount++;
            }
            token = strtok(NULL, " ");
        }
    }

    // Sort words by length
    qsort(words, wordCount, sizeof(Word), compareWords);

    // Print sorted words
    for (int i = 0; i < wordCount; i++) {
        printf("%s (%d)\n", words[i].word, words[i].len);
    }

    return 0;
}