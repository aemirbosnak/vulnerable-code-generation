//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

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

void countWords(WordNode *head) {
    int wordCount = 0;
    WordNode *currentNode = head;

    while (currentNode) {
        wordCount++;
        currentNode = currentNode->next;
    }

    printf("Total number of words: %d\n", wordCount);
}

int main() {
    WordNode *head = NULL;

    char *words[] = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog", "a", "bright", "shiny", "morning"};

    for (int i = 0; i < 13; i++) {
        insertWord(head, words[i]);
    }

    countWords(head);

    return 0;
}