//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20
#define MAX_ADDR_LEN 50

// Structure to store contact information
typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char addr[MAX_ADDR_LEN];
} contact_t;

// Function to insert a new contact
void insert_contact(contact_t *contacts, int *num_contacts, char *name, char *phone, char *addr) {
    int i;
    for (i = 0; i < *num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            // Contact already exists, update the information
            strcpy(contacts[i].phone, phone);
            strcpy(contacts[i].addr, addr);
            return;
        }
    }
    // Contact does not exist, add it to the end of the list
    contacts[*num_contacts] = (contact_t) { .name = name, .phone = phone, .addr = addr };
    (*num_contacts)++;
}

// Function to search for a contact
int search_contact(contact_t *contacts, int num_contacts, char *name) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to display all contacts
void display_contacts(contact_t *contacts, int num_contacts) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        printf("%d. %s %s %s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].addr);
    }
}

int main() {
    // Initialize the list of contacts
    contact_t *contacts = (contact_t *) malloc(sizeof(contact_t) * 10);
    int num_contacts = 0;

    // Insert some contacts
    insert_contact(contacts, &num_contacts, "John Doe", "555-1234", "123 Main St");
    insert_contact(contacts, &num_contacts, "Jane Doe", "555-5678", "456 Elm St");
    insert_contact(contacts, &num_contacts, "Bob Smith", "555-9012", "789 Oak St");

    // Search for a contact
    int found = search_contact(contacts, num_contacts, "Jane Doe");
    if (found != -1) {
        printf("Found Jane Doe at index %d\n", found);
    } else {
        printf("Did not find Jane Doe\n");
    }

    // Display all contacts
    display_contacts(contacts, num_contacts);

    // Free the memory allocated for the list of contacts
    free(contacts);

    return 0;
}