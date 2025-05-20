//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: satisfied
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
    char text[] = "This is a sample text with many words. The words are repeated several times. Some words are unique, while others are not.";

    insertWord(&head, "the");
    insertWord(&head, "is");
    insertWord(&head, "a");
    insertWord(&head, "sample");
    insertWord(&head, "text");
    insertWord(&head, "with");
    insertWord(&head, "many");
    insertWord(&head, "words");
    insertWord(&head, "are");
    insertWord(&head, "repeated");
    insertWord(&head, "several");
    insertWord(&head, "times");
    insertWord(&head, "some");
    insertWord(&head, "words");
    insertWord(&head, "are");
    insertWord(&head, "unique");
    insertWord(&head, "while");
    insertWord(&head, "others");
    insertWord(&head, "are");
    insertWord(&head, "not");

    int wordCount = countWords(head);

    printf("Total number of words: %d\n", wordCount);

    return 0;
}