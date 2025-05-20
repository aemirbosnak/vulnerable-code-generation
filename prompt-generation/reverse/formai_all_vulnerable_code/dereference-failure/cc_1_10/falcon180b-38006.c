//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a phone book entry
typedef struct {
    char name[50];
    char phone[15];
} PhoneBookEntry;

// Define the structure of a phone book
typedef struct {
    int size;
    int capacity;
    PhoneBookEntry* entries;
} PhoneBook;

// Initialize a phone book with the given capacity
PhoneBook* CreatePhoneBook(int capacity) {
    PhoneBook* phoneBook = (PhoneBook*)malloc(sizeof(PhoneBook));
    phoneBook->size = 0;
    phoneBook->capacity = capacity;
    phoneBook->entries = (PhoneBookEntry*)malloc(capacity * sizeof(PhoneBookEntry));
    return phoneBook;
}

// Add an entry to the phone book
void AddEntry(PhoneBook* phoneBook, char* name, char* phone) {
    if (phoneBook->size >= phoneBook->capacity) {
        printf("Phone book is full.\n");
        return;
    }
    strcpy(phoneBook->entries[phoneBook->size].name, name);
    strcpy(phoneBook->entries[phoneBook->size].phone, phone);
    phoneBook->size++;
}

// Look up an entry in the phone book by name
PhoneBookEntry* LookupEntry(PhoneBook* phoneBook, char* name) {
    for (int i = 0; i < phoneBook->size; i++) {
        if (strcmp(phoneBook->entries[i].name, name) == 0) {
            return &phoneBook->entries[i];
        }
    }
    return NULL;
}

// Look up an entry in the phone book by phone number
PhoneBookEntry* LookupEntryByPhone(PhoneBook* phoneBook, char* phone) {
    for (int i = 0; i < phoneBook->size; i++) {
        if (strcmp(phoneBook->entries[i].phone, phone) == 0) {
            return &phoneBook->entries[i];
        }
    }
    return NULL;
}

// Print the entire phone book
void PrintPhoneBook(PhoneBook* phoneBook) {
    printf("Name\tPhone\n");
    for (int i = 0; i < phoneBook->size; i++) {
        printf("%s\t%s\n", phoneBook->entries[i].name, phoneBook->entries[i].phone);
    }
}

// Free the memory used by a phone book
void FreePhoneBook(PhoneBook* phoneBook) {
    free(phoneBook->entries);
    free(phoneBook);
}

// Example usage
int main() {
    PhoneBook* phoneBook = CreatePhoneBook(10);

    AddEntry(phoneBook, "John Doe", "123-4567");
    AddEntry(phoneBook, "Jane Smith", "555-1234");
    AddEntry(phoneBook, "Bob Johnson", "987-6543");

    PrintPhoneBook(phoneBook);

    PhoneBookEntry* entry = LookupEntry(phoneBook, "John Doe");
    if (entry!= NULL) {
        printf("Found entry for John Doe:\n");
        printf("Name: %s\n", entry->name);
        printf("Phone: %s\n", entry->phone);
    } else {
        printf("No entry found for John Doe.\n");
    }

    entry = LookupEntryByPhone(phoneBook, "555-1234");
    if (entry!= NULL) {
        printf("Found entry for 555-1234:\n");
        printf("Name: %s\n", entry->name);
        printf("Phone: %s\n", entry->phone);
    } else {
        printf("No entry found for 555-1234.\n");
    }

    FreePhoneBook(phoneBook);
    return 0;
}