//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

void countWords(char* text, int textLength, WordFrequency* words, int numWords) {
    char* wordStart = text;
    char* wordEnd;
    int wordLength;

    while (numWords > 0) {
        wordEnd = strpbrk(wordStart, ",.?!;:\"'()[]{}<>");
        if (wordEnd == NULL) {
            break;
        }

        wordLength = wordEnd - wordStart;
        if (wordLength > 0 && wordLength <= MAX_WORD_LENGTH) {
            strncpy(words[numWords].word, wordStart, MAX_WORD_LENGTH);
            words[numWords].word[wordLength] = '\0';
            words[numWords].frequency++;
            numWords--;
        }

        wordStart = wordEnd + 1;
    }
}

void sortWords(WordFrequency* words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);
}

void printWords(WordFrequency* words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    FILE* file;
    char* text = NULL;
    long fileLength;
    WordFrequency* words = NULL;
    int numWords = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    fileLength = ftell(file);
    fseek(file, 0, SEEK_SET);

    text = malloc(fileLength + 1);
    if (text == NULL) {
        printf("Error: Could not allocate memory for text.\n");
        fclose(file);
        return 1;
    }

    fread(text, fileLength, 1, file);
    text[fileLength] = '\0';
    fclose(file);

    words = malloc(MAX_WORDS * sizeof(WordFrequency));
    if (words == NULL) {
        printf("Error: Could not allocate memory for words.\n");
        free(text);
        return 1;
    }

    countWords(text, strlen(text), words, MAX_WORDS);
    sortWords(words, numWords);
    printWords(words, numWords);

    free(text);
    free(words);

    return 0;
}