//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1024

typedef struct WordNode {
    char *word;
    struct WordNode *next;
} WordNode;

WordNode *word_insert(WordNode *head, char *word) {
    WordNode *newNode = malloc(sizeof(WordNode));
    newNode->word = strdup(word);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void word_count(WordNode *head) {
    int word_count = 0;
    WordNode *current = head;

    while (current) {
        word_count++;
        current = current->next;
    }

    printf("Total number of words: %d\n", word_count);
}

int main() {
    WordNode *head = NULL;
    char text[] = "This is a sample text for the word frequency counter. It contains many words, some repeated twice.";

    // Insert words into the linked list
    word_insert(head, "the");
    word_insert(head, "is");
    word_insert(head, "a");
    word_insert(head, "sample");
    word_insert(head, "text");
    word_insert(head, "for");
    word_insert(head, "the");
    word_insert(head, "words");
    word_insert(head, "some");
    word_insert(head, "repeated");
    word_insert(head, "twice");

    // Count the number of words
    word_count(head);

    return 0;
}