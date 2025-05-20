//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum word length
#define MAX_WORD_LENGTH 50

struct wordList {
    char word[MAX_WORD_LENGTH];
    int count;
    struct wordList* next;
};

struct wordList* createNewWord(char* word) {
    struct wordList* newWord = (struct wordList*) malloc(sizeof(struct wordList));
    strcpy(newWord->word, word);
    newWord->count = 1;
    newWord->next = NULL;
    return newWord;
}

void addWordToList(struct wordList** list, char* word) {
    if (*list == NULL) {
        *list = createNewWord(word);
        return;
    }
    struct wordList* curr = *list;
    // search for the word in the list
    while (curr != NULL) {
        if (strcmp(curr->word, word) == 0) {
            curr->count++;
            return;
        }
        curr = curr->next;
    }
    // the word is not in the list, add it to the front
    struct wordList* newWord = createNewWord(word);
    newWord->next = *list;
    *list = newWord;
}

void printWordList(struct wordList* list) {
    printf("Word\t\tFrequency\n");
    while (list != NULL) {
        printf("%s\t\t%d\n", list->word, list->count);
        list = list->next;
    }
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    fgets(str, 1000, stdin);
    // remove the newline character from fgets
    str[strcspn(str, "\n")] = 0;

    struct wordList* list = NULL;

    char* token = strtok(str, " ");
    while (token != NULL) {
        addWordToList(&list, token);
        token = strtok(NULL, " ");
    }

    printWordList(list);

    return 0;
}