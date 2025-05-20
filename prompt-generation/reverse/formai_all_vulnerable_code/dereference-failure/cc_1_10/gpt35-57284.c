//FormAI DATASET v1.0 Category: Memory management ; Style: creative
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void initList(struct Node** head) {
    *head = NULL;
}

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void delete(struct Node** head, int data) {
    if (*head == NULL) {
        return;
    }

    struct Node* prev = NULL;
    struct Node* current = *head;

    while (current && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

int main() {
    struct Node* head;
    initList(&head);

    insert(&head, 3);
    insert(&head, 5);
    insert(&head, 7);
    insert(&head, 9);

    printf("List contents: ");
    struct Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    delete(&head, 5);

    printf("List contents after deletion: ");
    current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}