//FormAI DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20 // Max length of strings: names, phone numbers.

typedef struct PhoneBookEntry {
    char name[MAX_LEN];
    char phone_number[MAX_LEN];
} PhoneBookEntry;

typedef struct PhoneBook {
    PhoneBookEntry *entries;
    int num_entries;
    int max_entries; // Maximum number of entries the phone book can hold.
} PhoneBook;

// Function prototypes.
void add_entry(PhoneBook *book, PhoneBookEntry entry);
void remove_entry(PhoneBook *book, char *name);
void search_entry(PhoneBook *book, char *name);
void print_all_entries(PhoneBook *book);

int main() {
    PhoneBook book;
    book.num_entries = 0;
    book.max_entries = 10; // Configurable max number of entries.
    book.entries = malloc(book.max_entries * sizeof(PhoneBookEntry));

    // Add some entries to start with.
    PhoneBookEntry entry1 = {"John Doe", "555-1234"};
    PhoneBookEntry entry2 = {"Jane Smith", "555-5678"};
    PhoneBookEntry entry3 = {"Bob Johnson", "555-9012"};
    add_entry(&book, entry1);
    add_entry(&book, entry2);
    add_entry(&book, entry3);

    // Menu loop.
    int choice = 0;
    while (choice != 5) {
        printf("Phone Book Menu:\n");
        printf("1. Add Entry\n");
        printf("2. Remove Entry\n");
        printf("3. Search for Entry\n");
        printf("4. Print All Entries\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline after scanning integer.

        switch (choice) {
            case 1: {
                // Add entry.
                PhoneBookEntry new_entry;
                printf("Enter name: ");
                fgets(new_entry.name, MAX_LEN, stdin);
                // Replace newline character with null terminator.
                new_entry.name[strcspn(new_entry.name, "\n")] = '\0';
                printf("Enter phone number: ");
                fgets(new_entry.phone_number, MAX_LEN, stdin);
                new_entry.phone_number[strcspn(new_entry.phone_number, "\n")] = '\0';
                add_entry(&book, new_entry);
                printf("Entry added.\n");
                break;
            }
            case 2: {
                // Remove entry.
                char name_to_remove[MAX_LEN];
                printf("Enter name to remove: ");
                fgets(name_to_remove, MAX_LEN, stdin);
                name_to_remove[strcspn(name_to_remove, "\n")] = '\0';
                remove_entry(&book, name_to_remove);
                break;
            }
            case 3: {
                // Search for entry.
                char name_to_search[MAX_LEN];
                printf("Enter name to search: ");
                fgets(name_to_search, MAX_LEN, stdin);
                name_to_search[strcspn(name_to_search, "\n")] = '\0';
                search_entry(&book, name_to_search);
                break;
            }
            case 4: {
                // Print all entries.
                print_all_entries(&book);
                break;
            }
            case 5:
                // Quit program.
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    free(book.entries);
    return 0;
}

void add_entry(PhoneBook *book, PhoneBookEntry entry) {
    if (book->num_entries == book->max_entries) {
        printf("Cannot add entry. Phone book is full.\n");
        return;
    }
    book->entries[book->num_entries] = entry;
    book->num_entries++;
}

void remove_entry(PhoneBook *book, char *name) {
    for (int i = 0; i < book->num_entries; i++) {
        if (strcmp(book->entries[i].name, name) == 0) {
            // Shift all entries down by one to overwrite the removed entry.
            for (int j = i; j < book->num_entries - 1; j++) {
                book->entries[j] = book->entries[j+1];
            }
            book->num_entries--;
            printf("Entry removed.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

void search_entry(PhoneBook *book, char *name) {
    for (int i = 0; i < book->num_entries; i++) {
        if (strcmp(book->entries[i].name, name) == 0) {
            printf("%s: %s\n", book->entries[i].name, book->entries[i].phone_number);
            return;
        }
    }
    printf("Entry not found.\n");
}

void print_all_entries(PhoneBook *book) {
    printf("Phone Book Entries:\n");
    for (int i = 0; i < book->num_entries; i++) {
        printf("%s: %s\n", book->entries[i].name, book->entries[i].phone_number);
    }
}