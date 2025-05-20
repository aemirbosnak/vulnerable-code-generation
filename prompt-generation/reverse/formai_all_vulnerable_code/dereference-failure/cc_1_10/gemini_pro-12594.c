//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
typedef struct node {
    char *word;
    int count;
    struct node *next;
} node;

// Function to create a new node
node *create_node(char *word) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->word = word;
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node into the linked list
void insert_node(node **head, node *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to search for a word in the linked list
node *search_node(node *head, char *word) {
    node *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to count the frequency of a word in the text
int count_frequency(node *head, char *word) {
    node *found_node = search_node(head, word);
    if (found_node != NULL) {
        return found_node->count;
    } else {
        return 0;
    }
}

// Function to print the linked list
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

// Function to free the linked list
void free_list(node *head) {
    node *current = head;
    while (current != NULL) {
        node *next_node = current->next;
        free(current->word);
        free(current);
        current = next_node;
    }
}

int main() {
    // Get the text from the user
    char *text = (char *)malloc(1000);
    printf("Enter the text: ");
    gets(text);

    // Tokenize the text into words
    char *tokens[100];
    int num_tokens = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Create a linked list to store the word frequencies
    node *head = NULL;
    for (int i = 0; i < num_tokens; i++) {
        node *new_node = create_node(tokens[i]);
        insert_node(&head, new_node);
    }

    // Print the word frequencies
    print_list(head);

    // Free the linked list
    free_list(head);

    return 0;
}