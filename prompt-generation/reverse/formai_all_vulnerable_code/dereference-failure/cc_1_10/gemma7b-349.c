//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: interoperable
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

void printWordFrequency(WordNode *head) {
    printf("Word frequency:\n");
    WordNode *traverse = head;
    while (traverse) {
        printf("%s: %d\n", traverse->word, traverse->frequency);
        traverse = traverse->next;
    }
}

int main() {
    WordNode *head = NULL;

    char *text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    char *words[] = {"quick", "brown", "fox", "jumps", "over", "lazy", "dog"};

    for (int i = 0; i < 7; i++) {
        insertWord(head, words[i]);
    }

    printWordFrequency(head);

    return 0;
}