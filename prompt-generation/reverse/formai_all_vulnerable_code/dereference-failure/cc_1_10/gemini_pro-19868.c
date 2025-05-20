//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Linked list operations
void insert_at_beginning(Node **head, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(Node **head, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void insert_at_index(Node **head, int data, int index) {
    if (index == 0) {
        insert_at_beginning(head, data);
    } else {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = data;
        Node *current = *head;
        int i = 0;
        while (current != NULL && i < index - 1) {
            current = current->next;
            i++;
        }
        if (current != NULL) {
            new_node->next = current->next;
            current->next = new_node;
        }
    }
}

void delete_at_beginning(Node **head) {
    if (*head != NULL) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void delete_at_end(Node **head) {
    if (*head != NULL) {
        Node *current = *head;
        Node *prev = NULL;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        if (prev != NULL) {
            prev->next = NULL;
            free(current);
        } else {
            *head = NULL;
            free(current);
        }
    }
}

void delete_at_index(Node **head, int index) {
    if (*head != NULL) {
        if (index == 0) {
            delete_at_beginning(head);
        } else {
            Node *current = *head;
            Node *prev = NULL;
            int i = 0;
            while (current != NULL && i < index) {
                prev = current;
                current = current->next;
                i++;
            }
            if (prev != NULL && current != NULL) {
                prev->next = current->next;
                free(current);
            }
        }
    }
}

void display_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node *head = NULL;
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_index(&head, 30, 1);
    display_list(head);
    delete_at_beginning(&head);
    delete_at_end(&head);
    delete_at_index(&head, 0);
    display_list(head);
    return 0;
}