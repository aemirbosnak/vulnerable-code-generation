//FormAI DATASET v1.0 Category: Linked list operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void create(Node **head) {
    int n, i;
    printf("Enter the number of elements in the link list: ");
    scanf("%d", &n);
    Node *temp, *new_node;
    *head = (Node*)malloc(sizeof(Node));
    printf("Enter the data for node 1: ");
    scanf("%d", &((*head)->data));
    (*head)->next = NULL;
    temp = (*head);
    for (i = 2; i <= n; i++) {
        new_node = (Node*)malloc(sizeof(Node));
        printf("Enter the data for node %d: ", i);
        scanf("%d", &(new_node->data));
        new_node->next = NULL;
        temp->next = new_node;
        temp = temp->next;
    }
}

void display(Node *head) {
    printf("The elements of the linked list are: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert(Node **head, int data, int position) {
    Node *new_node, *temp, *prev;
    int i;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    if (position == 1) {
        temp = (*head);
        (*head) = new_node;
        new_node->next = temp;
        return;
    }
    temp = (*head);
    for (i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = new_node;
    new_node->next = temp;
}

void delete(Node **head, int position) {
    Node *temp, *prev;
    int i;
    if (position == 1) {
        temp = (*head);
        (*head) = (*head)->next;
        free(temp);
        return;
    }
    temp = (*head);
    for (i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

int main() {
    Node *head = NULL;
    int choice, data, position;
    do {
        printf("\n\n");
        printf("1. Create a linked list\n");
        printf("2. Display the linked list\n");
        printf("3. Insert a node\n");
        printf("4. Delete a node\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create(&head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                printf("Enter the position at which the node is to be inserted: ");
                scanf("%d", &position);
                insert(&head, data, position);
                break;
            case 4:
                printf("Enter the position of the node to be deleted: ");
                scanf("%d", &position);
                delete(&head, position);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}