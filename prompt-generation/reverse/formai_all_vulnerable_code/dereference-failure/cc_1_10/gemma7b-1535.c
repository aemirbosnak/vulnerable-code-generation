//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insert(Node* head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
    head = newNode;
}

int countWords(Node* head) {
    int words = 0;
    char* currentWord = malloc(MAX);
    char* nextWord = malloc(MAX);

    currentWord = head->data;
    nextWord = NULL;

    while (currentWord) {
        if (nextWord == NULL) {
            words++;
            nextWord = currentWord;
            currentWord = head->next->data;
        } else if (strcmp(currentWord, nextWord) != 0) {
            words++;
            nextWord = currentWord;
            currentWord = head->next->data;
        } else {
            currentWord = head->next->data;
        }
    }

    return words;
}

int main() {
    Node* head = NULL;
    insert(head, 'a');
    insert(head, 'b');
    insert(head, 'c');
    insert(head, 'a');
    insert(head, 'd');

    int numWords = countWords(head);

    printf("Number of words: %d", numWords);

    return 0;
}