//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    WordCount* wordA = (WordCount*)a;
    WordCount* wordB = (WordCount*)b;
    return strcmp(wordA->word, wordB->word);
}

void printWords(int numWords, WordCount* words) {
    printf("Top %d most frequent words:\n", numWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char* inputText = NULL;
    size_t inputTextSize = 0;
    char* word;
    int numWords = 0;
    WordCount* words = NULL;

    // Read input text from user
    printf("Enter input text: ");
    if (fgets(inputText, MAX_WORD_LENGTH, stdin) == NULL) {
        printf("Error reading input text.\n");
        return 1;
    }
    inputTextSize = strlen(inputText);

    // Convert input text to lowercase
    for (int i = 0; i < inputTextSize; i++) {
        if (isalpha(inputText[i])) {
            inputText[i] = tolower(inputText[i]);
        }
    }

    // Count frequency of words
    words = malloc(MAX_WORDS * sizeof(WordCount));
    if (words == NULL) {
        printf("Error allocating memory for words.\n");
        return 1;
    }
    numWords = 0;
    word = strtok(inputText, " ");
    while (word!= NULL) {
        int index = 0;
        while (index < numWords && strcmp(words[index].word, word)!= 0) {
            index++;
        }
        if (index == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Error: too many words.\n");
                return 1;
            }
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        } else {
            words[index].count++;
        }
        word = strtok(NULL, " ");
    }

    // Sort words by frequency
    qsort(words, numWords, sizeof(WordCount), compareWords);

    // Print top N most frequent words
    int n = 10;
    printWords(n, words);

    // Free memory
    free(inputText);
    free(words);

    return 0;
}