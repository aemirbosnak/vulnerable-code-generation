//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct WordNode {
    char *word;
    int frequency;
    struct WordNode *next;
} WordNode;

WordNode *insertWord(WordNode *head, char *word) {
    WordNode *newNode = malloc(sizeof(WordNode));
    newNode->word = strdup(word);
    newNode->frequency = 1;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    WordNode *current = head;
    WordNode *previous = NULL;

    while (current) {
        if (strcmp(newNode->word, current->word) == 0) {
            current->frequency++;
            return head;
        } else if (previous) {
            previous = current;
            current = current->next;
        } else {
            previous = newNode;
            current = head;
        }
    }

    previous->next = newNode;
    return head;
}

int main() {
    WordNode *head = NULL;

    char *text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    insertWord(head, "the");
    insertWord(head, "quick");
    insertWord(head, "brown");
    insertWord(head, "fox");
    insertWord(head, "jumps");
    insertWord(head, "over");
    insertWord(head, "lazy");
    insertWord(head, "dog");

    printf("Word frequency:\n");
    WordNode *current = head;
    while (current) {
        printf("%s: %d\n", current->word, current->frequency);
    }

    return 0;
}