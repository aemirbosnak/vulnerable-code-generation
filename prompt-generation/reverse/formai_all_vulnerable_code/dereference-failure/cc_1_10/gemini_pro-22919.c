//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node in a linked list
typedef struct node {
    char *word;
    int count;
    struct node *next;
} node;

// Create a new node with the given word and count
node *create_node(char *word, int count) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->word = strdup(word);
    new_node->count = count;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node into the linked list in ascending order of word
void insert_node(node **head, node *new_node) {
    if (*head == NULL || strcmp((*head)->word, new_node->word) > 0) {
        new_node->next = *head;
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL && strcmp(current->next->word, new_node->word) < 0) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

// Count the frequency of each word in the given text
node *count_words(char *text) {
    node *head = NULL;

    // Split the text into words
    char *token = strtok(text, " ");
    while (token != NULL) {
        // Lowercase the word
        for (int i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }

        // Check if the word is already in the linked list
        node *current = head;
        while (current != NULL) {
            if (strcmp(current->word, token) == 0) {
                current->count++;
                break;
            }
            current = current->next;
        }

        // If the word is not in the linked list, create a new node
        if (current == NULL) {
            node *new_node = create_node(token, 1);
            insert_node(&head, new_node);
        }

        // Get the next word
        token = strtok(NULL, " ");
    }

    return head;
}

// Print the frequency of each word in the linked list
void print_words(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

// Free the memory allocated for the linked list
void free_list(node *head) {
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
}

int main() {
    // Get the text from the user
    char text[1000];
    printf("Enter the text: ");
    fgets(text, 1000, stdin);

    // Count the frequency of each word
    node *head = count_words(text);

    // Print the frequency of each word
    print_words(head);

    // Free the memory allocated for the linked list
    free_list(head);

    return 0;
}