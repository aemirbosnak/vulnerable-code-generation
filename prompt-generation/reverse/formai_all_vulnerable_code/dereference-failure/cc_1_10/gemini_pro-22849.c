//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _phone_entry {
    char name[32];
    char number[16];
    struct _phone_entry *next;
} phone_entry;

phone_entry *head = NULL;

void add_entry(char *name, char *number) {
    phone_entry *new_entry = malloc(sizeof(phone_entry));
    strcpy(new_entry->name, name);
    strcpy(new_entry->number, number);
    new_entry->next = head;
    head = new_entry;
}

void print_entry(phone_entry *entry) {
    printf("%s: %s\n", entry->name, entry->number);
}

void print_all_entries() {
    phone_entry *current = head;
    while (current != NULL) {
        print_entry(current);
        current = current->next;
    }
}

void delete_entry(char *name) {
    phone_entry *current = head;
    phone_entry *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    add_entry("John Doe", "555-1212");
    add_entry("Jane Smith", "555-1213");
    add_entry("Bill Jones", "555-1214");
    print_all_entries();
    delete_entry("Jane Smith");
    print_all_entries();
    return 0;
}