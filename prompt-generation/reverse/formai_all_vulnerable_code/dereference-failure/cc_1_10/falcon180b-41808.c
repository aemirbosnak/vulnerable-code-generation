//Falcon-180B DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DICTIONARY_SIZE 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency *words;
    int size;
} Dictionary;

Dictionary *createDictionary() {
    Dictionary *dict = (Dictionary *)malloc(sizeof(Dictionary));
    dict->words = (WordFrequency *)malloc(MAX_DICTIONARY_SIZE * sizeof(WordFrequency));
    dict->size = 0;
    return dict;
}

void destroyDictionary(Dictionary *dict) {
    free(dict->words);
    free(dict);
}

void addWord(Dictionary *dict, char *word) {
    WordFrequency *wordFreq = &dict->words[dict->size];
    strcpy(wordFreq->word, word);
    wordFreq->frequency = 1;
    dict->size++;
}

void printDictionary(Dictionary *dict) {
    printf("Dictionary:\n");
    for (int i = 0; i < dict->size; i++) {
        printf("%s: %d\n", dict->words[i].word, dict->words[i].frequency);
    }
}

int main() {
    Dictionary *dict = createDictionary();

    char input[MAX_WORD_LENGTH + 1];
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        input[strcspn(input, "\n")] = '\0';
        addWord(dict, input);
    }

    printDictionary(dict);

    destroyDictionary(dict);

    return 0;
}