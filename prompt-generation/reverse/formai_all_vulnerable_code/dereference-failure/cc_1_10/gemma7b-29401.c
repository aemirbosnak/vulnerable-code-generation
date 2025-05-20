//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Node {
    int data;
    struct Node* next;
};

void insert_at_tail(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int delete_from_front(struct Node** head) {
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return 0;
}

int main() {
    struct Node* head = NULL;

    insert_at_tail(&head, 10);
    insert_at_tail(&head, 20);
    insert_at_tail(&head, 30);
    insert_at_tail(&head, 40);
    insert_at_tail(&head, 50);

    delete_from_front(&head);
    delete_from_front(&head);

    printf("Data in the queue: ");
    struct Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}