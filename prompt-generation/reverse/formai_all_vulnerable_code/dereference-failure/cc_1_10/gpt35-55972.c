//FormAI DATASET v1.0 Category: Phone Book ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} phone_book_entry;

int num_entries = 0;
phone_book_entry *entries = NULL;

void add_new_entry() {
    char temp_name[MAX_NAME_LENGTH];
    char temp_phone[MAX_PHONE_LENGTH];

    printf("Enter name: ");
    scanf("%s", temp_name);
    printf("Enter phone number: ");
    scanf("%s", temp_phone);

    if (num_entries == 0) {
        entries = (phone_book_entry*) malloc(sizeof(phone_book_entry));
    } else {
        entries = (phone_book_entry*) realloc(entries, (num_entries + 1) * sizeof(phone_book_entry));
    }

    strncpy(entries[num_entries].name, temp_name, MAX_NAME_LENGTH);
    strncpy(entries[num_entries].phone, temp_phone, MAX_PHONE_LENGTH);
    num_entries++;
}

void search_by_name() {
    char name_to_search[MAX_NAME_LENGTH];
    int found = 0;

    printf("Enter name to search: ");
    scanf("%s", name_to_search);

    for (int i = 0; i < num_entries; i++) {
        if (strncmp(name_to_search, entries[i].name, MAX_NAME_LENGTH) == 0) {
            printf("Phone number for %s: %s\n", entries[i].name, entries[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No entry found for %s\n", name_to_search);
    }
}

void print_all_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].phone);
    }
}

int main() {
    char input = '0';

    while (1) {
        printf("Enter a command:\n");
        printf("[1] Add new entry\n");
        printf("[2] Search by name\n");
        printf("[3] Print all entries\n");
        printf("[0] Exit\n");
        printf("> ");

        scanf("%c", &input);

        switch (input) {
            case '1':
                add_new_entry();
                break;
            case '2':
                search_by_name();
                break;
            case '3':
                print_all_entries();
                break;
            case '0':
                printf("Exiting...\n");
                free(entries);
                return 0;
                break;
            default:
                printf("Invalid command!\n");
                break;
        }
    }

    return 0;
}