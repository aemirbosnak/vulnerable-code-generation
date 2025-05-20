//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHTABLE_SIZE 10

typedef struct Node {
    char password[256];
    struct Node* next;
} Node;

Node* insert(Node* head, char* password) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->password, password);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newNode;
    }

    return head;
}

int checkStrength(Node* head, char* password) {
    for (Node* current = head; current; current = current->next) {
        if (strcmp(current->password, password) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    Node* head = NULL;

    insert(head, "qwerty");
    insert(head, "12345");
    insert(head, "SuperSecret");

    char* password = "Hello";

    if (checkStrength(head, password) == 1) {
        printf("Password found!\n");
    } else {
        printf("Password not found.\n");
    }

    return 0;
}