//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error creating new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_head(node_t **head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_tail(node_t **head, int data) {
    node_t *new_node = create_node(data);
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
        insert_at_head(head, data);
    } else {
        node_t *new_node = create_node(data);
        node_t *current = *head;
        int i = 0;
        while (current->next != NULL && i < index - 1) {
            current = current->next;
            i++;
        }
        if (current->next == NULL && i < index - 1) {
            printf("Index out of bounds.\n");
            free(new_node);
        } else {
            new_node->next = current->next;
            current->next = new_node;
        }
    }
}

void delete_at_head(node_t **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
    } else {
        node_t *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void delete_at_tail(node_t **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
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
    if (*head == NULL) {
        printf("List is empty.\n");
    } else if (index == 0) {
        delete_at_head(head);
    } else {
        node_t *current = *head;
        int i = 0;
        while (current->next != NULL && i < index - 1) {
            current = current->next;
            i++;
        }
        if (current->next == NULL && i < index - 1) {
            printf("Index out of bounds.\n");
        } else {
            node_t *temp = current->next;
            current->next = temp->next;
            free(temp);
        }
    }
}

void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node_t *head = NULL;

    insert_at_head(&head, 10);
    insert_at_tail(&head, 20);
    insert_at_index(&head, 30, 1);
    insert_at_index(&head, 40, 3);

    print_list(head);

    delete_at_head(&head);
    delete_at_tail(&head);
    delete_at_index(&head, 1);

    print_list(head);

    return 0;
}