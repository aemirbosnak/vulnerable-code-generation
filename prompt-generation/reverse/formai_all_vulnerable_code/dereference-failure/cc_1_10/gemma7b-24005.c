//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: realistic
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

int main() {
    WordNode *head = NULL;
    char text[] = "This is a sample text with many words. The text contains some repeated words, such as the word 'the'.";

    // Insert words into the linked list
    insertWord(&head, "This");
    insertWord(&head, "is");
    insertWord(&head, "a");
    insertWord(&head, "sample");
    insertWord(&head, "text");
    insertWord(&head, "with");
    insertWord(&head, "many");
    insertWord(&head, "words");
    insertWord(&head, "The");
    insertWord(&head, "text");
    insertWord(&head, "contains");
    insertWord(&head, "some");
    insertWord(&head, "repeated");
    insertWord(&head, "words");
    insertWord(&head, "such");
    insertWord(&head, "as");
    insertWord(&head, "the");
    insertWord(&head, "word");

    // Create a word frequency table
    int wordFrequency[MAX_WORDS] = {0};
    WordNode *current = head;
    while (current) {
        wordFrequency[strcmp(current->word, "")]++;
        current = current->next;
    }

    // Print the word frequency table
    printf("Word frequency table:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (wordFrequency[i] > 0) {
            printf("%s: %d\n", wordFrequency[i], wordFrequency[i]);
        }
    }

    return 0;
}