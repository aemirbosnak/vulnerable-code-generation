//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 10

typedef struct {
    char name[20];
    char phone[20];
    char email[20];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(const char* name, const char* phone, const char* email) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full, cannot add another entry.\n");
        return;
    }

    Entry entry;
    strcpy(entry.name, name);
    strcpy(entry.phone, phone);
    strcpy(entry.email, email);

    entries[num_entries] = entry;
    num_entries++;

    printf("Entry added successfully.\n");
}

void remove_entry(const char* name) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            for (int j = i; j < num_entries - 1; j++) {
                entries[j] = entries[j + 1];
            }
            num_entries--;
            break;
        }
    }
}

void print_phone_book() {
    printf("Phone Book:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s\nPhone: %s\nEmail: %s\n", entries[i].name, entries[i].phone, entries[i].email);
    }
}

int main() {
    add_entry("John Doe", "1234567890", "johndoe@example.com");
    add_entry("Jane Smith", "9876543210", "janesmith@example.com");
    print_phone_book();

    remove_entry("John Doe");
    print_phone_book();

    return 0;
}