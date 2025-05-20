//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}

struct Node* delete(struct Node* head, int data) {
    struct Node* previous = NULL;
    struct Node* current = head;

    while (current && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (previous) {
        previous->next = current->next;
    } else {
        head = current->next;
    }

    free(current);

    return head;
}

struct Node* search(struct Node* head, int data) {
    struct Node* current = head;

    while (current && current->data != data) {
        current = current->next;
    }

    if (current) {
        return current;
    } else {
        return NULL;
    }
}

void traverse(struct Node* head) {
    struct Node* current = head;

    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    traverse(head);

    delete(head, 30);

    traverse(head);

    struct Node* searchResult = search(head, 40);

    if (searchResult) {
        printf("Data found: %d\n", searchResult->data);
    } else {
        printf("Data not found\n");
    }

    return 0;
}