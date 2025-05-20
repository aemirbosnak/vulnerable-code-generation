//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void print_list(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert_at_beginning(struct node **head, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_after(struct node *prev, int data) {
    if (prev == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = prev->next;
    prev->next = new_node;
}

void insert_at_end(struct node **head, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *last_node = *head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

void delete_node(struct node **head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->data == data) {
        *head = (*head)->next;
        return;
    }
    struct node *prev = *head;
    while (prev->next != NULL && prev->next->data != data) {
        prev = prev->next;
    }
    if (prev->next == NULL) {
        printf("Node with data %d not found.\n", data);
        return;
    }
    struct node *del_node = prev->next;
    prev->next = del_node->next;
    free(del_node);
}

int main() {
    struct node *head = NULL;
    int choice, data;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert after a node\n");
        printf("3. Insert at end\n");
        printf("4. Delete a node\n");
        printf("5. Print the list\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insert_at_beginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert after which node: ");
                scanf("%d", &data);
                struct node *prev = head;
                while (prev != NULL && prev->data != data) {
                    prev = prev->next;
                }
                if (prev == NULL) {
                    printf("Node with data %d not found.\n", data);
                } else {
                    printf("Enter data to insert: ");
                    scanf("%d", &data);
                    insert_after(prev, data);
                }
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insert_at_end(&head, data);
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete_node(&head, data);
                break;
            case 5:
                printf("The list is: ");
                print_list(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}