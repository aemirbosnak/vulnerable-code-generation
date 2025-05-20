//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct Node {
    char character;
    int frequency;
    struct Node* next;
} Node;

void insert(Node** head, char character, int frequency) {
    Node* newNode = malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        Node* previous = NULL;

        while (current) {
            if (newNode->character < current->character) {
                previous = current;
                current = current->next;
            } else if (previous) {
                previous->next = newNode;
                break;
            } else {
                *head = newNode;
                break;
            }
        }
    }
}

void printFreq(Node* head) {
    while (head) {
        printf("%c: %d\n", head->character, head->frequency);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    insert(&head, 'a', 5);
    insert(&head, 'b', 3);
    insert(&head, 'c', 2);
    insert(&head, 'd', 4);
    insert(&head, 'e', 6);

    printFreq(head);

    return 0;
}