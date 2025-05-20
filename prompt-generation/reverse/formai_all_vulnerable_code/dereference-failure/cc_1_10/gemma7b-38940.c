//Gemma-7B DATASET v1.0 Category: Cryptography Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_KEY_SIZE 1024

typedef struct Node {
    char key[MAX_KEY_SIZE];
    struct Node* next;
} Node;

Node* createNode(char* key) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node* head, char* key) {
    Node* newNode = createNode(key);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        Node* previous = NULL;
        while (current) {
            if (strcmp(newNode->key, current->key) < 0) {
                previous = current;
                current = current->next;
            } else {
                break;
            }
        }
        if (previous) {
            previous->next = newNode;
        } else {
            head = newNode;
        }
    }
    return;
}

int searchNode(Node* head, char* key) {
    for (Node* current = head; current; current) {
        if (strcmp(key, current->key) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    Node* head = NULL;
    insertNode(head, "abc");
    insertNode(head, "bcd");
    insertNode(head, "cde");
    insertNode(head, "def");

    if (searchNode(head, "bcd") == 1) {
        printf("Key found!\n");
    }

    return 0;
}