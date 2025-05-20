//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

typedef struct Node {
    char character;
    int frequency;
    struct Node* next;
} Node;

void insertNode(Node** head, char character, int frequency) {
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
            } else {
                break;
            }
        }
        if (previous) {
            previous->next = newNode;
        } else {
            *head = newNode;
        }
    }
}

void huffmanCoding(char* text) {
    Node* head = NULL;
    for (int i = 0; text[i] != '\0'; i++) {
        insertNode(&head, text[i], 1);
    }

    Node* current = head;
    while (current) {
        current->frequency /= 2;
        insertNode(&head, '#', current->frequency);
    }

    printf("Huffman Coding:\n");
    current = head;
    while (current) {
        printf("%c: %d\n", current->character, current->frequency);
    }
}

int main() {
    char text[] = "ABBABCAABBCA";
    huffmanCoding(text);

    return 0;
}