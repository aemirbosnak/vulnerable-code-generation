//Gemma-7B DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    char **passwords;
    struct Node* next;
} Node;

void insertNode(struct Node** head, char** password) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->passwords = (char**)malloc(sizeof(char*) * MAX);
    newNode->passwords[0] = strdup(password);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void printPass(struct Node* head) {
    struct Node* current = head;
    while (current) {
        for (int i = 0; current->passwords[i] != NULL; i++) {
            printf("%s ", current->passwords[i]);
        }
        printf("\n");
        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;

    char** passwords = (char**)malloc(sizeof(char*) * MAX);
    passwords[0] = "MySuperSecret";
    passwords[1] = "Secret123";
    passwords[2] = "StrongPassword";

    insertNode(&head, passwords);

    printPass(head);

    return 0;
}