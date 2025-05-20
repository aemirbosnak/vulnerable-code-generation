//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: energetic
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
    }
}

int countWords(WordNode *head) {
    int count = 0;
    WordNode *current = head;

    while (current) {
        count++;
        current = current->next;
    }

    return count;
}

int main() {
    WordNode *head = NULL;
    char text[] = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    insertWord(&head, "The");
    insertWord(&head, "quick");
    insertWord(&head, "brown");
    insertWord(&head, "fox");
    insertWord(&head, "jumps");
    insertWord(&head, "over");
    insertWord(&head, "lazy");
    insertWord(&head, "dog");

    int numWords = countWords(head);

    printf("Number of words in the text: %d\n", numWords);

    return 0;
}