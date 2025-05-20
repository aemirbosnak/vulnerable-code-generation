//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: recursive
/*
 * Digital Diary Example Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a diary entry
struct diary_entry {
    char date[11];
    char time[9];
    char message[256];
};

// Function to read a diary entry from the user
struct diary_entry read_diary_entry() {
    struct diary_entry entry;
    char line[256];

    // Prompt the user to enter the date and time
    printf("Enter the date and time: ");
    fgets(line, sizeof(line), stdin);
    strcpy(entry.date, line);
    strcpy(entry.time, line);

    // Prompt the user to enter the message
    printf("Enter the message: ");
    fgets(line, sizeof(line), stdin);
    strcpy(entry.message, line);

    return entry;
}

// Function to write a diary entry to the file
void write_diary_entry(FILE *file, struct diary_entry entry) {
    fprintf(file, "%s %s: %s", entry.date, entry.time, entry.message);
}

// Function to read a diary entry from the file
struct diary_entry read_diary_entry_from_file(FILE *file) {
    struct diary_entry entry;
    char line[256];

    // Read the date and time from the file
    fgets(line, sizeof(line), file);
    strcpy(entry.date, line);
    strcpy(entry.time, line);

    // Read the message from the file
    fgets(line, sizeof(line), file);
    strcpy(entry.message, line);

    return entry;
}

// Function to print a diary entry
void print_diary_entry(struct diary_entry entry) {
    printf("%s %s: %s", entry.date, entry.time, entry.message);
}

// Function to save a diary entry to the file
void save_diary_entry(FILE *file, struct diary_entry entry) {
    fprintf(file, "%s %s: %s", entry.date, entry.time, entry.message);
}

// Function to load a diary entry from the file
struct diary_entry load_diary_entry(FILE *file) {
    struct diary_entry entry;
    char line[256];

    // Read the date and time from the file
    fgets(line, sizeof(line), file);
    strcpy(entry.date, line);
    strcpy(entry.time, line);

    // Read the message from the file
    fgets(line, sizeof(line), file);
    strcpy(entry.message, line);

    return entry;
}

int main() {
    // Open the diary file
    FILE *diary_file = fopen("diary.txt", "a+");

    // Read the diary entries from the file
    struct diary_entry entry = read_diary_entry_from_file(diary_file);

    // Print the diary entries
    print_diary_entry(entry);

    // Write a new diary entry to the file
    struct diary_entry new_entry = read_diary_entry();
    save_diary_entry(diary_file, new_entry);

    // Close the diary file
    fclose(diary_file);

    return 0;
}