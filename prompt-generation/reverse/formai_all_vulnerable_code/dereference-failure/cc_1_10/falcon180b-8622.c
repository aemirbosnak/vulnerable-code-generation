//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void readFile(char* filename, char* buffer) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    while (fgets(buffer, MAX_WORD_LEN, file)!= NULL) {
        int len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
    }
    fclose(file);
}

void countWords(char* buffer, WordCount* wordCounts) {
    char* word = strtok(buffer, ",.!?;:");
    while (word!= NULL) {
        int len = strlen(word);
        if (len > MAX_WORD_LEN) {
            len = MAX_WORD_LEN;
        }
        strncpy(wordCounts[0].word, word, len);
        wordCounts[0].count++;
        word = strtok(NULL, ",.!?;:");
        if (wordCounts[0].count >= MAX_WORDS) {
            break;
        }
    }
}

void printWordCounts(WordCount* wordCounts) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (wordCounts[i].count > 0) {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    char filename[MAX_WORD_LEN];
    strcpy(filename, argv[1]);
    char buffer[MAX_WORD_LEN];
    readFile(filename, buffer);
    WordCount wordCounts[MAX_WORDS];
    countWords(buffer, wordCounts);
    printWordCounts(wordCounts);
    return 0;
}