//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

typedef struct {
    Contact *contacts;
    size_t size;
} PhoneBook;

// Function prototypes
void initializePhoneBook(PhoneBook *pb);
void addContact(PhoneBook *pb);
void displayContacts(const PhoneBook *pb);
void deleteContact(PhoneBook *pb);
void freePhoneBook(PhoneBook *pb);

int main() {
    PhoneBook pb;
    initializePhoneBook(&pb);

    int choice;
    do {
        printf("\n==== Phone Book Menu ====\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("=========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character

        switch (choice) {
            case 1:
                addContact(&pb);
                break;
            case 2:
                displayContacts(&pb);
                break;
            case 3:
                deleteContact(&pb);
                break;
            case 4:
                printf("Exiting... Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    freePhoneBook(&pb);
    return 0;
}

void initializePhoneBook(PhoneBook *pb) {
    pb->contacts = NULL;
    pb->size = 0;
}

void addContact(PhoneBook *pb) {
    pb->contacts = realloc(pb->contacts, (pb->size + 1) * sizeof(Contact));
    if (pb->contacts == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    
    printf("Enter contact name: ");
    fgets(pb->contacts[pb->size].name, NAME_LENGTH, stdin);
    pb->contacts[pb->size].name[strcspn(pb->contacts[pb->size].name, "\n")] = 0; // Remove newline

    printf("Enter contact phone: ");
    fgets(pb->contacts[pb->size].phone, PHONE_LENGTH, stdin);
    pb->contacts[pb->size].phone[strcspn(pb->contacts[pb->size].phone, "\n")] = 0; // Remove newline

    pb->size++;
    printf("Contact added successfully!\n");
}

void displayContacts(const PhoneBook *pb) {
    if (pb->size == 0) {
        printf("No contacts to display.\n");
        return;
    }
    
    printf("\n=== Contacts ===\n");
    for (size_t i = 0; i < pb->size; i++) {
        printf("%zu. Name: %s, Phone: %s\n", i + 1, pb->contacts[i].name, pb->contacts[i].phone);
    } 
}

void deleteContact(PhoneBook *pb) {
    if (pb->size == 0) {
        printf("No contacts to delete.\n");
        return;
    }
    
    displayContacts(pb);
    
    size_t index;
    printf("Select the contact number to delete: ");
    scanf("%zu", &index);
    getchar(); // To consume newline character

    if (index == 0 || index > pb->size) {
        printf("Invalid contact number!\n");
        return;
    }

    // Shift contacts down to fill the gap
    for (size_t i = index - 1; i < pb->size - 1; i++) {
        pb->contacts[i] = pb->contacts[i + 1];
    }

    pb->size--;
    pb->contacts = realloc(pb->contacts, pb->size * sizeof(Contact));
    
    printf("Contact deleted successfully!\n");
}

void freePhoneBook(PhoneBook *pb) {
    free(pb->contacts);
    pb->contacts = NULL;
    pb->size = 0;
}