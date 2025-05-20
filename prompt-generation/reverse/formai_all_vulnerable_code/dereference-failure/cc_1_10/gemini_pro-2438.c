//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a node for the linked list
typedef struct node {
    char* word;
    int count;
    struct node *next;
} node;

// Create a new node
node* create_node(char* word) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

// Insert a node into the linked list
void insert_node(node** head, node* new_node) {
    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Otherwise, find the correct place to insert the new node
    node* current = *head;
    while (current->next != NULL && strcmp(current->next->word, new_node->word) < 0) {
        current = current->next;
    }

    // Insert the new node after the current node
    new_node->next = current->next;
    current->next = new_node;
}

// Count the words in a string
int count_words(char* string) {
    int count = 0;
    char* word = strtok(string, " ");
    while (word != NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Print the linked list
void print_list(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

// Free the linked list
void free_list(node* head) {
    node* current = head;
    while (current != NULL) {
        node* next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Get the input string from the user
    char* string = (char*)malloc(1024);
    printf("Enter a string: ");
    fgets(string, 1024, stdin);

    // Count the words in the string
    int word_count = count_words(string);
    printf("The string contains %d words.\n", word_count);

    // Create a linked list to store the words and their counts
    node* head = NULL;

    // Tokenize the string and insert each word into the linked list
    char* word = strtok(string, " ");
    while (word != NULL) {
        node* new_node = create_node(word);
        insert_node(&head, new_node);
        word = strtok(NULL, " ");
    }

    // Print the linked list
    printf("The words and their counts are:\n");
    print_list(head);

    // Free the linked list
    free_list(head);

    // Free the input string
    free(string);

    return 0;
}