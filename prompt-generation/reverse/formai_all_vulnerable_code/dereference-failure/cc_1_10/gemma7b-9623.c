//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct Word {
    char word[MAX_WORD_LENGTH];
    struct Word* next;
} Word;

void insertWord(Word** head, char* word) {
    Word* newNode = malloc(sizeof(Word));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int spellCheck(Word* head, char* word) {
    Word* currentWord = head;

    while (currentWord) {
        if (strcmp(currentWord->word, word) == 0) {
            return 1;
        }
        currentWord = currentWord->next;
    }

    return 0;
}

int main() {
    Word* head = NULL;
    insertWord(&head, "apple");
    insertWord(&head, "banana");
    insertWord(&head, "orange");
    insertWord(&head, "grape");

    char* wordToSearch = "apple";

    if (spellCheck(head, wordToSearch) == 1) {
        printf("Word found: %s\n", wordToSearch);
    } else {
        printf("Word not found: %s\n", wordToSearch);
    }

    return 0;
}