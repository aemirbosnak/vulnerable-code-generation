//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: automated
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

int wordFrequency(WordNode *head, char *word) {
    int frequency = 0;
    WordNode *current = head;

    while (current) {
        if (strcmp(current->word, word) == 0) {
            frequency++;
        }
        current = current->next;
    }

    return frequency;
}

int main() {
    WordNode *head = NULL;
    char *text = "This is a sample text with many words. The word frequency counter is a tool to count the frequency of each word in a text.";

    insertWord(&head, "the");
    insertWord(&head, "is");
    insertWord(&head, "a");
    insertWord(&head, "sample");
    insertWord(&head, "text");
    insertWord(&head, "with");
    insertWord(&head, "many");
    insertWord(&head, "words");
    insertWord(&head, "The");
    insertWord(&head, "word");
    insertWord(&head, "frequency");
    insertWord(&head, "counter");
    insertWord(&head, "is");
    insertWord(&head, "a");
    insertWord(&head, "tool");
    insertWord(&head, "to");
    insertWord(&head, "count");
    insertWord(&head, "the");
    insertWord(&head, "frequency");
    insertWord(&head, "of");
    insertWord(&head, "each");
    insertWord(&head, "word");
    insertWord(&head, "in");
    insertWord(&head, "a");
    insertWord(&head, "text");

    char *wordToSearch = "the";

    int frequency = wordFrequency(head, wordToSearch);

    printf("The frequency of the word '%s' is: %d\n", wordToSearch, frequency);

    return 0;
}