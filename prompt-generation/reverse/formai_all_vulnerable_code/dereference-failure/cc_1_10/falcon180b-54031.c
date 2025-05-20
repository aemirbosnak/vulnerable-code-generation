//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_ENTRIES 1000

// Define the structure of each entry in the phone book
typedef struct {
    char name[50];
    char phone_number[15];
} PhoneBookEntry;

// Define the structure of the phone book itself
typedef struct {
    int num_entries;
    PhoneBookEntry entries[MAX_NUM_ENTRIES];
} PhoneBook;

// Function to initialize an empty phone book
PhoneBook *phone_book_init() {
    PhoneBook *pb = malloc(sizeof(PhoneBook));
    pb->num_entries = 0;
    return pb;
}

// Function to add an entry to the phone book
void phone_book_add_entry(PhoneBook *pb, char *name, char *phone_number) {
    if (pb->num_entries >= MAX_NUM_ENTRIES) {
        printf("Error: Phone book is full.\n");
        return;
    }
    strcpy(pb->entries[pb->num_entries].name, name);
    strcpy(pb->entries[pb->num_entries].phone_number, phone_number);
    pb->num_entries++;
}

// Function to search for an entry in the phone book
int phone_book_search_entry(PhoneBook *pb, char *name) {
    for (int i = 0; i < pb->num_entries; i++) {
        if (strcmp(pb->entries[i].name, name) == 0) {
            printf("Found entry for %s: %s\n", name, pb->entries[i].phone_number);
            return 1;
        }
    }
    printf("Entry not found.\n");
    return 0;
}

// Function to print all entries in the phone book
void phone_book_print_entries(PhoneBook *pb) {
    for (int i = 0; i < pb->num_entries; i++) {
        printf("%s: %s\n", pb->entries[i].name, pb->entries[i].phone_number);
    }
}

// Function to free memory used by the phone book
void phone_book_free(PhoneBook *pb) {
    free(pb);
}

// Main function to demonstrate usage of the phone book functions
int main() {
    PhoneBook *pb = phone_book_init();
    phone_book_add_entry(pb, "John Smith", "555-1234");
    phone_book_add_entry(pb, "Jane Doe", "555-5678");
    phone_book_print_entries(pb);
    phone_book_search_entry(pb, "John Smith");
    phone_book_search_entry(pb, "Bob Johnson");
    phone_book_free(pb);
    return 0;
}