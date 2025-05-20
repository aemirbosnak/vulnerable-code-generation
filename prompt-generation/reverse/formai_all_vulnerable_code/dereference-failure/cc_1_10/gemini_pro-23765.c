//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of entries in the diary
#define MAX_ENTRIES 100

// Define the structure of a diary entry
typedef struct {
    char *title;
    char *content;
    int date;
} diary_entry;

// Initialize the diary with no entries
diary_entry diary[MAX_ENTRIES];
int num_entries = 0;

// Function to add a new entry to the diary
void add_entry(char *title, char *content, int date) {
    // Check if the diary is full
    if (num_entries == MAX_ENTRIES) {
        printf("Error: Diary is full.\n");
        return;
    }

    // Allocate memory for the new entry
    diary[num_entries].title = malloc(strlen(title) + 1);
    diary[num_entries].content = malloc(strlen(content) + 1);

    // Copy the title and content into the new entry
    strcpy(diary[num_entries].title, title);
    strcpy(diary[num_entries].content, content);

    // Set the date of the new entry
    diary[num_entries].date = date;

    // Increment the number of entries in the diary
    num_entries++;
}

// Function to print an entry from the diary
void print_entry(int index) {
    // Check if the index is valid
    if (index < 0 || index >= num_entries) {
        printf("Error: Invalid index.\n");
        return;
    }

    // Print the title of the entry
    printf("Title: %s\n", diary[index].title);

    // Print the content of the entry
    printf("Content: %s\n", diary[index].content);

    // Print the date of the entry
    printf("Date: %d\n", diary[index].date);
}

// Function to delete an entry from the diary
void delete_entry(int index) {
    // Check if the index is valid
    if (index < 0 || index >= num_entries) {
        printf("Error: Invalid index.\n");
        return;
    }

    // Free the memory allocated for the entry
    free(diary[index].title);
    free(diary[index].content);

    // Shift the entries after the deleted entry to the left
    for (int i = index; i < num_entries - 1; i++) {
        diary[i] = diary[i + 1];
    }

    // Decrement the number of entries in the diary
    num_entries--;
}

// Function to search for an entry in the diary by title
int search_entry(char *title) {
    // Iterate over the entries in the diary
    for (int i = 0; i < num_entries; i++) {
        // Check if the title of the entry matches the search term
        if (strcmp(diary[i].title, title) == 0) {
            // Return the index of the entry
            return i;
        }
    }

    // Return -1 if the entry was not found
    return -1;
}

// Function to sort the entries in the diary by date in ascending order
void sort_entries() {
    // Iterate over the entries in the diary
    for (int i = 0; i < num_entries - 1; i++) {
        // Find the index of the entry with the smallest date
        int min_index = i;
        for (int j = i + 1; j < num_entries; j++) {
            if (diary[j].date < diary[min_index].date) {
                min_index = j;
            }
        }

        // Swap the entries at the current index and the index of the entry with the smallest date
        diary_entry temp = diary[i];
        diary[i] = diary[min_index];
        diary[min_index] = temp;
    }
}

// Function to print the diary
void print_diary() {
    // Iterate over the entries in the diary
    for (int i = 0; i < num_entries; i++) {
        // Print the title of the entry
        printf("Title: %s\n", diary[i].title);

        // Print the content of the entry
        printf("Content: %s\n", diary[i].content);

        // Print the date of the entry
        printf("Date: %d\n\n", diary[i].date);
    }
}

// Main function
int main() {
    // Add some entries to the diary
    add_entry("My First Entry", "This is my first entry in my digital diary.", 20230308);
    add_entry("My Second Entry", "This is my second entry in my digital diary.", 20230309);
    add_entry("My Third Entry", "This is my third entry in my digital diary.", 20230310);

    // Print the diary
    print_diary();

    // Search for an entry in the diary
    int index = search_entry("My Second Entry");
    if (index != -1) {
        printf("Found entry with title 'My Second Entry' at index %d.\n", index);
    } else {
        printf("Entry with title 'My Second Entry' not found.\n");
    }

    // Sort the entries in the diary by date
    sort_entries();

    // Print the sorted diary
    printf("Sorted diary:\n");
    print_diary();

    // Delete an entry from the diary
    delete_entry(1);

    // Print the diary again
    printf("Diary after deleting the second entry:\n");
    print_diary();

    return 0;
}