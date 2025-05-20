//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;
    if (wordA->frequency > wordB->frequency) {
        return -1;
    } else if (wordA->frequency < wordB->frequency) {
        return 1;
    } else {
        return 0;
    }
}

void printWordFrequency(WordFrequency *wordFrequency, int numWords) {
    qsort(wordFrequency, numWords, sizeof(WordFrequency), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequency[i].word, wordFrequency[i].frequency);
    }
}

int main() {
    FILE *file;
    char ch;
    char word[MAX_WORD_LENGTH];
    int wordLength = 0;
    int numWords = 0;
    WordFrequency *wordFrequency = NULL;

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[wordLength++] = tolower(ch);
        } else if (wordLength > 0) {
            word[wordLength] = '\0';
            if (numWords >= MAX_WORD_LENGTH) {
                printf("Error: too many words.\n");
                exit(1);
            }
            wordFrequency[numWords].word = strdup(word);
            wordFrequency[numWords].frequency = 1;
            numWords++;
            wordLength = 0;
        }
    }

    if (wordLength > 0) {
        word[wordLength] = '\0';
        if (numWords >= MAX_WORD_LENGTH) {
            printf("Error: too many words.\n");
            exit(1);
        }
        wordFrequency[numWords].word = strdup(word);
        wordFrequency[numWords].frequency = 1;
        numWords++;
    }

    fclose(file);

    wordFrequency = realloc(wordFrequency, sizeof(WordFrequency) * numWords);
    printWordFrequency(wordFrequency, numWords);

    for (int i = 0; i < numWords; i++) {
        free(wordFrequency[i].word);
    }
    free(wordFrequency);

    return 0;
}