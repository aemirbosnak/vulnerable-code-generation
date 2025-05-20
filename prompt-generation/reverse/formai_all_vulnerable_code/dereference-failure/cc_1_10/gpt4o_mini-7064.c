//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define INITIAL_CAPACITY 2

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

typedef struct {
    Contact *contacts;
    int size;
    int capacity;
} PhoneBook;

void initializePhoneBook(PhoneBook *phoneBook) {
    phoneBook->size = 0;
    phoneBook->capacity = INITIAL_CAPACITY;
    phoneBook->contacts = malloc(phoneBook->capacity * sizeof(Contact));
}

void resizePhoneBook(PhoneBook *phoneBook) {
    phoneBook->capacity *= 2;
    phoneBook->contacts = realloc(phoneBook->contacts, phoneBook->capacity * sizeof(Contact));
}

void addContact(PhoneBook *phoneBook, const char *name, const char *phone) {
    if (phoneBook->size >= phoneBook->capacity) {
        resizePhoneBook(phoneBook);
    }
    strcpy(phoneBook->contacts[phoneBook->size].name, name);
    strcpy(phoneBook->contacts[phoneBook->size].phone, phone);
    phoneBook->size++;
    printf("Contact added: %s - %s\n", name, phone);
}

void viewContacts(const PhoneBook *phoneBook) {
    if (phoneBook->size == 0) {
        printf("No contacts available.\n");
        return;
    }
    printf("Contacts:\n");
    for (int i = 0; i < phoneBook->size; i++) {
        printf("%d. %s - %s\n", i + 1, phoneBook->contacts[i].name, phoneBook->contacts[i].phone);
    }
}

void searchContact(const PhoneBook *phoneBook, const char *name) {
    for (int i = 0; i < phoneBook->size; i++) {
        if (strcasecmp(phoneBook->contacts[i].name, name) == 0) {
            printf("Found contact: %s - %s\n", phoneBook->contacts[i].name, phoneBook->contacts[i].phone);
            return;
        }
    }
    printf("Contact not found: %s\n", name);
}

void deleteContact(PhoneBook *phoneBook, const char *name) {
    for (int i = 0; i < phoneBook->size; i++) {
        if (strcasecmp(phoneBook->contacts[i].name, name) == 0) {
            for (int j = i; j < phoneBook->size - 1; j++) {
                phoneBook->contacts[j] = phoneBook->contacts[j + 1];
            }
            phoneBook->size--;
            printf("Contact deleted: %s\n", name);
            return;
        }
    }
    printf("Contact not found: %s\n", name);
}

void freePhoneBook(PhoneBook *phoneBook) {
    free(phoneBook->contacts);
}

int main() {
    PhoneBook phoneBook;
    initializePhoneBook(&phoneBook);
    
    int choice;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    
    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume leftover newline character

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter phone: ");
                fgets(phone, MAX_PHONE_LENGTH, stdin);
                phone[strcspn(phone, "\n")] = 0; // Remove newline
                addContact(&phoneBook, name, phone);
                break;
            case 2:
                viewContacts(&phoneBook);
                break;
            case 3:
                printf("Enter name to search: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                searchContact(&phoneBook, name);
                break;
            case 4:
                printf("Enter name to delete: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                deleteContact(&phoneBook, name);
                break;
            case 5:
                printf("Exiting the phone book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    freePhoneBook(&phoneBook);
    return 0;
}