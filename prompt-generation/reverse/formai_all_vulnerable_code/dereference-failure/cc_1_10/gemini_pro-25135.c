//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a linked list node to store a word and its frequency
typedef struct node {
    char *word;
    int frequency;
    struct node *next;
} node;

// Create a new linked list node
node *create_node(char *word) {
    node *new_node = malloc(sizeof(node));
    new_node->word = strdup(word);
    new_node->frequency = 1;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node into the linked list in alphabetical order
void insert_node(node **head, node *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL && strcmp(current->next->word, new_node->word) < 0) {
            current = current->next;
        }
        if (current->next == NULL || strcmp(current->next->word, new_node->word) > 0) {
            new_node->next = current->next;
            current->next = new_node;
        } else {
            current->next->frequency++;
        }
    }
}

// Print the linked list of words and their frequencies
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->frequency);
        current = current->next;
    }
}

// Free the linked list of words
void free_list(node *head) {
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
}

// Read a file and store the words in a linked list
void read_file(char *filename, node **head) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char word[1024];
    while (fscanf(file, "%s", word) != EOF) {
        node *new_node = create_node(word);
        insert_node(head, new_node);
    }

    fclose(file);
}

// Write the linked list of words and their frequencies to a file
void write_file(char *filename, node *head) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    node *current = head;
    while (current != NULL) {
        fprintf(file, "%s: %d\n", current->word, current->frequency);
        current = current->next;
    }

    fclose(file);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    node *head = NULL;
    read_file(argv[1], &head);
    print_list(head);
    write_file(argv[2], head);
    free_list(head);

    return 0;
}