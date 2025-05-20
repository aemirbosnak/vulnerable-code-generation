//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Couldn't allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_head(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_tail(Node **head, int data) {
    Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void insert_at_index(Node **head, int data, int index) {
    if (index == 0) {
        insert_at_head(head, data);
        return;
    }
    Node *new_node = create_node(data);
    Node *current = *head;
    for (int i = 0; i < index - 1; i++) {
        if (current == NULL) {
            printf("Error: Index out of bounds.\n");
            free(new_node);
            return;
        }
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

void delete_at_head(Node **head) {
    if (*head == NULL) {
        printf("Error: List is empty.\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_at_tail(Node **head) {
    if (*head == NULL) {
        printf("Error: List is empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void delete_at_index(Node **head, int index) {
    if (index == 0) {
        delete_at_head(head);
        return;
    }
    Node *current = *head;
    for (int i = 0; i < index - 1; i++) {
        if (current == NULL) {
            printf("Error: Index out of bounds.\n");
            return;
        }
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Error: Index out of bounds.\n");
        return;
    }
    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
}

void print_list(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    insert_at_head(&head, 1);
    insert_at_tail(&head, 2);
    insert_at_index(&head, 3, 1);
    print_list(head);  // Output: 1 3 2
    delete_at_head(&head);
    delete_at_tail(&head);
    delete_at_index(&head, 0);
    print_list(head);  // Output: 3
    return 0;
}