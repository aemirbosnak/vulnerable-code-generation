//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the diary structure
typedef struct {
    char *name;
    char *date;
    char *entry;
} diary_t;

// Function to create a new diary entry
void new_entry(diary_t *d, char *name, char *date, char *entry) {
    // Check if the diary is full
    if (d->name == NULL) {
        // Allocate memory for the diary
        d->name = (char *)malloc(sizeof(char *) * 3);
        d->date = (char *)malloc(sizeof(char *) * 3);
        d->entry = (char *)malloc(sizeof(char *) * 3);
    }

    // Set the name, date, and entry fields
    d->name = name;
    d->date = date;
    d->entry = entry;

    // Print a success message
    printf("New entry added successfully! 😊\n");
}

// Function to display the diary
void display_diary(diary_t *d) {
    // Print the name, date, and entry fields
    printf("Name: %s\nDate: %s\nEntry: %s\n", d->name, d->date, d->entry);
}

int main() {
    // Create a diary structure
    diary_t *d = (diary_t *)malloc(sizeof(diary_t));

    // Set the name, date, and entry fields
    d->name = "Happy";
    d->date = "Today";
    d->entry = "I had a great day today! 😊";

    // Add a new entry
    new_entry(d, "Sunny", "Yesterday", "Went for a walk in the park and saw some cute puppies 🐶");

    // Display the diary
    display_diary(d);

    // Free the diary memory
    free(d);

    return 0;
}