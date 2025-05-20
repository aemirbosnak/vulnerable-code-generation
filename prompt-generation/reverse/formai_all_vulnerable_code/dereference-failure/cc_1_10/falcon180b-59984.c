//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure definition
struct node {
    char word[100];
    int count;
    struct node* next;
};

// Function to create a new node
struct node* create_node(char* word) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a word into the index
void insert_word(struct node** head, char* word) {
    struct node* current = *head;
    while (current!= NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }
    struct node* new_node = create_node(word);
    new_node->next = *head;
    *head = new_node;
}

// Function to print the index
void print_index(struct node* head) {
    struct node* current = head;
    while (current!= NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

// Function to search for a word in the index
struct node* search_word(struct node* head, char* word) {
    struct node* current = head;
    while (current!= NULL) {
        if (strcmp(current->word, word) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    // Create an empty index
    struct node* head = NULL;

    // Insert some words into the index
    insert_word(&head, "love");
    insert_word(&head, "romance");
    insert_word(&head, "passion");

    // Print the index
    printf("Index:\n");
    print_index(head);

    // Search for a word in the index
    struct node* result = search_word(head, "love");
    if (result!= NULL) {
        printf("Found '%s' with count %d\n", result->word, result->count);
    } else {
        printf("Word not found\n");
    }

    return 0;
}