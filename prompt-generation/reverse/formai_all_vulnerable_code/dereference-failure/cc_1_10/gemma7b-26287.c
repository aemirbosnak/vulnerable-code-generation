//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: multiplayer
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

int findWord(WordNode *head, char *word) {
    for (WordNode *node = head; node; node = node->next) {
        if (strcmp(node->word, word) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    WordNode *head = NULL;

    // Multiplayer part
    char word1[] = "Hello";
    insertWord(head, word1);

    char word2[] = "World";
    insertWord(head, word2);

    char word3[] = "Test";
    insertWord(head, word3);

    // Check if word exists
    if (findWord(head, word2) == 1) {
        printf("Word found: %s\n", word2);
    } else {
        printf("Word not found: %s\n", word2);
    }

    return 0;
}