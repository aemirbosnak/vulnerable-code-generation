//GEMINI-pro DATASET v1.0 Category: Educational ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node_at_head(struct node **head, struct node *new_node) {
    new_node->next = *head;
    *head = new_node;
}

void insert_node_at_tail(struct node **head, struct node *new_node) {
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

void insert_node_at_index(struct node **head, struct node *new_node, int index) {
    if (*head == NULL || index == 0) {
        insert_node_at_head(head, new_node);
        return;
    }
    int current_index = 0;
    struct node *current_node = *head;
    while (current_index < index - 1 && current_node->next != NULL) {
        current_node = current_node->next;
        current_index++;
    }
    if (current_index < index - 1) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
}

void remove_node_at_head(struct node **head) {
    if (*head == NULL) {
        fprintf(stderr, "Empty list\n");
        exit(EXIT_FAILURE);
    }
    struct node *new_head = (*head)->next;
    free(*head);
    *head = new_head;
}

void remove_node_at_tail(struct node **head) {
    if (*head == NULL) {
        fprintf(stderr, "Empty list\n");
        exit(EXIT_FAILURE);
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node *current_node = *head;
    while (current_node->next->next != NULL) {
        current_node = current_node->next;
    }
    free(current_node->next);
    current_node->next = NULL;
}

void remove_node_at_index(struct node **head, int index) {
    if (*head == NULL || index == 0) {
        remove_node_at_head(head);
        return;
    }
    int current_index = 0;
    struct node *current_node = *head;
    while (current_index < index - 1 && current_node->next != NULL) {
        current_node = current_node->next;
        current_index++;
    }
    if (current_index < index - 1) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    struct node *new_next = current_node->next->next;
    free(current_node->next);
    current_node->next = new_next;
}

void print_list(struct node *head) {
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;

    insert_node_at_head(&head, create_node(1));
    insert_node_at_tail(&head, create_node(2));
    insert_node_at_index(&head, create_node(3), 1);

    print_list(head);

    remove_node_at_head(&head);
    remove_node_at_tail(&head);
    remove_node_at_index(&head, 0);

    print_list(head);

    return 0;
}