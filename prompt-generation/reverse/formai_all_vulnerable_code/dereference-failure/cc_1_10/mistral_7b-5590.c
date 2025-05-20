//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define ELEMENT_SIZE sizeof(struct Node)

typedef struct Node {
    char data[10];
    int len;
    struct Node* next;
} Node;

Node* createNode(const char* data) {
    Node* newNode = (Node*) malloc(ELEMENT_SIZE);
    strncpy(newNode->data, data, sizeof(newNode->data));
    newNode->len = strlen(newNode->data);
    newNode->next = NULL;
    return newNode;
}

Node* createList() {
    Node* head = NULL;
    Node* newNode;

    while (1) {
        printf("Enter data (or 'q' to quit): ");
        char input[10];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "q") == 0)
            break;

        newNode = createNode(input);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%.*s\tLen: %d\tNext: %p\n", current->len, current->data, current->len, current->next);
        current = current->next;
    }
}

void deleteNode(Node** head, const char* data) {
    Node* current = *head;
    Node* previous = NULL;

    while (current != NULL && strcmp(current->data, data) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node not found.\n");
        return;
    }

    if (previous == NULL)
        *head = current->next;
    else
        previous->next = current->next;

    free(current);
}

int main() {
    Node* list = NULL;

    printf("Creating list:\n");
    list = createList();

    printf("\nPrinting list:\n");
    printList(list);

    char deleteData[10];
    printf("\nEnter data to delete: ");
    fgets(deleteData, sizeof(deleteData), stdin);
    deleteData[strcspn(deleteData, "\n")] = '\0';

    deleteNode(&list, deleteData);

    printf("\nPrinting list after deletion:\n");
    printList(list);

    return 0;
}