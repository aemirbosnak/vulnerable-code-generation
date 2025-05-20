//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void create_node(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void delete_node(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

int main() {
    Node* head = NULL;

    create_node(&head, 1);
    create_node(&head, 2);
    create_node(&head, 3);
    create_node(&head, 4);
    create_node(&head, 5);

    printf("Original list:\n");
    print_list(head);

    delete_node(&head, 3);
    printf("After deleting 3:\n");
    print_list(head);

    delete_node(&head, 1);
    printf("After deleting 1:\n");
    print_list(head);

    delete_node(&head, 5);
    printf("After deleting 5:\n");
    print_list(head);

    delete_node(&head, 2);
    printf("After deleting 2:\n");
    print_list(head);

    delete_node(&head, 4);
    printf("After deleting 4:\n");
    print_list(head);

    return 0;
}