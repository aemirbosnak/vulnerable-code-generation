//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 10

// Define the struct for each contact
struct contact {
    char name[MAX_NAME_LENGTH + 1];
    char phone[MAX_PHONE_LENGTH + 1];
};

// Define the hash table
struct hash_table {
    struct contact **table;
    int size;
};

// Hash function to compute the index of a contact in the hash table
unsigned int hash_function(const char *key) {
    unsigned int hash = 0;
    while (*key!= '\0') {
        hash = (hash << 2) ^ *key++;
    }
    return hash % MAX_CONTACTS;
}

// Create a new contact and add it to the hash table
void add_contact(struct hash_table *table, const char *name, const char *phone) {
    unsigned int index = hash_function(name);
    struct contact *contact = (struct contact*) malloc(sizeof(struct contact));
    strcpy(contact->name, name);
    strcpy(contact->phone, phone);
    table->table[index] = contact;
    table->size++;
}

// Search for a contact in the hash table
struct contact *search_contact(struct hash_table *table, const char *name) {
    unsigned int index = hash_function(name);
    return table->table[index];
}

// Print all contacts in the hash table
void print_contacts(struct hash_table *table) {
    for (int i = 0; i < table->size; i++) {
        printf("Name: %s\nPhone: %s\n", table->table[i]->name, table->table[i]->phone);
    }
}

// Free memory allocated for the hash table
void free_hash_table(struct hash_table *table) {
    for (int i = 0; i < table->size; i++) {
        free(table->table[i]);
    }
    free(table->table);
    free(table);
}

int main() {
    struct hash_table *phone_book = (struct hash_table*) malloc(sizeof(struct hash_table));
    phone_book->size = 0;
    phone_book->table = (struct contact**) malloc(MAX_CONTACTS * sizeof(struct contact*));
    
    add_contact(phone_book, "John Smith", "1234567890");
    add_contact(phone_book, "Jane Doe", "0987654321");
    add_contact(phone_book, "Bob Johnson", "5555555555");
    
    print_contacts(phone_book);
    
    struct contact *contact = search_contact(phone_book, "John Smith");
    if (contact!= NULL) {
        printf("Phone: %s\n", contact->phone);
    } else {
        printf("Contact not found.\n");
    }
    
    free_hash_table(phone_book);
    
    return 0;
}