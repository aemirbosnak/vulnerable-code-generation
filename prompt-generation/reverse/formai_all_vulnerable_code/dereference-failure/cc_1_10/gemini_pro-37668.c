//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a node in the phone book
typedef struct node {
    char *name;
    char *number;
    struct node *next;
} node_t;

// Define the head of the phone book
node_t *head = NULL;

// Define a mutex to protect the phone book
pthread_mutex_t phonebook_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to add a new entry to the phone book
void add_entry(char *name, char *number) {
    // Allocate memory for the new entry
    node_t *new_entry = malloc(sizeof(node_t));

    // Initialize the new entry
    new_entry->name = name;
    new_entry->number = number;
    new_entry->next = NULL;

    // Lock the phone book
    pthread_mutex_lock(&phonebook_mutex);

    // Add the new entry to the phone book
    if (head == NULL) {
        head = new_entry;
    } else {
        node_t *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_entry;
    }

    // Unlock the phone book
    pthread_mutex_unlock(&phonebook_mutex);
}

// Function to find an entry in the phone book
char* find_entry(char *name) {
    // Lock the phone book
    pthread_mutex_lock(&phonebook_mutex);

    // Find the entry in the phone book
    node_t *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            // Return the phone number
            return current->number;
        }
        current = current->next;
    }

    // Unlock the phone book
    pthread_mutex_unlock(&phonebook_mutex);

    // Return NULL if the entry was not found
    return NULL;
}

// Function to print the phone book
void print_phonebook() {
    // Lock the phone book
    pthread_mutex_lock(&phonebook_mutex);

    // Print the phone book
    node_t *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->number);
        current = current->next;
    }

    // Unlock the phone book
    pthread_mutex_unlock(&phonebook_mutex);
}

// Main function
int main() {
    // Add some entries to the phone book
    add_entry("John Doe", "555-1212");
    add_entry("Jane Doe", "555-1213");
    add_entry("Bob Smith", "555-1214");

    // Print the phone book
    print_phonebook();

    // Find an entry in the phone book
    char *number = find_entry("John Doe");
    if (number != NULL) {
        printf("John Doe's number is %s\n", number);
    } else {
        printf("John Doe not found in phone book\n");
    }

    return 0;
}