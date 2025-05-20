//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: safe
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
        WordNode *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void printWordFrequency(WordNode *head) {
    WordNode *temp = head;
    int frequency = 0;
    while (temp) {
        char *word = temp->word;
        frequency = 0;
        for (WordNode *iter = head; iter; iter = iter->next) {
            if (strcmp(word, iter->word) == 0) {
                frequency++;
            }
        }
        printf("%s: %d\n", word, frequency);
        temp = temp->next;
    }
}

int main() {
    WordNode *head = NULL;
    char text[] = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    insertWord(head, "the");
    insertWord(head, "quick");
    insertWord(head, "brown");
    insertWord(head, "fox");
    insertWord(head, "jumps");
    insertWord(head, "over");
    insertWord(head, "lazy");
    insertWord(head, "dog");

    printWordFrequency(head);

    return 0;
}