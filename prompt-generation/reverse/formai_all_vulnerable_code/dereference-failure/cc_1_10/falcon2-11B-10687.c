//Falcon2-11B DATASET v1.0 Category: Word Frequency Counter ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char* word;
    int frequency;
} WordFrequency;

WordFrequency* initializeDictionary() {
    WordFrequency* dictionary = (WordFrequency*)malloc(sizeof(WordFrequency));
    dictionary->word = NULL;
    dictionary->frequency = 0;
    return dictionary;
}

void freeDictionary(WordFrequency* dictionary) {
    free(dictionary->word);
    free(dictionary);
}

int countWords(const char* str, WordFrequency* dictionary) {
    int i = 0;
    int len = strlen(str);

    while (i < len) {
        int j = i;
        while (j < len &&!isspace(str[j])) {
            j++;
        }
        if (j == i || str[j] == '\0') {
            strcat(dictionary->word, str + i);
            dictionary->word[strlen(dictionary->word)] = '\0';
            dictionary->frequency++;
            i = j + 1;
        }
    }

    return i;
}

void printWordFrequencies(WordFrequency* dictionary) {
    for (int i = 0; i < dictionary->frequency; i++) {
        printf("%s: %d\n", dictionary->word, dictionary->frequency);
    }
}

int main() {
    WordFrequency* dictionary = initializeDictionary();
    const char* str = "Hello, world! This is a sample string. Hello, world!";

    int wordCount = countWords(str, dictionary);

    printf("Word Count: %d\n", wordCount);

    printWordFrequencies(dictionary);

    freeDictionary(dictionary);

    return 0;
}