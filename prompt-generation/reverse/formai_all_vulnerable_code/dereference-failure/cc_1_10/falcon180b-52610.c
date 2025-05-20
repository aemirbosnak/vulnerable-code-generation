//Falcon-180B DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

int main() {
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = (Node*) malloc(sizeof(Node));
    if (head == NULL) {
        printf("Memory could not be allocated for the first node.\n");
        return 1;
    }

    head->data = 1;
    head->next = NULL;

    second = (Node*) malloc(sizeof(Node));
    if (second == NULL) {
        printf("Memory could not be allocated for the second node.\n");
        return 1;
    }

    second->data = 2;
    second->next = NULL;

    third = (Node*) malloc(sizeof(Node));
    if (third == NULL) {
        printf("Memory could not be allocated for the third node.\n");
        return 1;
    }

    third->data = 3;
    third->next = NULL;

    head->next = second;
    second->next = third;

    printf("The linked list contains the following elements:\n");
    Node* current = head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    free(head);
    free(second);
    free(third);

    return 0;
}