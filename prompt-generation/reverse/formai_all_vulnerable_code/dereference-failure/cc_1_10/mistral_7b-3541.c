//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct node {
    char data[MAX_LEN];
    struct node *next;
} Node;

Node *create_node(const char *data);
void add_node(Node **head, Node *new_node);
Node *find_node(Node *head, const char *data);
void display_list(Node *head);
void delete_node(Node **head, const char *data);

int main() {
    Node *head = NULL;
    // Some Cyberpunk style initialization code here...

    // Input some data to the linked list
    add_node(&head, create_node("Neuromancer"));
    add_node(&head, create_node("Molly"));
    add_node(&head, create_node("Tess"));

    // Display the linked list
    printf("Linked List:\n");
    display_list(head);

    // Find and delete an element from the list
    Node *to_delete = find_node(head, "Molly");
    if (to_delete != NULL) {
        delete_node(&head, to_delete->data);
    }

    // Display the updated linked list
    printf("\nUpdated Linked List:\n");
    display_list(head);

    return 0;
}

Node *create_node(const char *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->data, data);
    new_node->next = NULL;
    return new_node;
}

void add_node(Node **head, Node *new_node) {
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

Node *find_node(Node *head, const char *data) {
    Node *current = head;
    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void display_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void delete_node(Node **head, const char *data) {
    if (*head == NULL) {
        return;
    }

    if (strcmp((*head)->data, data) == 0) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node *current = *head;
    while (current->next != NULL && strcmp(current->next->data, data) != 0) {
        current = current->next;
    }

    if (current->next == NULL) {
        return;
    }

    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
}