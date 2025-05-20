//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: sophisticated
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

void countWordFrequencies(WordNode *head) {
    int wordCount = 0;
    WordNode *current = head;

    while (current) {
        wordCount++;
        current = current->next;
    }

    printf("Total number of words: %d\n", wordCount);

    current = head;

    while (current) {
        int frequency = 0;
        WordNode *previous = NULL;

        while (current) {
            if (strcmp(current->word, previous->word) == 0) {
                frequency++;
            }

            previous = current;
            current = current->next;
        }

        printf("%s: %d\n", current->word, frequency);
    }
}

int main() {
    WordNode *head = NULL;

    char *words[] = {"apple", "banana", "orange", "grape", "apple", "banana", "orange"};

    for (int i = 0; i < 7; i++) {
        insertWord(head, words[i]);
    }

    countWordFrequencies(head);

    return 0;
}