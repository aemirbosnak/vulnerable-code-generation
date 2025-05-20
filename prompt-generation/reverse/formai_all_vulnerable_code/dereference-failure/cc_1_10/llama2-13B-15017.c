//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME_LEN 256
#define MAX_PHONE_LEN 64
#define MAX_ADDRESS_LEN 128

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char address[MAX_ADDRESS_LEN];
} contact_t;

contact_t* create_contact(char* name, char* phone, char* address) {
    contact_t* new_contact = (contact_t*) malloc(sizeof(contact_t));
    strcpy(new_contact->name, name);
    strcpy(new_contact->phone, phone);
    strcpy(new_contact->address, address);
    return new_contact;
}

void add_contact(contact_t** contacts, char* name, char* phone, char* address) {
    contact_t* new_contact = create_contact(name, phone, address);
    int i = 0;
    while (contacts[i] != NULL) {
        if (strcmp(contacts[i]->name, name) > 0) {
            break;
        }
        i++;
    }
    contacts[i] = new_contact;
}

void print_contacts(contact_t** contacts) {
    int i = 0;
    while (contacts[i] != NULL) {
        printf("%s %s %s\n", contacts[i]->name, contacts[i]->phone, contacts[i]->address);
        i++;
    }
}

int main() {
    contact_t** contacts = (contact_t**) malloc(sizeof(contact_t*) * 10);
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char address[MAX_ADDRESS_LEN];

    // Add some contacts
    add_contact(contacts, "John Doe", "555-1234", "123 Main St");
    add_contact(contacts, "Jane Doe", "555-5678", "456 Elm St");
    add_contact(contacts, "Bob Smith", "555-9012", "789 Oak St");

    // Print the contacts
    print_contacts(contacts);

    // Free the memory
    free(contacts);

    return 0;
}