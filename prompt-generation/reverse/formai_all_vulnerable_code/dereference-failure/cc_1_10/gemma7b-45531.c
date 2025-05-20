//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

// Define a structure for a post-apocalyptic phone book entry
typedef struct PhoneBookEntry {
    char name[20];
    char number[20];
    struct PhoneBookEntry* next;
} PhoneBookEntry;

// Create a function to insert a new entry into the phone book
void insertEntry(PhoneBookEntry** head, char* name, char* number) {
    PhoneBookEntry* newEntry = (PhoneBookEntry*)malloc(sizeof(PhoneBookEntry));
    strcpy(newEntry->name, name);
    strcpy(newEntry->number, number);
    newEntry->next = NULL;

    if (*head == NULL) {
        *head = newEntry;
    } else {
        (*head)->next = newEntry;
    }
}

// Create a function to search for an entry in the phone book
PhoneBookEntry* searchEntry(PhoneBookEntry* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        } else {
            head = head->next;
        }
    }

    return NULL;
}

int main() {
    PhoneBookEntry* phoneBook = NULL;

    // Insert some entries into the phone book
    insertEntry(&phoneBook, "Bob", "555-123-4567");
    insertEntry(&phoneBook, "Alice", "555-456-7890");
    insertEntry(&phoneBook, "Charlie", "555-982-3415");

    // Search for an entry in the phone book
    PhoneBookEntry* entry = searchEntry(phoneBook, "Alice");

    // Print the entry's name and number
    if (entry) {
        printf("Name: %s\n", entry->name);
        printf("Number: %s\n", entry->number);
    } else {
        printf("Entry not found.\n");
    }

    return 0;
}