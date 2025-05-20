//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define ALPHABET_SIZE 26

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

char* generateRandomString(int length) {
    char* result = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        result[i] = 'a' + rand() % ALPHABET_SIZE;
    }
    result[length] = '\0';
    return result;
}

void countWordFrequencies(char* text, WordFrequency* wordFrequencies) {
    memset(wordFrequencies, 0, sizeof(WordFrequency) * MAX_WORDS);
    char* word = strtok(text, " ");
    while (word!= NULL) {
        int index = tolower(word[0]) - 'a';
        if (index >= 0 && index < ALPHABET_SIZE) {
            wordFrequencies[index].frequency++;
        }
        word = strtok(NULL, " ");
    }
}

void printWordFrequencies(WordFrequency* wordFrequencies) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (wordFrequencies[i].frequency > 0) {
            printf("%c: %d\n", 'a' + i, wordFrequencies[i].frequency);
        }
    }
}

int main() {
    srand(time(NULL));

    char* text = generateRandomString(1000);
    WordFrequency wordFrequencies[ALPHABET_SIZE];

    countWordFrequencies(text, wordFrequencies);
    printWordFrequencies(wordFrequencies);

    free(text);
    return 0;
}