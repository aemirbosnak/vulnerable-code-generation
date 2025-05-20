//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 10
#define HASH_SIZE 100

// Hash function for phone book entries
int hash(const char *name) {
    int hash_value = 0;
    while (*name) {
        hash_value += (*name++);
    }
    return hash_value % HASH_SIZE;
}

// Hash table for phone book entries
struct PhoneBookEntry {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
    struct PhoneBookEntry *next;
};

struct PhoneBookEntry *phone_book[HASH_SIZE];
int phone_book_count = 0;

// Function to add a new contact to the phone book
void add_contact(const char *name, const char *number) {
    struct PhoneBookEntry *new_entry = (struct PhoneBookEntry *)malloc(sizeof(struct PhoneBookEntry));
    strcpy(new_entry->name, name);
    strcpy(new_entry->number, number);
    new_entry->next = NULL;
    int hash_value = hash(name);
    new_entry->next = phone_book[hash_value];
    phone_book[hash_value] = new_entry;
    phone_book_count++;
}

// Function to search for a contact in the phone book
struct PhoneBookEntry *search_contact(const char *name) {
    int hash_value = hash(name);
    struct PhoneBookEntry *entry = phone_book[hash_value];
    while (entry!= NULL) {
        if (strcmp(entry->name, name) == 0) {
            return entry;
        }
        entry = entry->next;
    }
    return NULL;
}

// Function to display all contacts in the phone book
void display_contacts() {
    printf("Phone Book\n==============================\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        struct PhoneBookEntry *entry = phone_book[i];
        while (entry!= NULL) {
            printf("%s: %s\n", entry->name, entry->number);
            entry = entry->next;
        }
    }
    printf("==============================\n");
}

int main() {
    add_contact("John", "123-456-7890");
    add_contact("Jane", "987-654-3210");
    add_contact("Bob", "555-123-4567");
    display_contacts();
    struct PhoneBookEntry *entry = search_contact("Jane");
    if (entry!= NULL) {
        printf("Contact found: %s - %s\n", entry->name, entry->number);
        free(entry);
    }
    else {
        printf("Contact not found\n");
    }
    return 0;
}