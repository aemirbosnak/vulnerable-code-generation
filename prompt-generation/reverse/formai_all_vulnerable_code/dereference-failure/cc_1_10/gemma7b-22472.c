//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct WordNode {
    char *word;
    struct WordNode *next;
} WordNode;

WordNode *createWordNode(char *word) {
    WordNode *newNode = malloc(sizeof(WordNode));
    newNode->word = strdup(word);
    newNode->next = NULL;
    return newNode;
}

void insertWord(WordNode **head, char *word) {
    WordNode *newNode = createWordNode(word);
    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int searchWord(WordNode *head, char *word) {
    while (head) {
        if (strcmp(head->word, word) == 0) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int main() {
    WordNode *head = NULL;
    insertWord(&head, "apple");
    insertWord(&head, "banana");
    insertWord(&head, "orange");
    insertWord(&head, "grapefruit");

    if (searchWord(head, "apple") == 1) {
        printf("Apple found!\n");
    }

    if (searchWord(head, "banana") == 1) {
        printf("Banana found!\n");
    }

    return 0;
}