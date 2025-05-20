//FormAI DATASET v1.0 Category: Linked list operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert_node_at_end(struct node **head_ref, int data);
void insert_node_at_position(struct node **head_ref, int position, int data);
void delete_node_at_position(struct node **head_ref, int position);
void display_list(struct node *n);

int main() {
    struct node *head = NULL;
    int choice, position, data;

    while(1) {
        printf("\nLinked List Operations\n");
        printf("1. Insert node at the end\n");
        printf("2. Insert node at a specific position\n");
        printf("3. Delete node from a specific position\n");
        printf("4. Display the linked list\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                insert_node_at_end(&head, data);
                break;

            case 2:
                printf("Enter position where data is to be inserted: ");
                scanf("%d", &position);
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                insert_node_at_position(&head, position, data);
                break;

            case 3:
                printf("Enter position of node to be deleted: ");
                scanf("%d", &position);
                delete_node_at_position(&head, position);
                break;

            case 4:
                display_list(head);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!");
        }
    }

    return 0;
}

void insert_node_at_end(struct node **head_ref, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *last_node = *head_ref;

    new_node->data = data;
    new_node->next = NULL;

    if(*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        while(last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }

    printf("%d inserted at the end of the linked list\n", data);
}

void insert_node_at_position(struct node **head_ref, int position, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *current_node = *head_ref;
    struct node *previous_node = NULL;
    int node_count = 0;

    new_node->data = data;
    new_node->next = NULL;

    while(current_node != NULL) {
        node_count++;
        if(node_count == position) {
            if(previous_node == NULL) {
                new_node->next = current_node;
                *head_ref = new_node;
            } else {
                previous_node->next = new_node;
                new_node->next = current_node;
            }
            printf("%d inserted at position %d of the linked list\n", data, position);
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }

    printf("Position out of range! Insertion failed\n");
}

void delete_node_at_position(struct node **head_ref, int position) {
    struct node *current_node = *head_ref;
    struct node *previous_node = NULL;
    int node_count = 0;

    if(*head_ref == NULL) {
        printf("Linked list is empty! Deletion failed\n");
        return;
    }

    while(current_node != NULL) {
        node_count++;
        if(node_count == position) {
            if(previous_node == NULL) {
                *head_ref = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            printf("Node at position %d deleted from the linked list\n", position);
            free(current_node);
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }

    printf("Position out of range! Deletion failed\n");
}

void display_list(struct node *n) {
    if(n == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    printf("Elements of the linked list: ");
    while(n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}