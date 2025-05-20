//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: single-threaded
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

int main() {
    char text[] = "This is a sample text with many words. Some words are repeated. The repetition of words is a common phenomenon in natural language processing.";
    WordNode *head = NULL;
    insertWord(head, "is");
    insertWord(head, "a");
    insertWord(head, "the");
    insertWord(head, "words");
    insertWord(head, "sample");
    insertWord(head, "with");
    insertWord(head, "many");
    insertWord(head, "some");
    insertWord(head, "repeated");
    insertWord(head, "common");
    insertWord(head, "phenomenon");

    int wordCount = 0;
    WordNode *current = head;
    while (current) {
        wordCount++;
        current = current->next;
    }

    printf("Total number of words: %d\n", wordCount);

    return 0;
}