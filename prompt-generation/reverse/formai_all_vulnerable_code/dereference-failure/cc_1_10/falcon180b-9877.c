//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32
#define MAX_NUM_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *w1 = (WordCount *)a;
    WordCount *w2 = (WordCount *)b;
    return strcmp(w1->word, w2->word);
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int isWord(char c) {
    return isalpha(c) || c == '-';
}

void processLine(char *line, WordCount *wordCounts, int numWords) {
    char *word = strtok(line, " ");
    while (word!= NULL) {
        int wordLength = strlen(word);
        if (wordLength > MAX_WORD_LENGTH) {
            printf("Error: word is too long (%d characters)\n", wordLength);
            exit(1);
        }
        if (numWords >= MAX_NUM_WORDS) {
            printf("Error: too many words\n");
            exit(1);
        }
        WordCount *wc = &wordCounts[numWords];
        strcpy(wc->word, word);
        wc->count = 1;
        numWords++;
        word = strtok(NULL, " ");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    WordCount wordCounts[MAX_NUM_WORDS];
    int numWords = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        processLine(line, wordCounts, numWords);
    }
    fclose(file);
    printWordCounts(wordCounts, numWords);
    return 0;
}