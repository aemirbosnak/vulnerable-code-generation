//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

// Structure to hold phone book entries
typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

// Function to compare two entries by name
int compare_entries(const void *a, const void *b) {
    const Entry *entry1 = a;
    const Entry *entry2 = b;
    return strcmp(entry1->name, entry2->name);
}

// Function to add an entry to the phone book
void add_entry(Entry *entries[], int num_entries, char name[], char number[]) {
    if (num_entries == MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i]->name, name) == 0) {
            printf("Duplicate name found.\n");
            return;
        }
    }
    strcpy(entries[num_entries]->name, name);
    strcpy(entries[num_entries]->number, number);
    num_entries++;
}

// Function to search for an entry in the phone book
Entry* search_entry(Entry *entries[], int num_entries, char name[]) {
    Entry *result = NULL;
    qsort(entries, num_entries, sizeof(Entry), compare_entries);
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i]->name, name) == 0) {
            result = entries[i];
            break;
        }
    }
    return result;
}

// Function to print the phone book
void print_phonebook(Entry *entries[], int num_entries) {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i]->name, entries[i]->number);
    }
}

int main() {
    Entry *entries[MAX_ENTRIES];
    int num_entries = 0;
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
    int choice;
    while (1) {
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Print phone book\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                add_entry(entries, num_entries, name, number);
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                Entry *result = search_entry(entries, num_entries, name);
                if (result == NULL) {
                    printf("Entry not found.\n");
                } else {
                    printf("Name: %s\nNumber: %s\n", result->name, result->number);
                }
                break;
            case 3:
                print_phonebook(entries, num_entries);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}