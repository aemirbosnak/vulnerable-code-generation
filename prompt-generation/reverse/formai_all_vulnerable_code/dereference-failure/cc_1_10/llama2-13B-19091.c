//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: retro
// Retro Phone Book v1.0
// Compiled on Thu, 22-Apr-1987 using Turbo C v2.01

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define constants and structs
#define MAX_NAME_LEN 20
#define MAX_PHONE_LEN 15
#define PHONE_BOOK_SIZE 10

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} phone_book_entry;

// Function prototypes
phone_book_entry create_entry(char *name, char *phone);
void print_entry(phone_book_entry *entry);
int search_entry(phone_book_entry *entries, int num_entries, char *name);

// Global variables
phone_book_entry phone_book[PHONE_BOOK_SIZE];
int num_entries = 0;

// Main program
int main() {
    // Initialize phone book
    for (int i = 0; i < PHONE_BOOK_SIZE; i++) {
        phone_book[i].name[0] = '\0';
        phone_book[i].phone[0] = '\0';
    }

    // Add entries
    printf("Enter names and phones for up to 10 entries:\n");
    for (int i = 0; i < 10; i++) {
        char *name = malloc(MAX_NAME_LEN * sizeof(char));
        char *phone = malloc(MAX_PHONE_LEN * sizeof(char));
        printf("Entry %d: Name: ", i + 1);
        fgets(name, MAX_NAME_LEN, stdin);
        printf("Phone: ");
        fgets(phone, MAX_PHONE_LEN, stdin);
        create_entry(name, phone);
    }

    // Search for an entry
    char search_name[] = "John";
    int found = search_entry(phone_book, num_entries, search_name);
    if (found) {
        print_entry(&phone_book[found - 1]);
    } else {
        printf("No matching entry found.\n");
    }

    return 0;
}

// Functions
phone_book_entry create_entry(char *name, char *phone) {
    phone_book_entry new_entry;
    strcpy(new_entry.name, name);
    strcpy(new_entry.phone, phone);
    return new_entry;
}

void print_entry(phone_book_entry *entry) {
    printf("%s (%s)", entry->name, entry->phone);
}

int search_entry(phone_book_entry *entries, int num_entries, char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(name, entries[i].name) == 0) {
            return i;
        }
    }
    return -1;
}