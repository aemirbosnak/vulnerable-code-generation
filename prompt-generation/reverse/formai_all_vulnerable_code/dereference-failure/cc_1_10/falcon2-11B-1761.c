//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* phone;
} Contact;

typedef struct {
    Contact* contact;
    struct HashEntry* next;
} HashEntry;

typedef struct {
    int size;
    HashEntry* entries;
} HashTable;

int hash(char* str) {
    int hash = 0;
    while (*str) {
        hash += *str;
        str++;
    }
    return hash;
}

Contact* get_contact(HashTable* table, char* name) {
    HashEntry* entry = table->entries;
    while (entry!= NULL) {
        if (strcmp(entry->contact->name, name) == 0) {
            return entry->contact;
        }
        entry = entry->next;
    }
    return NULL;
}

int add_contact(HashTable* table, char* name, char* phone) {
    Contact* contact = (Contact*) malloc(sizeof(Contact));
    contact->name = strdup(name);
    contact->phone = strdup(phone);

    int index = hash(contact->name);
    HashEntry* new_entry = (HashEntry*) malloc(sizeof(HashEntry));
    new_entry->contact = contact;
    new_entry->next = table->entries;
    table->entries = new_entry;

    return 0;
}

int main() {
    HashTable table;
    table.entries = NULL;
    table.size = 0;

    char name[100];
    char phone[20];

    printf("Enter a contact name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter a phone number: ");
    fgets(phone, sizeof(phone), stdin);

    add_contact(&table, name, phone);

    Contact* contact = get_contact(&table, name);
    if (contact == NULL) {
        printf("Contact not found\n");
    } else {
        printf("Name: %s\nPhone: %s\n", contact->name, contact->phone);
    }

    return 0;
}