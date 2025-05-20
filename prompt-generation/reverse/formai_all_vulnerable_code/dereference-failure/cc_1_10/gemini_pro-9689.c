//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declare the node structure for the linked list
struct node {
    char* word;
    int count;
    struct node* next;
};

// Declare the head of the linked list
struct node* head = NULL;

// Function to add a word to the linked list
void add_word(char* word) {
    // Allocate memory for the new node
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    // Copy the word into the new node
    new_node->word = strdup(word);

    // Initialize the count to 1
    new_node->count = 1;

    // Add the new node to the beginning of the linked list
    new_node->next = head;
    head = new_node;
}

// Function to count the number of occurrences of a word in the linked list
int count_word(char* word) {
    // Initialize the count to 0
    int count = 0;

    // Iterate over the linked list
    struct node* current = head;
    while (current != NULL) {
        // Check if the current word matches the given word
        if (strcmp(current->word, word) == 0) {
            // Increment the count
            count++;
        }
        // Move to the next node
        current = current->next;
    }

    // Return the count
    return count;
}

// Function to print the linked list
void print_list() {
    // Iterate over the linked list
    struct node* current = head;
    while (current != NULL) {
        // Print the word and its count
        printf("%s: %d\n", current->word, current->count);

        // Move to the next node
        current = current->next;
    }
}

// Main function
int main() {
    // Read the input file
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the words from the file
    char word[100];
    while (fscanf(file, "%s", word) != EOF) {
        // Convert the word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Add the word to the linked list
        add_word(word);
    }

    // Close the input file
    fclose(file);

    // Print the linked list
    print_list();

    // Free the memory allocated for the linked list
    struct node* current = head;
    while (current != NULL) {
        struct node* next = current->next;
        free(current->word);
        free(current);
        current = next;
    }

    return EXIT_SUCCESS;
}