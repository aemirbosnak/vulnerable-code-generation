//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_SIZE 50
#define PHONE_SIZE 15

typedef struct {
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
} Contact;

Contact* contacts[MAX_CONTACTS];
int contact_count = 0;

void add_contact(const char *name, const char *phone) {
    if (contact_count >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }
    Contact *new_contact = (Contact *)malloc(sizeof(Contact));
    strncpy(new_contact->name, name, NAME_SIZE);
    strncpy(new_contact->phone, phone, PHONE_SIZE);
    contacts[contact_count++] = new_contact;
    printf("Contact added: %s, %s\n", new_contact->name, new_contact->phone);
}

void search_contact(const char *name) {
    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i]->name, name) == 0) {
            printf("Found contact: %s, %s\n", contacts[i]->name, contacts[i]->phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

void delete_contact(const char *name) {
    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i]->name, name) == 0) {
            free(contacts[i]);
            for (int j = i; j < contact_count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            contact_count--;
            printf("Contact deleted: %s\n", name);
            return;
        }
    }
    printf("No contact found to delete.\n");
}

void list_contacts() {
    if (contact_count == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("Contact List:\n");
    for (int i = 0; i < contact_count; i++) {
        printf("%s: %s\n", contacts[i]->name, contacts[i]->phone);
    }
}

void free_contacts() {
    for (int i = 0; i < contact_count; i++) {
        free(contacts[i]);
    }
}

int main() {
    int choice;
    char name[NAME_SIZE], phone[PHONE_SIZE];

    while (1) {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. List Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character after choice input

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_SIZE, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                printf("Enter phone number: ");
                fgets(phone, PHONE_SIZE, stdin);
                phone[strcspn(phone, "\n")] = '\0'; // Remove newline
                add_contact(name, phone);
                break;
            case 2:
                printf("Enter name to search: ");
                fgets(name, NAME_SIZE, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                search_contact(name);
                break;
            case 3:
                printf("Enter name to delete: ");
                fgets(name, NAME_SIZE, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                delete_contact(name);
                break;
            case 4:
                list_contacts();
                break;
            case 5:
                free_contacts();
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}