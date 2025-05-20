//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: complete
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

void printWordFrequency(WordNode *head) {
    WordNode *traversingNode = head;
    while (traversingNode) {
        printf("%s: %d\n", traversingNode->word, traversingNode->frequency);
        traversingNode = traversingNode->next;
    }
}

int main() {
    WordNode *head = NULL;

    char *text = "This is a sample text with many words. The words are repeated many times. Some words are unique, while others are not.";

    char *words[MAX_WORDS];
    int i = 0;
    char *word = strtok(text, " ");

    while (word) {
        words[i++] = word;
        word = strtok(NULL, " ");
    }

    for (i = 0; i < MAX_WORDS; i++) {
        insertWord(head, words[i]);
    }

    printWordFrequency(head);

    return 0;
}