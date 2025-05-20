//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

typedef struct WordNode {
    char *word;
    struct WordNode *next;
} WordNode;

WordNode *insertWord(WordNode *head, char *word) {
    WordNode *newNode = malloc(sizeof(WordNode));
    newNode->word = strdup(word);
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    WordNode *curr = head;
    WordNode *prev = NULL;

    while (curr) {
        if (strcmp(newNode->word, curr->word) == 0) {
            return head;
        } else if (prev) {
            prev = curr;
            curr = curr->next;
        } else {
            prev = newNode;
            curr = head;
        }
    }

    prev->next = newNode;
    return head;
}

void printWordFreq(WordNode *head) {
    WordNode *curr = head;

    while (curr) {
        printf("%s: %d\n", curr->word, 1);
        curr = curr->next;
    }
}

int main() {
    WordNode *head = NULL;

    char *text = "This is a sample text with many words. Some words are repeated multiple times. The quick brown fox jumps over the lazy dog.";

    char *words[] = {"the", "is", "a", "sample", "text", "with", "many", "words", "some", "words", "are", "repeated", "multiple", "times", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};

    for (int i = 0; i < 13; i++) {
        insertWord(head, words[i]);
    }

    printWordFreq(head);

    return 0;
}