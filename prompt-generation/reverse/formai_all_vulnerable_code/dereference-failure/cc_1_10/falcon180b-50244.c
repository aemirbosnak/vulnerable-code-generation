//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

int main() {
    FILE *diary;
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[50];
    time_t now;
    struct tm *tm_now;

    printf("Welcome to your digital diary!\n");

    // Get the current date and time
    time(&now);
    tm_now = localtime(&now);
    strftime(filename, 50, "diary_%Y-%m-%d.txt", tm_now);

    // Open the diary file for reading
    diary = fopen(filename, "r");

    if (diary!= NULL) {
        // Read in existing entries
        while (num_entries < MAX_ENTRIES && fscanf(diary, "%s %s\n", entries[num_entries].date, entries[num_entries].entry)!= EOF) {
            num_entries++;
        }
        fclose(diary);
    }

    // Prompt the user for a new entry
    printf("Enter a new diary entry:\n");
    fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
    strcpy(entries[num_entries].date, ctime(&now));
    num_entries++;

    // Open the diary file for writing
    diary = fopen(filename, "w");

    if (diary!= NULL) {
        // Write out the entries
        for (int i = 0; i < num_entries; i++) {
            fprintf(diary, "%s %s\n", entries[i].date, entries[i].entry);
        }
        fclose(diary);
    } else {
        printf("Error: Could not open diary file for writing.\n");
    }

    return 0;
}