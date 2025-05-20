//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a node for the linked list.
typedef struct node {
    char *word;
    int count;
    struct node *next;
} node;

// Create a new node.
node *create_node(char *word) {
    node *new_node = malloc(sizeof(node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node into the linked list.
void insert_node(node **head, char *word) {
    node *new_node = create_node(word);

    // If the linked list is empty, set the head to the new node.
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Otherwise, find the last node and insert the new node after it.
    node *current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

// Search for a word in the linked list.
node *search_node(node *head, char *word) {
    node *current_node = head;

    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            return current_node;
        }
        current_node = current_node->next;
    }

    return NULL;
}

// Increment the count of a word in the linked list.
void increment_count(node *node) {
    node->count++;
}

// Print the linked list.
void print_list(node *head) {
    node *current_node = head;

    while (current_node != NULL) {
        printf("%s: %d\n", current_node->word, current_node->count);
        current_node = current_node->next;
    }
}

// Free the linked list.
void free_list(node *head) {
    node *current_node = head;
    node *next_node;

    while (current_node != NULL) {
        next_node = current_node->next;
        free(current_node->word);
        free(current_node);
        current_node = next_node;
    }
}

// Read a file and count the words.
void count_words(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    node *head = NULL;

    char word[100];
    while (fscanf(file, "%s", word) != EOF) {
        node *node = search_node(head, word);
        if (node == NULL) {
            insert_node(&head, word);
        } else {
            increment_count(node);
        }
    }

    fclose(file);

    print_list(head);

    free_list(head);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    count_words(argv[1]);

    return 0;
}