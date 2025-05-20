//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct WordNode {
    char *word;
    struct WordNode *next;
} WordNode;

void insertWord(WordNode **head, char *word) {
    WordNode *newNode = malloc(sizeof(WordNode));
    newNode->word = strdup(word);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
        *head = newNode;
    }
}

void countWords(WordNode *head) {
    int count = 0;
    WordNode *current = head;

    while (current) {
        count++;
        current = current->next;
    }

    printf("Total number of words: %d\n", count);
}

int main() {
    WordNode *head = NULL;

    insertWord(&head, "The");
    insertWord(&head, "quick");
    insertWord(&head, "brown");
    insertWord(&head, "fox");
    insertWord(&head, "jumps");
    insertWord(&head, "over");
    insertWord(&head, "the");
    insertWord(&head, "lazy");

    countWords(head);

    return 0;
}