//Gemma-7B DATASET v1.0 Category: Text processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

Word *createWordList(int size) {
    Word *head = malloc(sizeof(Word));
    head->word = malloc(size * sizeof(char));
    head->next = NULL;

    return head;
}

void addWordToList(Word *head, char *word) {
    Word *newWord = malloc(sizeof(Word));
    newWord->word = malloc(strlen(word) * sizeof(char));
    strcpy(newWord->word, word);
    newWord->next = NULL;

    if (head->next) {
        head->next->next = newWord;
    } else {
        head->next = newWord;
    }
}

void printWordList(Word *head) {
    Word *currWord = head->next;
    while (currWord) {
        printf("%s ", currWord->word);
        currWord = currWord->next;
    }
    printf("\n");
}

int main() {
    Word *wordList = createWordList(MAX_WORDS);
    addWordToList(wordList, "Hello");
    addWordToList(wordList, "World");
    addWordToList(wordList, "!");

    printWordList(wordList);

    return 0;
}