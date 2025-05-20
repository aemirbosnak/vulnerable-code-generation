//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a diary entry
typedef struct diary_entry {
    char date[11];
    char time[6];
    char title[51];
    char content[1001];
} diary_entry;

// Function to create a new diary entry
diary_entry* create_entry(char* date, char* time, char* title, char* content) {
    diary_entry* entry = malloc(sizeof(diary_entry));
    strcpy(entry->date, date);
    strcpy(entry->time, time);
    strcpy(entry->title, title);
    strcpy(entry->content, content);
    return entry;
}

// Function to print a diary entry
void print_entry(diary_entry* entry) {
    printf("Date: %s\n", entry->date);
    printf("Time: %s\n", entry->time);
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n\n", entry->content);
}

// Function to add a new entry to the diary
void add_entry(diary_entry** diary, int* num_entries) {
    char date[11], time[6], title[51], content[1001];
    printf("Enter date (yyyy-mm-dd): ");
    scanf("%s", date);
    printf("Enter time (hh:mm): ");
    scanf("%s", time);
    printf("Enter title: ");
    scanf(" %[^\n]s", title); // Read the entire line as the title
    printf("Enter content: ");
    scanf(" %[^\n]s", content); // Read the entire line as the content
    diary_entry* new_entry = create_entry(date, time, title, content);
    diary[*num_entries] = new_entry;
    (*num_entries)++;
}

// Function to search for a diary entry by title
void search_entry(diary_entry** diary, int num_entries) {
    char title[51];
    printf("Enter title to search for: ");
    scanf(" %[^\n]s", title); // Read the entire line as the title
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(diary[i]->title, title) == 0) {
            print_entry(diary[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No entry found with that title.\n");
    }
}

// Function to edit a diary entry by title
void edit_entry(diary_entry** diary, int num_entries) {
    char title[51];
    printf("Enter title of entry to edit: ");
    scanf(" %[^\n]s", title); // Read the entire line as the title
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(diary[i]->title, title) == 0) {
            char new_content[1001];
            printf("Enter new content: ");
            scanf(" %[^\n]s", new_content); // Read the entire line as the new content
            strcpy(diary[i]->content, new_content);
            printf("Entry updated successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No entry found with that title.\n");
    }
}

// Function to delete a diary entry by title
void delete_entry(diary_entry** diary, int* num_entries) {
    char title[51];
    printf("Enter title of entry to delete: ");
    scanf(" %[^\n]s", title); // Read the entire line as the title
    int found = 0;
    for (int i = 0; i < *num_entries; i++) {
        if (strcmp(diary[i]->title, title) == 0) {
            free(diary[i]);
            for (int j = i; j < *num_entries - 1; j++) {
                diary[j] = diary[j + 1];
            }
            (*num_entries)--;
            printf("Entry deleted successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No entry found with that title.\n");
    }
}

// Function to print all diary entries
void print_all_entries(diary_entry** diary, int num_entries) {
    if (num_entries == 0) {
        printf("No entries to display.\n");
        return;
    }
    for (int i = 0; i < num_entries; i++) {
        print_entry(diary[i]);
    }
}

// Main function
int main() {
    // Initialize the diary as an array of pointers to diary entries
    diary_entry** diary = malloc(0 * sizeof(diary_entry*));

    // Initialize the number of entries to 0
    int num_entries = 0;

    // Main loop to interact with the user
    while (1) {
        int choice;
        printf("1. Add new entry\n2. Search for entry\n3. Edit entry\n4. Delete entry\n5. Print all entries\n6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(diary, &num_entries);
                break;
            case 2:
                search_entry(diary, num_entries);
                break;
            case 3:
                edit_entry(diary, num_entries);
                break;
            case 4:
                delete_entry(diary, &num_entries);
                break;
            case 5:
                print_all_entries(diary, num_entries);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    }

    // Free the memory allocated for the diary
    for (int i = 0; i < num_entries; i++) {
        free(diary[i]);
    }
    free(diary);

    return 0;
}