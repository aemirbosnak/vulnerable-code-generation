//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Address {
    char* street;
    char* city;
    char* state;
    char* zip;
};

struct Contact {
    char* name;
    char* email;
    struct Address* address;
    struct Contact* next;
};

void printContacts(struct Contact* head);
void addContact(struct Contact** head, char* name, char* email, char* street, char* city, char* state, char* zip);
void deleteContact(struct Contact** head, char* email);

int main() {
    struct Contact* head = NULL;
    addContact(&head, "John Doe", "johndoe@example.com", "123 Main St", "Anytown", "CA", "12345");
    addContact(&head, "Jane Smith", "janesmith@example.com", "456 Oak Blvd", "Somewhere", "TX", "67890");
    addContact(&head, "Bob Johnson", "bjohnson@example.com", "789 Pine Ave", "Nowhere", "AZ", "24680");
    printf("Initial contacts:\n");
    printContacts(head);
    deleteContact(&head, "janesmith@example.com");
    printf("\nContacts after deleting Jane Smith:\n");
    printContacts(head);
    return 0;
}

void printContacts(struct Contact* head) {
    struct Contact* current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Email: %s\n", current->email);
        printf("Address: %s, %s, %s %s\n\n", current->address->street, current->address->city, current->address->state, current->address->zip);
        current = current->next;
    }
}

void addContact(struct Contact** head, char* name, char* email, char* street, char* city, char* state, char* zip) {
    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
    newContact->name = (char*)malloc(strlen(name) + 1);
    strcpy(newContact->name, name);
    newContact->email = (char*)malloc(strlen(email) + 1);
    strcpy(newContact->email, email);
    newContact->address = (struct Address*)malloc(sizeof(struct Address));
    newContact->address->street = (char*)malloc(strlen(street) + 1);
    strcpy(newContact->address->street, street);
    newContact->address->city = (char*)malloc(strlen(city) + 1);
    strcpy(newContact->address->city, city);
    newContact->address->state = (char*)malloc(strlen(state) + 1);
    strcpy(newContact->address->state, state);
    newContact->address->zip = (char*)malloc(strlen(zip) + 1);
    strcpy(newContact->address->zip, zip);
    newContact->next = *head;
    *head = newContact;
}

void deleteContact(struct Contact** head, char* email) {
    struct Contact* current = *head;
    if (current != NULL && strcmp(current->email, email) == 0) {
        *head = current->next;
        free(current->name);
        free(current->email);
        free(current->address->street);
        free(current->address->city);
        free(current->address->state);
        free(current->address->zip);
        free(current->address);
        free(current);
        return;
    }
    while (current != NULL) {
        if (current->next != NULL && strcmp(current->next->email, email) == 0) {
            struct Contact* deleteContact = current->next;
            current->next = deleteContact->next;
            free(deleteContact->name);
            free(deleteContact->email);
            free(deleteContact->address->street);
            free(deleteContact->address->city);
            free(deleteContact->address->state);
            free(deleteContact->address->zip);
            free(deleteContact->address);
            free(deleteContact);
            return;
        }
        current = current->next;
    }
}