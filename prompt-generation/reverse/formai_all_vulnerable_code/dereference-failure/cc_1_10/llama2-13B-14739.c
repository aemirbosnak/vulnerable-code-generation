//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_FILE "diary.txt"
#define MAX_ENTRIES 10

struct entry {
    char date[20];
    char entry[100];
};

int main() {
    struct entry entries[MAX_ENTRIES];
    int i, j;

    // Initialize the diary file
    if (freopen(DIARY_FILE, "w", stdout) == NULL) {
        perror("Error opening diary file");
        return 1;
    }

    // Read the current date and time
    time_t now = time(NULL);
    struct tm current_time = *localtime(&now);
    char date_str[20];
    strftime(date_str, sizeof(date_str), "%m/%d/%Y", &current_time);

    // Initialize the entries array
    for (i = 0; i < MAX_ENTRIES; i++) {
        entries[i].date[0] = '\0';
        entries[i].entry[0] = '\0';
    }

    // Read the diary entries from the file
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (fgets(entries[i].date, sizeof(entries[i].date), stdin) == NULL) {
            break;
        }
        if (fgets(entries[i].entry, sizeof(entries[i].entry), stdin) == NULL) {
            break;
        }
    }

    // Add a new entry
    if (fgets(date_str, sizeof(date_str), stdin) == NULL) {
        perror("Error reading date");
        return 1;
    }
    if (fgets(entries[MAX_ENTRIES].entry, sizeof(entries[MAX_ENTRIES].entry), stdin) == NULL) {
        perror("Error reading entry");
        return 1;
    }
    entries[MAX_ENTRIES].date[0] = '\0';

    // Print the diary entries
    for (i = 0; i < MAX_ENTRIES; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }

    // Close the diary file
    fclose(stdin);

    return 0;
}