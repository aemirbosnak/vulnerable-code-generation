//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

typedef struct Entry {
    char name[20];
    int phone_number;
    struct Entry* next;
} Entry;

Entry* insert_entry(Entry* head, char* name, int phone_number) {
    Entry* new_entry = malloc(sizeof(Entry));
    strcpy(new_entry->name, name);
    new_entry->phone_number = phone_number;
    new_entry->next = NULL;

    if (head == NULL) {
        head = new_entry;
    } else {
        head->next = insert_entry(head->next, name, phone_number);
    }

    return head;
}

Entry* search_entry(Entry* head, char* name) {
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
    Entry* phone_book = NULL;

    insert_entry(phone_book, "Donald Knuth", 12345);
    insert_entry(phone_book, "Terry Tao", 65432);
    insert_entry(phone_book, "Martin Gardner", 48152);
    insert_entry(phone_book, "Richard Feynman", 21234);

    Entry* entry = search_entry(phone_book, "Terry Tao");

    if (entry) {
        printf("Phone number of Terry Tao: %d\n", entry->phone_number);
    } else {
        printf("Entry not found.\n");
    }

    return 0;
}