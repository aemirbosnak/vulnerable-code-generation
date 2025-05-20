//FormAI DATASET v1.0 Category: Memory management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[10];
    struct Node* next;
};

struct Node* head = NULL;

void insert(char* data) {
    if (head == NULL) {
        head = (struct Node*)malloc(sizeof(struct Node));
        strcpy(head->data, data);
        head->next = NULL;
        printf("%s inserted!\n", data);
        return;
    }

    struct Node* current = head;
    while (current->next != NULL)
        current = current->next;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    current->next = newNode;

    printf("%s inserted!\n", data);
}

void delete(char* data) {
    struct Node* current = head;
    struct Node* previous = NULL;

    while (current != NULL && strcmp(current->data, data) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("%s not found!\n", data);
        return;
    }

    if (previous == NULL) {
        head = current->next;
    }
    else {
        previous->next = current->next;
    }

    free(current);
    printf("%s deleted!\n", data);
}

void printList() {
    struct Node* current = head;
    if (current == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    insert("apple");
    insert("banana");
    insert("orange");

    printList();

    delete("banana");

    printList();

    return 0;
}