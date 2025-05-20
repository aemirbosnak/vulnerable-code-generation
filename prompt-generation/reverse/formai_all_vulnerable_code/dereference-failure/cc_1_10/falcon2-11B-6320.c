//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <string.h>

// Struct to store phone book data
struct PhoneBook {
    char name[100];
    char number[20];
};

// Function to add a new entry to the phone book
void addEntry(struct PhoneBook *pb, char *name, char *number) {
    strcpy(pb->name, name);
    strcpy(pb->number, number);
}

// Function to search for an entry in the phone book
int searchEntry(struct PhoneBook *pb, char *name) {
    int i;
    for (i = 0; i < sizeof(pb->name) / sizeof(pb->name[0]); i++) {
        if (strcmp(pb->name[i], name) == 0) {
            printf("Found %s's number: %s\n", name, pb->number[i]);
            return 1;
        }
    }
    return 0;
}

// Function to delete an entry from the phone book
void deleteEntry(struct PhoneBook *pb, char *name) {
    int i;
    for (i = 0; i < sizeof(pb->name) / sizeof(pb->name[0]); i++) {
        if (strcmp(pb->name[i], name) == 0) {
            memset(pb->name, 0, sizeof(pb->name));
            memset(pb->number, 0, sizeof(pb->number));
            printf("Deleted %s\n", name);
            return;
        }
    }
    printf("Entry not found\n");
}

// Function to print the phone book
void printPhoneBook(struct PhoneBook *pb) {
    int i;
    for (i = 0; i < sizeof(pb->name) / sizeof(pb->name[0]); i++) {
        printf("Name: %s\nNumber: %s\n", pb->name[i], pb->number[i]);
    }
}

// Main function
int main() {
    struct PhoneBook phoneBook[10];

    // Adding entries to the phone book
    addEntry(phoneBook, "John", "1234567890");
    addEntry(phoneBook, "Alice", "0987654321");
    addEntry(phoneBook, "Bob", "9876543210");

    // Searching for an entry
    searchEntry(phoneBook, "Alice");
    searchEntry(phoneBook, "Dave");

    // Deleting an entry
    deleteEntry(phoneBook, "John");

    // Printing the phone book
    printPhoneBook(phoneBook);

    return 0;
}