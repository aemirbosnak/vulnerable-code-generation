//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Phone book module
#define MAX_NAME_LENGTH 256
#define MAX_PHONE_NUMBER_LENGTH 20

struct phone_book {
    char *name;
    char *phone_number;
    struct phone_book *next;
};

// Function to create a new phone book entry
struct phone_book *create_entry(char *name, char *phone_number) {
    struct phone_book *new_entry = (struct phone_book *) malloc(sizeof(struct phone_book));
    new_entry->name = name;
    new_entry->phone_number = phone_number;
    new_entry->next = NULL;
    return new_entry;
}

// Function to search for a phone book entry
struct phone_book *search_entry(struct phone_book *head, char *name) {
    struct phone_book *current = head;
    while (current != NULL && strcmp(current->name, name) != 0) {
        current = current->next;
    }
    return current;
}

// Function to add a new phone book entry
void add_entry(struct phone_book **head_ref, char *name, char *phone_number) {
    struct phone_book *new_entry = create_entry(name, phone_number);
    new_entry->next = *head_ref;
    *head_ref = new_entry;
}

// Function to remove a phone book entry
void remove_entry(struct phone_book **head_ref, char *name) {
    struct phone_book *current = *head_ref;
    struct phone_book *previous = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        if (previous == NULL) {
            *head_ref = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

int main() {
    struct phone_book *head = NULL;

    // Example usage of the functions
    add_entry(&head, "John Doe", "555-1234");
    add_entry(&head, "Jane Doe", "555-5678");
    add_entry(&head, "Bob Smith", "555-9012");

    // Search for a phone number
    struct phone_book *jane = search_entry(head, "Jane Doe");
    if (jane != NULL) {
        printf("Jane Doe's phone number is: %s\n", jane->phone_number);
    } else {
        printf("Jane Doe is not in the phone book\n");
    }

    // Remove a phone number
    remove_entry(&head, "Jane Doe");

    // Print the remaining phone book entries
    struct phone_book *current = head;
    while (current != NULL) {
        printf("%s %s\n", current->name, current->phone_number);
        current = current->next;
    }

    return 0;
}