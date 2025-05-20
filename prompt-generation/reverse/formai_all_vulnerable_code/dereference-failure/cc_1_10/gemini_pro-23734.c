//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom data type for a linked list of characters
struct char_node {
    char data;
    struct char_node *next;
};

// Create a new character node
struct char_node *new_char_node(char data) {
    struct char_node *node = malloc(sizeof(struct char_node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Insert a character node into a linked list
void insert_char_node(struct char_node **head, struct char_node *node) {
    if (*head == NULL) {
        *head = node;
    } else {
        struct char_node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

// Delete a character node from a linked list
void delete_char_node(struct char_node **head, struct char_node *node) {
    if (*head == node) {
        *head = (*head)->next;
    } else {
        struct char_node *current = *head;
        while (current->next != node) {
            current = current->next;
        }
        current->next = node->next;
    }
    free(node);
}

// Convert a C string to a linked list of characters
struct char_node *string_to_list(char *string) {
    struct char_node *head = NULL;
    int i = 0;
    while (string[i] != '\0') {
        struct char_node *node = new_char_node(string[i]);
        insert_char_node(&head, node);
        i++;
    }
    return head;
}

// Convert a linked list of characters to a C string
char *list_to_string(struct char_node *head) {
    int length = 0;
    struct char_node *current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    char *string = malloc(length + 1);
    int i = 0;
    current = head;
    while (current != NULL) {
        string[i] = current->data;
        current = current->next;
        i++;
    }
    string[length] = '\0';
    return string;
}

// Reverse a linked list of characters
struct char_node *reverse_list(struct char_node *head) {
    struct char_node *prev = NULL;
    struct char_node *current = head;
    struct char_node *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Main function
int main() {
    // Create a C string
    char *string = "Hello, world!";

    // Convert the C string to a linked list of characters
    struct char_node *head = string_to_list(string);

    // Reverse the linked list of characters
    head = reverse_list(head);

    // Convert the reversed linked list of characters back to a C string
    char *reversed_string = list_to_string(head);

    // Print the original C string and the reversed C string
    printf("Original string: %s\n", string);
    printf("Reversed string: %s\n", reversed_string);

    // Free the memory allocated for the linked list of characters
    struct char_node *current = head;
    while (current != NULL) {
        struct char_node *next = current->next;
        free(current);
        current = next;
    }

    // Free the memory allocated for the reversed C string
    free(reversed_string);

    return 0;
}