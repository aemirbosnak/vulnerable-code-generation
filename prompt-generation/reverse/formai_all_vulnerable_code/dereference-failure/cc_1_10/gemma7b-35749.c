//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000

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
        head = newNode;
    } else {
        WordNode *traverse = head;
        while (traverse->next) {
            traverse = traverse->next;
        }
        traverse->next = newNode;
    }

    return head;
}

int countWords(WordNode *head) {
    int count = 0;
    WordNode *traverse = head;
    while (traverse) {
        count++;
        traverse = traverse->next;
    }
    return count;
}

void printWordFrequency(WordNode *head) {
    WordNode *traverse = head;
    printf("Word frequency:\n");
    while (traverse) {
        printf("%s: %d\n", traverse->word, traverse->frequency);
        traverse = traverse->next;
    }
}

int main() {
    WordNode *head = NULL;
    char *text = "This is a sample text for word frequency counting. The text contains many words, including some repeated words. Some words, such as the word 'the', appear multiple times.";

    insertWord(head, text);

    printWordFrequency(head);

    printf("Number of words: %d\n", countWords(head));

    return 0;
}