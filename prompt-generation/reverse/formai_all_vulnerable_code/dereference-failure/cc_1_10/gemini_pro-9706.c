//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: excited
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Create a new node for the linked list
struct node {
    char *word;
    int count;
    struct node *next;
};

// Create a new linked list
struct list {
    struct node *head;
    struct node *tail;
};

// Create a new linked list node
struct node *create_node(char *word) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

// Create a new linked list
struct list *create_list() {
    struct list *new_list = malloc(sizeof(struct list));
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

// Add a new node to the linked list
void add_node(struct list *list, struct node *new_node) {
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// Check if a word is already in the linked list
int find_word(struct list *list, char *word) {
    struct node *current_node = list->head;
    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            return 1;
        }
        current_node = current_node->next;
    }
    return 0;
}

// Print the linked list
void print_list(struct list *list) {
    struct node *current_node = list->head;
    while (current_node != NULL) {
        printf("%s: %d\n", current_node->word, current_node->count);
        current_node = current_node->next;
    }
}

// Free the linked list
void free_list(struct list *list) {
    struct node *current_node = list->head;
    while (current_node != NULL) {
        struct node *next_node = current_node->next;
        free(current_node->word);
        free(current_node);
        current_node = next_node;
    }
    free(list);
}

int main() {
    // Create a new linked list
    struct list *list = create_list();

    // Open the file
    FILE *file = fopen("text.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the file line by line
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Tokenize the line
        char *tokens = strtok(line, " ");
        while (tokens != NULL) {
            // Convert the token to lowercase
            char *word = strdup(tokens);
            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }

            // Check if the word is already in the linked list
            if (!find_word(list, word)) {
                // Add the word to the linked list
                struct node *new_node = create_node(word);
                add_node(list, new_node);
            } else {
                // Increment the count of the word
                struct node *current_node = list->head;
                while (current_node != NULL) {
                    if (strcmp(current_node->word, word) == 0) {
                        current_node->count++;
                        break;
                    }
                    current_node = current_node->next;
                }
            }

            // Get the next token
            tokens = strtok(NULL, " ");
        }
    }

    // Close the file
    fclose(file);

    // Print the linked list
    print_list(list);

    // Free the linked list
    free_list(list);

    return EXIT_SUCCESS;
}