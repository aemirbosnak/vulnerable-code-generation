//FormAI DATASET v1.0 Category: Linked list operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The previous node cannot be null!\n");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last_node = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("The element '%d' is  not present in the list.\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void printList(struct Node* node) {
    printf("The linked list is: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, del_data;

    while (1) {
        printf("\nSelect a linked list operation:\n");
        printf("1. Insert a node at the beginning of the list\n");
        printf("2. Insert a node after a given node\n");
        printf("3. Append a node at the end of the list\n");
        printf("4. Delete a node from the list\n");
        printf("5. Print the contents of the list\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be inserted at the beginning of the list: ");
                scanf("%d", &data);
                push(&head, data);
                break;

            case 2:
                printf("Enter the data of the node after which a new node needs to be inserted: ");
                scanf("%d", &del_data);
                insertAfter(head->next, del_data);
                break;

            case 3:
                printf("Enter the data to be appended at the end of the list: ");
                scanf("%d", &data);
                append(&head, data);
                break;

            case 4:
                printf("Enter the data to be deleted: ");
                scanf("%d", &del_data);
                deleteNode(&head, del_data);
                break;

            case 5:
                printList(head);
                break;

            case 6:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}