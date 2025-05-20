//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure representing a contact.
typedef struct {
    char name[50];
    char number[20];
} Contact;

// Define the structure representing a phone book.
typedef struct {
    Contact* contacts;
    int size;
    int capacity;
} PhoneBook;

// Create a new phone book.
PhoneBook* createPhoneBook(int initialCapacity) {
    PhoneBook* phoneBook = malloc(sizeof(PhoneBook));
    phoneBook->contacts = malloc(initialCapacity * sizeof(Contact));
    phoneBook->size = 0;
    phoneBook->capacity = initialCapacity;
    return phoneBook;
}

// Delete a phone book.
void deletePhoneBook(PhoneBook* phoneBook) {
    free(phoneBook->contacts);
    free(phoneBook);
}

// Add a contact to a phone book.
void addContact(PhoneBook* phoneBook, Contact contact) {
    if (phoneBook->size == phoneBook->capacity) {
        phoneBook->capacity *= 2;
        phoneBook->contacts = realloc(phoneBook->contacts, phoneBook->capacity * sizeof(Contact));
    }
    phoneBook->contacts[phoneBook->size] = contact;
    phoneBook->size++;
}

// Search for a contact in a phone book by name.
Contact* searchContactByName(PhoneBook* phoneBook, char* name) {
    for (int i = 0; i < phoneBook->size; i++) {
        Contact* contact = &phoneBook->contacts[i];
        if (strcmp(contact->name, name) == 0) {
            return contact;
        }
    }
    return NULL;
}

// Print a phone book.
void printPhoneBook(PhoneBook* phoneBook) {
    for (int i = 0; i < phoneBook->size; i++) {
        Contact* contact = &phoneBook->contacts[i];
        printf("%s: %s\n", contact->name, contact->number);
    }
}

// Main function.
int main() {
    // Create a new phone book with an initial capacity of 10 contacts.
    PhoneBook* phoneBook = createPhoneBook(10);

    // Add some contacts to the phone book.
    Contact contact1 = {"John Smith", "555-1212"};
    Contact contact2 = {"Jane Doe", "555-1213"};
    Contact contact3 = {"Bill Jones", "555-1214"};
    addContact(phoneBook, contact1);
    addContact(phoneBook, contact2);
    addContact(phoneBook, contact3);

    // Search for a contact in the phone book by name.
    Contact* contact = searchContactByName(phoneBook, "John Smith");
    if (contact != NULL) {
        printf("Found contact: %s: %s\n", contact->name, contact->number);
    } else {
        printf("Contact not found.\n");
    }

    // Print the phone book.
    printf("Phone book:\n");
    printPhoneBook(phoneBook);

    // Delete the phone book.
    deletePhoneBook(phoneBook);

    return 0;
}