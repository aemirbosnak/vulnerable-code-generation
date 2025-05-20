//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Phone book structure
typedef struct {
    char name[50];
    char number[20];
    struct phone_book *next;
} phone_book;

// Function to insert a new entry into the phone book
void insert(phone_book **head_ref, char *name, char *number) {
    phone_book *new_entry = (phone_book *) malloc(sizeof(phone_book));
    strcpy(new_entry->name, name);
    strcpy(new_entry->number, number);
    new_entry->next = *head_ref;
    *head_ref = new_entry;
}

// Function to search for a specific entry in the phone book
phone_book *search(phone_book **head_ref, char *name) {
    phone_book *current = *head_ref;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete an entry from the phone book
void delete(phone_book **head_ref, char *name) {
    phone_book *current = *head_ref;
    phone_book *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                *head_ref = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    phone_book *head = NULL;

    // Insert some entries into the phone book
    insert(&head, "John Doe", "555-1234");
    insert(&head, "Jane Doe", "555-5678");
    insert(&head, "Bob Smith", "555-9012");

    // Search for an entry in the phone book
    phone_book *john = search(&head, "John Doe");
    if (john != NULL) {
        printf("Found John Doe's number: %s\n", john->number);
    } else {
        printf("Not found\n");
    }

    // Delete an entry from the phone book
    delete(&head, "Jane Doe");

    // Print the remaining entries in the phone book
    phone_book *current = head;
    while (current != NULL) {
        printf("%s %s\n", current->name, current->number);
        current = current->next;
    }

    return 0;
}