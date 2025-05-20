//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(node_t **head, int data) {
    node_t *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node_t *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insert_at_index(node_t **head, int data, int index) {
    if (index == 0) {
        insert_at_beginning(head, data);
        return;
    }
    node_t *new_node = create_node(data);
    node_t *temp = *head;
    for (int i = 0; i < index - 1; i++) {
        if (temp->next == NULL) {
            printf("Index out of bounds\n");
            return;
        }
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_at_beginning(node_t **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_at_end(node_t **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    node_t *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void delete_at_index(node_t **head, int index) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (index == 0) {
        delete_at_beginning(head);
        return;
    }
    node_t *temp = *head;
    for (int i = 0; i < index - 1; i++) {
        if (temp->next == NULL) {
            printf("Index out of bounds\n");
            return;
        }
        temp = temp->next;
    }
    node_t *to_delete = temp->next;
    temp->next = temp->next->next;
    free(to_delete);
}

void print_list(node_t *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node_t *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node_t *head = NULL;

    // Inserting at beginning
    insert_at_beginning(&head, 1);
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 3);

    // Inserting at end
    insert_at_end(&head, 4);
    insert_at_end(&head, 5);
    insert_at_end(&head, 6);

    // Inserting at index
    insert_at_index(&head, 7, 3);
    insert_at_index(&head, 8, 6);
    insert_at_index(&head, 9, 0);

    // Printing the list
    print_list(head);

    // Deleting at beginning
    delete_at_beginning(&head);
    delete_at_beginning(&head);
    delete_at_beginning(&head);

    // Deleting at end
    delete_at_end(&head);
    delete_at_end(&head);
    delete_at_end(&head);

    // Deleting at index
    delete_at_index(&head, 3);
    delete_at_index(&head, 0);
    delete_at_index(&head, 6);

    // Printing the list
    print_list(head);

    return 0;
}