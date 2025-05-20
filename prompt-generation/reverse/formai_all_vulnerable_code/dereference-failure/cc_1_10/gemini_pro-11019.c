//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Create a struct to represent a diary entry
typedef struct diary_entry {
    char *text;
    int date;
    int time;
} diary_entry;

// Create an array of diary entries
diary_entry entries[100];

// Initialize the diary entries with some funny text
void initialize_entries() {
    strcpy(entries[0].text, "Dear Diary,\nI'm so bored today. I wish something exciting would happen.");
    entries[0].date = 20230308;
    entries[0].time = 1430;

    strcpy(entries[1].text, "Dear Diary,\nI finally found something exciting to do! I'm going to a clown convention.");
    entries[1].date = 20230309;
    entries[1].time = 1000;

    strcpy(entries[2].text, "Dear Diary,\nThe clown convention was a disaster. I got lost in a maze of balloons and ended up getting chased by a giant rubber chicken.");
    entries[2].date = 20230310;
    entries[2].time = 1600;

    strcpy(entries[3].text, "Dear Diary,\nI'm never going to a clown convention again. I'm still traumatized by the giant rubber chicken.");
    entries[3].date = 20230311;
    entries[3].time = 1200;
}

// Print a diary entry
void print_entry(diary_entry entry) {
    printf("Date: %d\n", entry.date);
    printf("Time: %d\n", entry.time);
    printf("Text: %s\n", entry.text);
}

// Get a diary entry by date
diary_entry get_entry_by_date(int date) {
    for (int i = 0; i < 100; i++) {
        if (entries[i].date == date) {
            return entries[i];
        }
    }

    // Return an empty diary entry if no entry is found
    diary_entry empty_entry;
    empty_entry.text = "";
    empty_entry.date = 0;
    empty_entry.time = 0;
    return empty_entry;
}

// Add a new diary entry
void add_entry(diary_entry entry) {
    for (int i = 0; i < 100; i++) {
        if (entries[i].date == 0) {
            entries[i] = entry;
            return;
        }
    }

    // Print an error message if the diary is full
    printf("Error: Diary is full.\n");
}

// Delete a diary entry by date
void delete_entry(int date) {
    for (int i = 0; i < 100; i++) {
        if (entries[i].date == date) {
            entries[i].date = 0;
            entries[i].time = 0;
            entries[i].text = "";
            return;
        }
    }

    // Print an error message if the entry is not found
    printf("Error: Entry not found.\n");
}

// Print all diary entries
void print_all_entries() {
    for (int i = 0; i < 100; i++) {
        if (entries[i].date != 0) {
            print_entry(entries[i]);
        }
    }
}

// Main function
int main() {
    // Initialize the diary entries
    initialize_entries();

    // Get a diary entry by date
    diary_entry entry = get_entry_by_date(20230309);

    // Print the diary entry
    print_entry(entry);

    // Add a new diary entry
    diary_entry new_entry;
    new_entry.date = 20230312;
    new_entry.time = 1800;
    strcpy(new_entry.text, "Dear Diary,\nI'm so glad I'm not a clown.");
    add_entry(new_entry);

    // Delete a diary entry by date
    delete_entry(20230310);

    // Print all diary entries
    print_all_entries();

    return 0;
}