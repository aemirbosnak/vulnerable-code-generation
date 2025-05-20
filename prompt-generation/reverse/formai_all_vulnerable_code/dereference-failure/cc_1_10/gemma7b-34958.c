//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000

typedef struct WordNode {
    char *word;
    struct WordNode *next;
} WordNode;

WordNode *insertWord(WordNode *head, char *word) {
    WordNode *newNode = malloc(sizeof(WordNode));
    newNode->word = strdup(word);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = insertWord(head->next, word);
    }

    return head;
}

int wordFrequency(WordNode *head, char *word) {
    WordNode *current = head;

    while (current) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    WordNode *head = NULL;

    insertWord(head, "apple");
    insertWord(head, "banana");
    insertWord(head, "cherry");
    insertWord(head, "apple");
    insertWord(head, "orange");

    int frequency = wordFrequency(head, "apple");

    if (frequency) {
        printf("The word 'apple' appears %d times.\n", frequency);
    } else {
        printf("The word 'apple' does not appear in the list.\n");
    }

    return 0;
}