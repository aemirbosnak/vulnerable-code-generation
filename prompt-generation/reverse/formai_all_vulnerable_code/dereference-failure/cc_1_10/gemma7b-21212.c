//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void printWordFrequency(WordNode *head) {
    WordNode *currNode = head;
    int wordCount = 0;
    char *word = NULL;

    while (currNode) {
        word = currNode->word;

        if (wordCount == 0) {
            printf("%s:", word);
        } else {
            printf(", %s:", word);
        }

        wordCount++;

        currNode = currNode->next;
    }

    printf("\n");
}

int main() {
    WordNode *head = NULL;

    insertWord(head, "apple");
    insertWord(head, "banana");
    insertWord(head, "orange");
    insertWord(head, "apple");
    insertWord(head, "banana");

    printWordFrequency(head);

    return 0;
}