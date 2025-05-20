//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DAY_LENGTH 24 * 60 * 60
#define WEEK_LENGTH 7 * DAY_LENGTH
#define MONTH_LENGTH 30 * DAY_LENGTH
#define YEAR_LENGTH 365 * DAY_LENGTH

// Structure to store diary entries
typedef struct {
    int day;      // Day of the month (1-31)
    int month;    // Month of the year (1-12)
    int year;     // Year (1900-2099)
    char entry[100]; // Entry text (up to 100 characters)
} diary_entry;

// Function to read and write diary entries
void read_diary(const char* filename) {
    // Open the diary file in read mode
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open diary file %s\n", filename);
        return;
    }

    // Read the diary entries from the file
    diary_entry entry;
    while (fread(&entry, sizeof(diary_entry), 1, file) == 1) {
        // Print the entry date and text
        printf("%d %d %d: %s\n", entry.day, entry.month, entry.year, entry.entry);
    }

    // Close the diary file
    fclose(file);
}

// Function to write a new diary entry
void write_diary(const char* filename) {
    // Open the diary file in write mode
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open diary file %s\n", filename);
        return;
    }

    // Get the current date and time
    time_t now = time(NULL);
    struct tm* current_time = localtime(&now);
    int day = current_time->tm_mday;
    int month = current_time->tm_mon;
    int year = current_time->tm_year;

    // Create a new diary entry
    diary_entry entry;
    entry.day = day;
    entry.month = month;
    entry.year = year;
    fgets(entry.entry, 100, stdin);

    // Write the entry to the diary file
    fwrite(&entry, sizeof(diary_entry), 1, file);

    // Close the diary file
    fclose(file);
}

int main() {
    // Prompt the user to enter a diary entry
    printf("Enter a diary entry (press enter for today): ");
    char entry[100];
    fgets(entry, 100, stdin);

    // Determine the current date and time
    time_t now = time(NULL);
    struct tm* current_time = localtime(&now);
    int day = current_time->tm_mday;
    int month = current_time->tm_mon;
    int year = current_time->tm_year;

    // Write the entry to the diary file
    write_diary("diary.txt");

    return 0;
}