//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

void add_node(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node* head) {
    while (head!= NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("\nLinked List Operations\n");
        printf("1. Add node\n2. Print list\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to be added: ");
                scanf("%d", &data);
                add_node(&head, data);
                break;
            case 2:
                printf("List: ");
                print_list(head);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}