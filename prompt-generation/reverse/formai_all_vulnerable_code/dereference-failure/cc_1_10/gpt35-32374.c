//FormAI DATASET v1.0 Category: Phone Book ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for our PhoneBookEntry
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} PhoneBookEntry;

// Define the structure for our PhoneBook
typedef struct {
    PhoneBookEntry* entries;
    int capacity;
    int size;
} PhoneBook;

// Initialize a new PhoneBook with a given size
void initPhoneBook(PhoneBook* pb, int size) {
    pb->entries = (PhoneBookEntry*) malloc(size * sizeof(PhoneBookEntry));
    pb->capacity = size;
    pb->size = 0;
}

// Add a new PhoneBookEntry to the PhoneBook
void addEntry(PhoneBook* pb, PhoneBookEntry entry) {
    if (pb->size == pb->capacity) {
        printf("Error: PhoneBook capacity exceeded.");
        return;
    }
    
    pb->entries[pb->size] = entry;
    pb->size++;
}

// Find a PhoneBookEntry in the PhoneBook by name
PhoneBookEntry* findEntryByName(PhoneBook* pb, char* name) {
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->entries[i].name, name) == 0) {
            return &pb->entries[i];
        }
    }
    return NULL;
}

// Print the contents of a PhoneBookEntry
void printEntry(PhoneBookEntry* entry) {
    printf("%s: %s, %s\n", entry->name, entry->phone, entry->email);
}

// Print the contents of the entire PhoneBook
void printPhoneBook(PhoneBook* pb) {
    for (int i = 0; i < pb->size; i++) {
        PhoneBookEntry* entry = &pb->entries[i];
        printEntry(entry);
    }
    printf("\n");
}

int main() {
    // Initialize our PhoneBook
    PhoneBook pb;
    initPhoneBook(&pb, 10);
    
    // Add some entries to the PhoneBook
    PhoneBookEntry entry1 = {"John Smith", "555-1234", "jsmith@example.com"};
    addEntry(&pb, entry1);
    PhoneBookEntry entry2 = {"Jane Doe", "555-5678", "jdoe@example.com"};
    addEntry(&pb, entry2);
    
    // Find and print a specific entry
    PhoneBookEntry* entry = findEntryByName(&pb, "John Smith");
    if (entry != NULL) {
        printEntry(entry);
    } else {
        printf("Entry not found.\n");
    }
    
    // Print the entire PhoneBook
    printPhoneBook(&pb);
    
    // Free the memory allocated for our PhoneBook
    free(pb.entries);
    
    return 0;
}