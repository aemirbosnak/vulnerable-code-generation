//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

void print_list(node_t *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(node_t **head, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void insert_at_index(node_t **head, int data, int index) {
    if (index == 0) {
        insert_at_beginning(head, data);
    } else {
        node_t *new_node = malloc(sizeof(node_t));
        new_node->data = data;

        node_t *current = *head;
        int i = 0;
        while (i < index - 1 && current != NULL) {
            current = current->next;
            i++;
        }

        if (current == NULL) {
            printf("Index out of bounds\n");
            free(new_node);
        } else {
            new_node->next = current->next;
            current->next = new_node;
        }
    }
}

void delete_at_beginning(node_t **head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else {
        node_t *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void delete_at_end(node_t **head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        node_t *current = *head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
}

void delete_at_index(node_t **head, int index) {
    if (index == 0) {
        delete_at_beginning(head);
    } else {
        node_t *current = *head;
        int i = 0;
        while (i < index - 1 && current != NULL) {
            current = current->next;
            i++;
        }

        if (current == NULL) {
            printf("Index out of bounds\n");
        } else if (current->next == NULL) {
            delete_at_end(head);
        } else {
            node_t *temp = current->next;
            current->next = temp->next;
            free(temp);
        }
    }
}

int main() {
    node_t *head = NULL;

    // Insert some data into the list
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_index(&head, 3, 1);
    insert_at_end(&head, 4);
    insert_at_index(&head, 5, 2);

    // Print the list
    print_list(head);

    // Delete some data from the list
    delete_at_beginning(&head);
    delete_at_end(&head);
    delete_at_index(&head, 1);

    // Print the list again
    print_list(head);

    return 0;
}