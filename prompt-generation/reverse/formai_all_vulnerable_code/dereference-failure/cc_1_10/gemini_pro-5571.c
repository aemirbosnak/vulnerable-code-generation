//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Linked list operations
void insert_at_beginning(struct Node **head, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(struct Node **head, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node *current_node = *head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void insert_at_position(struct Node **head, int data, int position) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;

    if (position == 1) {
        insert_at_beginning(head, data);
    } else {
        struct Node *current_node = *head;
        int count = 1;
        while (current_node != NULL && count < position - 1) {
            current_node = current_node->next;
            count++;
        }

        if (current_node != NULL) {
            new_node->next = current_node->next;
            current_node->next = new_node;
        }
    }
}

void delete_at_beginning(struct Node **head) {
    if (*head == NULL) {
        printf("The linked list is empty.\n");
    } else {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void delete_at_end(struct Node **head) {
    if (*head == NULL) {
        printf("The linked list is empty.\n");
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        struct Node *current_node = *head;
        struct Node *previous_node = NULL;
        while (current_node->next != NULL) {
            previous_node = current_node;
            current_node = current_node->next;
        }
        previous_node->next = NULL;
        free(current_node);
    }
}

void delete_at_position(struct Node **head, int position) {
    if (*head == NULL) {
        printf("The linked list is empty.\n");
    } else if (position == 1) {
        delete_at_beginning(head);
    } else {
        struct Node *current_node = *head;
        struct Node *previous_node = NULL;
        int count = 1;
        while (current_node != NULL && count < position) {
            previous_node = current_node;
            current_node = current_node->next;
            count++;
        }

        if (current_node != NULL) {
            previous_node->next = current_node->next;
            free(current_node);
        }
    }
}

void print_linked_list(struct Node *head) {
    struct Node *current_node = head;
    printf("The linked list is: ");
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;

    // Inserting elements at the beginning
    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_beginning(&head, 30);

    // Inserting elements at the end
    insert_at_end(&head, 40);
    insert_at_end(&head, 50);
    insert_at_end(&head, 60);

    // Inserting elements at a specific position
    insert_at_position(&head, 70, 3);
    insert_at_position(&head, 80, 5);

    // Printing the linked list
    print_linked_list(head);

    // Deleting elements from the beginning
    delete_at_beginning(&head);
    delete_at_beginning(&head);

    // Deleting elements from the end
    delete_at_end(&head);
    delete_at_end(&head);

    // Deleting elements from a specific position
    delete_at_position(&head, 3);
    delete_at_position(&head, 5);

    // Printing the linked list again
    print_linked_list(head);

    return 0;
}