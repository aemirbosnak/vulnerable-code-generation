//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: calm
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
        return newNode;
    }

    WordNode *traversal = head;
    while (traversal->next) {
        traversal = traversal->next;
    }

    traversal->next = newNode;
    return head;
}

void printWordFrequency(WordNode *head) {
    WordNode *traversal = head;
    int wordCount = 0;
    while (traversal) {
        wordCount++;
        printf("%s: %d\n", traversal->word, wordCount);
        traversal = traversal->next;
    }
}

int main() {
    WordNode *head = NULL;
    char *text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    insertWord(head, "the");
    insertWord(head, "quick");
    insertWord(head, "brown");
    insertWord(head, "fox");
    insertWord(head, "jumps");
    insertWord(head, "lazy");
    insertWord(head, "over");
    insertWord(head, "dog");

    printWordFrequency(head);

    return 0;
}