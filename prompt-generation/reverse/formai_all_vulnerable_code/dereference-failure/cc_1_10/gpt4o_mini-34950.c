//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a contact
struct Contact {
    char name[100];
    char phone[15];
};

// Function prototypes
void addContact(struct Contact **contacts, int *count);
void deleteContact(struct Contact *contacts, int *count);
void searchContact(struct Contact *contacts, int count);
void displayContacts(struct Contact *contacts, int count);
void freeMemory(struct Contact *contacts);

int main() {
    struct Contact *contacts = NULL;
    int count = 0;
    int choice;

    while (1) {
        printf("\n##### Phone Book Menu #####\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Display All Contacts\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                addContact(&contacts, &count);
                break;
            case 2:
                deleteContact(contacts, &count);
                break;
            case 3:
                searchContact(contacts, count);
                break;
            case 4:
                displayContacts(contacts, count);
                break;
            case 5:
                freeMemory(contacts);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    
    return 0;
}

void addContact(struct Contact **contacts, int *count) {
    *contacts = realloc(*contacts, (*count + 1) * sizeof(struct Contact));
    if (*contacts == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    printf("Enter name: ");
    fgets((*contacts)[*count].name, sizeof((*contacts)[*count].name), stdin);
    (*contacts)[*count].name[strcspn((*contacts)[*count].name, "\n")] = '\0'; // Remove newline

    printf("Enter phone number: ");
    fgets((*contacts)[*count].phone, sizeof((*contacts)[*count].phone), stdin);
    (*contacts)[*count].phone[strcspn((*contacts)[*count].phone, "\n")] = '\0'; // Remove newline

    (*count)++;
    printf("Contact added successfully!\n");
}

void deleteContact(struct Contact *contacts, int *count) {
    if (*count == 0) {
        printf("No contacts to delete!\n");
        return;
    }
    
    char name[100];
    printf("Enter the name of the contact to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1]; // Shift contacts
            }
            (*count)--;
            contacts = realloc(contacts, (*count) * sizeof(struct Contact)); // Resize memory
            printf("Contact deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    }
}

void searchContact(struct Contact *contacts, int count) {
    if (count == 0) {
        printf("No contacts available!\n");
        return;
    }
    
    char name[100];
    printf("Enter the name of the contact to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found: %s - %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    }
}

void displayContacts(struct Contact *contacts, int count) {
    if (count == 0) {
        printf("No contacts available!\n");
        return;
    }

    printf("\n##### All Contacts #####\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void freeMemory(struct Contact *contacts) {
    free(contacts);
}