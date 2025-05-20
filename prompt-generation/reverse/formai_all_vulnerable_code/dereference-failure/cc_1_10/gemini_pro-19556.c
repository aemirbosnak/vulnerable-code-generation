//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Sherlock Holmes
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY_SIZE 1024

// The digital diary structure
typedef struct {
    char *title;
    char *entry;
    time_t timestamp;
} diary_entry;

// The digital diary array
diary_entry diary[100];

// The current number of entries in the diary
int num_entries = 0;

// Function to add a new entry to the diary
void add_entry(char *title, char *entry) {
    // Allocate memory for the new entry
    diary[num_entries].title = malloc(strlen(title) + 1);
    diary[num_entries].entry = malloc(strlen(entry) + 1);

    // Copy the title and entry into the new entry
    strcpy(diary[num_entries].title, title);
    strcpy(diary[num_entries].entry, entry);

    // Set the timestamp of the new entry
    diary[num_entries].timestamp = time(NULL);

    // Increment the number of entries in the diary
    num_entries++;
}

// Function to print the diary
void print_diary() {
    for (int i = 0; i < num_entries; i++) {
        printf("Title: %s\n", diary[i].title);
        printf("Entry: %s\n", diary[i].entry);
        printf("Timestamp: %s\n", ctime(&diary[i].timestamp));
        printf("\n");
    }
}

// Main function
int main() {
    // Add some sample entries to the diary
    add_entry("The Red-Headed League", "A curious case involving a pawnbroker, a red-headed man, and a secret society.");
    add_entry("The Adventure of the Speckled Band", "A young woman seeks Holmes' help after being terrorized by her stepfather.");
    add_entry("The Case of the Dancing Men", "Holmes investigates a series of coded messages that appear to be linked to a murder.");

    // Print the diary
    print_diary();

    return 0;
}