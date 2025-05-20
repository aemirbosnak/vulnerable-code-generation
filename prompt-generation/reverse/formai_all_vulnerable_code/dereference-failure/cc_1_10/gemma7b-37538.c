//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: scalable
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

Word **insertWord(Word **head, char *word) {
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->next = NULL;

    if (*head == NULL) {
        *head = newWord;
    } else {
        (*head)->next = insertWord(head, word);
    }

    return head;
}

int spellCheck(Word **head, char *word) {
    Word *currentWord = *head;

    while (currentWord) {
        if (strcmp(currentWord->word, word) == 0) {
            return 1;
        }
        currentWord = currentWord->next;
    }

    return 0;
}

int main() {
    Word **head = NULL;

    insertWord(&head, "apple");
    insertWord(&head, "banana");
    insertWord(&head, "cherry");
    insertWord(&head, "orange");

    if (spellCheck(head, "apple") == 1) {
        printf("Apple is in the list.\n");
    }

    if (spellCheck(head, "banana") == 1) {
        printf("Banana is in the list.\n");
    }

    if (spellCheck(head, "grape") == 0) {
        printf("Grape is not in the list.\n");
    }

    return 0;
}