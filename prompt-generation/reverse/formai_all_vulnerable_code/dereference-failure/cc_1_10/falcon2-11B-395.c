//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold diary entries
typedef struct diary_entry {
    char entry[100];
    struct diary_entry *next;
} diary_entry;

// Define a function to add an entry to the diary
void add_entry(diary_entry **diary) {
    diary_entry *new_entry = (diary_entry *)malloc(sizeof(diary_entry));
    strcpy(new_entry->entry, "");
    new_entry->next = NULL;

    // Traverse the diary list to find the last entry
    diary_entry *current = *diary;
    while (current->next!= NULL) {
        current = current->next;
    }

    // Add the new entry to the end of the list
    current->next = new_entry;
}

// Define a function to display the diary
void display_diary(diary_entry *diary) {
    diary_entry *current = diary;
    while (current!= NULL) {
        printf("%s\n", current->entry);
        current = current->next;
    }
}

// Define a function to delete an entry from the diary
void delete_entry(diary_entry **diary, char *entry) {
    diary_entry *current = *diary;
    diary_entry *prev = NULL;

    // Traverse the diary list to find the entry to be deleted
    while (current!= NULL && strcmp(current->entry, entry)!= 0) {
        prev = current;
        current = current->next;
    }

    // If the entry was found, delete it and free the memory
    if (current!= NULL) {
        if (prev == NULL) {
            *diary = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}

// Define the main function
int main() {
    diary_entry *diary = NULL;
    diary_entry *entry;

    // Prompt the user for a new entry
    printf("Enter a new diary entry: ");
    fgets(entry->entry, sizeof(entry->entry), stdin);

    // Add the new entry to the diary
    add_entry(&diary);

    // Display the diary
    display_diary(diary);

    // Prompt the user for an entry to delete
    printf("Enter an entry to delete: ");
    fgets(entry->entry, sizeof(entry->entry), stdin);

    // Delete the entry from the diary
    delete_entry(&diary, entry->entry);

    // Display the diary again
    display_diary(diary);

    return 0;
}