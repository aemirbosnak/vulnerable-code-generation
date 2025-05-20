//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

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
        WordNode *traversingNode = head;
        while (traversingNode->next) {
            traversingNode = traversingNode->next;
        }
        traversingNode->next = newNode;
    }

    return head;
}

int countWords(WordNode *head) {
    int count = 0;
    WordNode *traversingNode = head;
    while (traversingNode) {
        count++;
        traversingNode = traversingNode->next;
    }
    return count;
}

void printWords(WordNode *head) {
    WordNode *traversingNode = head;
    while (traversingNode) {
        printf("%s: %d\n", traversingNode->word, traversingNode->frequency);
        traversingNode = traversingNode->next;
    }
}

int main() {
    WordNode *head = NULL;

    // Insert some words
    insertWord(head, "apple");
    insertWord(head, "banana");
    insertWord(head, "orange");
    insertWord(head, "grape");
    insertWord(head, "apple");

    // Print the words and their frequencies
    printWords(head);

    // Count the number of words
    int numWords = countWords(head);
    printf("Number of words: %d\n", numWords);

    return 0;
}