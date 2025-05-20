//GEMINI-pro DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for a linked list
typedef struct node {
    char *key;
    char *value;
    struct node *next;
} node_t;

// Function to create a new node
node_t *create_node(char *key, char *value) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node into a linked list
node_t *insert_node(node_t *head, node_t *new_node) {
    if (head == NULL) {
        return new_node;
    }
    head->next = insert_node(head->next, new_node);
    return head;
}

// Function to find a node in a linked list
node_t *find_node(node_t *head, char *key) {
    if (head == NULL) {
        return NULL;
    }
    if (strcmp(head->key, key) == 0) {
        return head;
    }
    return find_node(head->next, key);
}

// Function to delete a node from a linked list
node_t *delete_node(node_t *head, char *key) {
    if (head == NULL) {
        return NULL;
    }
    if (strcmp(head->key, key) == 0) {
        node_t *temp = head->next;
        free(head->key);
        free(head->value);
        free(head);
        return temp;
    }
    head->next = delete_node(head->next, key);
    return head;
}

// Function to print a linked list
void print_list(node_t *head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    printf("%s: %s\n", head->key, head->value);
    print_list(head->next);
}

// Function to get input from the user
void get_input(node_t **head) {
    char key[100], value[100];
    printf("Enter key: ");
    scanf("%s", key);
    if (strcmp(key, "q") == 0) {
        return;
    }
    printf("Enter value: ");
    scanf("%s", value);
    node_t *new_node = create_node(key, value);
    *head = insert_node(*head, new_node);
    get_input(head);
}

// Main function
int main() {
    node_t *head = NULL;
    get_input(&head);
    print_list(head);
    return 0;
}