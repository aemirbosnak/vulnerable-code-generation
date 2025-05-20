//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LEN 20
#define MAX_PHONE_LEN 20
#define MAX_ADDRESS_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char address[MAX_ADDRESS_LEN];
} contact_t;

contact_t contact_list[10]; // array to store contact information
int num_contacts = 0; // number of contacts in the list

void add_contact(char *name, char *phone, char *address); // function to add a new contact
void display_contacts(); // function to display all contacts

int main() {
    // Add some sample contacts
    add_contact("John Doe", "555-1234", "123 Main St");
    add_contact("Jane Doe", "555-5678", "456 Elm St");
    add_contact("Bob Smith", "555-9012", "789 Oak St");

    // Display all contacts
    display_contacts();

    return 0;
}

void add_contact(char *name, char *phone, char *address) {
    // Check if the name is already in the list
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, contact_list[i].name) == 0) {
            printf("Error: Contact already exists with name %s\n", name);
            return;
        }
    }

    // Allocate memory for the new contact
    contact_t *new_contact = (contact_t *)malloc(sizeof(contact_t));
    strcpy(new_contact->name, name);
    strcpy(new_contact->phone, phone);
    strcpy(new_contact->address, address);

    // Add the new contact to the list
    contact_list[num_contacts] = *new_contact;
    num_contacts++;

    // Display the updated list of contacts
    display_contacts();
}

void display_contacts() {
    printf("Contacts:\n");

    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\nPhone: %s\nAddress: %s\n",
               contact_list[i].name, contact_list[i].phone, contact_list[i].address);
    }

    printf("\n");
}