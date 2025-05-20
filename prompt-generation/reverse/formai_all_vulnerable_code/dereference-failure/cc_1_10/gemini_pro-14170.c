//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact {
    char name[32];
    char phone_number[16];
    char email[64];
} contact_t;

void print_contact(contact_t *contact) {
    printf("Name: %s\n", contact->name);
    printf("Phone Number: %s\n", contact->phone_number);
    printf("Email: %s\n", contact->email);
}

void add_contact(contact_t **contacts, int *num_contacts) {
    char name[32];
    char phone_number[16];
    char email[64];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", phone_number);

    printf("Enter email: ");
    scanf("%s", email);

    contact_t *new_contact = malloc(sizeof(contact_t));
    strcpy(new_contact->name, name);
    strcpy(new_contact->phone_number, phone_number);
    strcpy(new_contact->email, email);

    (*contacts) = realloc((*contacts), sizeof(contact_t) * (*num_contacts + 1));
    (*contacts)[*num_contacts] = *new_contact;
    (*num_contacts)++;
}

void delete_contact(contact_t **contacts, int *num_contacts) {
    char name[32];

    printf("Enter name: ");
    scanf("%s", name);

    int index = -1;
    for (int i = 0; i < *num_contacts; i++) {
        if (strcmp((*contacts)[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Contact not found\n");
        return;
    }

    for (int i = index + 1; i < *num_contacts; i++) {
        (*contacts)[i - 1] = (*contacts)[i];
    }

    (*num_contacts)--;
    (*contacts) = realloc((*contacts), sizeof(contact_t) * (*num_contacts));
}

void search_contact(contact_t *contacts, int num_contacts) {
    char name[32];

    printf("Enter name: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            print_contact(&contacts[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found\n");
    }
}

int main() {
    int num_contacts = 0;
    contact_t *contacts = NULL;

    while (1) {
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Search contact\n");
        printf("4. Print all contacts\n");
        printf("5. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(&contacts, &num_contacts);
                break;
            case 2:
                delete_contact(&contacts, &num_contacts);
                break;
            case 3:
                search_contact(contacts, num_contacts);
                break;
            case 4:
                for (int i = 0; i < num_contacts; i++) {
                    print_contact(&contacts[i]);
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}