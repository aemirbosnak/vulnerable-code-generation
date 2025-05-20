//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

void insertWord(Word **head, char *word) {
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->next = NULL;

    if (*head == NULL) {
        *head = newWord;
    } else {
        (*head)->next = newWord;
    }
}

int main() {
    Word *head = NULL;

    insertWord(&head, "apple");
    insertWord(&head, "banana");
    insertWord(&head, "cherry");
    insertWord(&head, "orange");
    insertWord(&head, "peach");
    insertWord(&head, "apricot");

    char *wordToSearch = "apricot";

    Word *currentWord = head;
    while (currentWord) {
        if (strcmp(currentWord->word, wordToSearch) == 0) {
            printf("Word found: %s\n", currentWord->word);
            break;
        }
        currentWord = currentWord->next;
    }

    if (currentWord == NULL) {
        printf("Word not found: %s\n", wordToSearch);
    }

    return 0;
}