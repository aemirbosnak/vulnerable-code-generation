//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

typedef struct Node {
    char character;
    int frequency;
    struct Node* next;
} Node;

Node* insert(Node* head, char character, int frequency) {
    Node* newNode = malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        Node* previous = NULL;
        while (current) {
            if (newNode->character == current->character) {
                current->frequency++;
                previous = NULL;
                break;
            } else if (newNode->character < current->character) {
                previous = current;
                current = current->next;
            } else {
                previous = current;
                current = current->next;
            }
        }

        if (previous) {
            previous->next = newNode;
        } else {
            head = newNode;
        }
    }

    return head;
}

void huffman_encode(Node* head, char* message) {
    char* encodedMessage = malloc(MAX);
    int i = 0;

    for (int j = 0; message[j] != '\0'; j++) {
        Node* current = head;
        while (current) {
            if (message[j] == current->character) {
                encodedMessage[i++] = current->character;
                encodedMessage[i++] = current->frequency;
                break;
            }
            current = current->next;
        }
    }

    printf("%s\n", encodedMessage);
    free(encodedMessage);
}

int main() {
    char* message = "This is a message to be encoded.";
    Node* head = insert(NULL, 'a', 3);
    insert(head, 'e', 2);
    insert(head, 'h', 1);
    insert(head, 'i', 2);
    insert(head, 'n', 2);
    insert(head, 'o', 2);
    insert(head, 'r', 2);
    insert(head, 's', 2);
    insert(head, 't', 3);
    insert(head, 'y', 1);

    huffman_encode(head, message);

    return 0;
}