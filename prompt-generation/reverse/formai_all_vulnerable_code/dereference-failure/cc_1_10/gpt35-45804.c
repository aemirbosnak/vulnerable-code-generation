//FormAI DATASET v1.0 Category: Digital Diary ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure of a diary entry
typedef struct {
    int day;
    int month;
    int year;
    char entry[250];
} entry_t;

// Function to get current date
void getCurrentDate(int *day, int *month, int *year) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    *day = tm.tm_mday;
    *month = tm.tm_mon + 1;
    *year = tm.tm_year + 1900;
}

// Function to print all entries in the diary
void printDiary(entry_t *entries, int num_entries) {
    printf("\n\n         MY DIARY\n");
    printf("---------------------------\n");

    for(int i = 0; i < num_entries; i++) {
        printf("%02d/%02d/%d\n%s\n\n", entries[i].day, entries[i].month, entries[i].year, entries[i].entry);
    }
}

int main() {
    entry_t *entries = NULL;
    int num_entries = 0;

    while(1) {
        printf("\n\nWhat would you like to do?\n");
        printf("1: Add an entry to the diary\n");
        printf("2: View all entries in the diary\n");
        printf("3: Quit\n");

        char choice[10];
        fgets(choice, 10, stdin);

        if(strncmp(choice, "1", 1) == 0) {
            printf("\nEnter your diary entry:\n");

            // Create a new entry
            entry_t new_entry;
            new_entry.day = 0;
            new_entry.month = 0;
            new_entry.year = 0;
            fgets(new_entry.entry, 250, stdin);

            // Get current date
            getCurrentDate(&new_entry.day, &new_entry.month, &new_entry.year);

            // Add the new entry to the diary
            num_entries++;
            entries = (entry_t *) realloc(entries, num_entries * sizeof(entry_t));
            entries[num_entries - 1] = new_entry;

            printf("\nEntry added to diary.\n");
        }
        else if(strncmp(choice, "2", 1) == 0) {
            if(num_entries == 0) {
                printf("\nYour diary is empty.\n");
            }
            else {
                printDiary(entries, num_entries);
            }
        }
        else if(strncmp(choice, "3", 1) == 0) {
            printf("\nGoodbye!\n");
            break;
        }
        else {
            printf("\nInvalid choice.\n");
        }
    }

    if(entries != NULL) {
        free(entries);
    }

    return 0;
}