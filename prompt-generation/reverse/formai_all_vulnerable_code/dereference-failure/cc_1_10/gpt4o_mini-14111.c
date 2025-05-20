//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 50
#define PHONE_SIZE 15
#define INITIAL_CAPACITY 5

typedef struct {
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
} Contact;

typedef struct {
    Contact *contacts;
    int size;
    int capacity;
} ContactManager;

// Function prototypes
ContactManager* create_contact_manager();
void add_contact(ContactManager *manager, const char *name, const char *phone);
void list_contacts(const ContactManager *manager);
void delete_contact(ContactManager *manager, const char *name);
void free_contact_manager(ContactManager *manager);

int main() {
    ContactManager *manager = create_contact_manager();
    int choice;
    char name[NAME_SIZE], phone[PHONE_SIZE];

    while (1) {
        printf("\nContact Manager\n");
        printf("1. Add Contact\n");
        printf("2. List Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline after scanf

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_SIZE, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                
                printf("Enter phone number: ");
                fgets(phone, PHONE_SIZE, stdin);
                phone[strcspn(phone, "\n")] = 0; // Remove newline
                
                add_contact(manager, name, phone);
                break;
            case 2:
                list_contacts(manager);
                break;
            case 3:
                printf("Enter name of the contact to delete: ");
                fgets(name, NAME_SIZE, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                
                delete_contact(manager, name);
                break;
            case 4:
                free_contact_manager(manager);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

ContactManager* create_contact_manager() {
    ContactManager *manager = (ContactManager *)malloc(sizeof(ContactManager));
    manager->size = 0;
    manager->capacity = INITIAL_CAPACITY;
    manager->contacts = (Contact *)malloc(manager->capacity * sizeof(Contact));
    return manager;
}

void add_contact(ContactManager *manager, const char *name, const char *phone) {
    if (manager->size >= manager->capacity) {
        // Resize array if needed
        manager->capacity *= 2;
        manager->contacts = (Contact *)realloc(manager->contacts, manager->capacity * sizeof(Contact));
    }
    strcpy(manager->contacts[manager->size].name, name);
    strcpy(manager->contacts[manager->size].phone, phone);
    manager->size++;
    printf("Contact added successfully.\n");
}

void list_contacts(const ContactManager *manager) {
    if (manager->size == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("\nList of Contacts:\n");
    for (int i = 0; i < manager->size; i++) {
        printf("Name: %s, Phone: %s\n", manager->contacts[i].name, manager->contacts[i].phone);
    }
}

void delete_contact(ContactManager *manager, const char *name) {
    int found = 0;
    for (int i = 0; i < manager->size; i++) {
        if (strcmp(manager->contacts[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < manager->size - 1; j++) {
                manager->contacts[j] = manager->contacts[j + 1]; // Shift contacts left
            }
            manager->size--;
            printf("Contact deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void free_contact_manager(ContactManager *manager) {
    free(manager->contacts);
    free(manager);
}