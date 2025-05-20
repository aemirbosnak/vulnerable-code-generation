//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME_LEN 256
#define MAX_PHONE_NUM_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char phone_num[MAX_PHONE_NUM_LEN];
} contact_t;

contact_t *create_contact(const char *name, const char *phone_num) {
    contact_t *contact = malloc(sizeof(contact_t));
    strcpy(contact->name, name);
    strcpy(contact->phone_num, phone_num);
    return contact;
}

void print_contact(const contact_t *contact) {
    printf("Name: %s\nPhone Number: %s\n", contact->name, contact->phone_num);
}

int main() {
    contact_t *contact1 = create_contact("John Doe", "555-1234");
    contact_t *contact2 = create_contact("Jane Doe", "555-5678");
    contact_t *contact3 = create_contact("Bob Smith", "555-9012");

    // Add contacts to a dynamic array
    contact_t **contacts = malloc(sizeof(contact_t *) * 3);
    contacts[0] = contact1;
    contacts[1] = contact2;
    contacts[2] = contact3;

    // Print all contacts
    for (int i = 0; i < 3; i++) {
        print_contact(contacts[i]);
    }

    // Remove a contact
    contacts[1] = NULL;

    // Print all remaining contacts
    for (int i = 0; i < 2; i++) {
        print_contact(contacts[i]);
    }

    // Free memory
    free(contacts[0]);
    free(contacts[1]);
    free(contacts);

    return 0;
}