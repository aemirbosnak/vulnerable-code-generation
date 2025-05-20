//FormAI DATASET v1.0 Category: Digital Diary ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ENTRIES 100

// Function to get current date and time
void getDateAndTime(char* date_time) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date_time, "%d/%d/%d %d:%02d:%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
}

// Entry struct to store diary entries
struct entry {
    char date_time[20];
    char content[500];
};

// Function to print the menu and get user choice
char getMenuChoice() {
    char choice;
    printf("------ Digital Diary ------\n");
    printf("[1] Add Entry\n");
    printf("[2] View Entries\n");
    printf("[3] Exit\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);
    return choice;
}

// Function to add an entry to the diary
void addEntry(struct entry* diary, int* num_entries) {
    if (*num_entries == MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    char date_time[20];
    getDateAndTime(date_time);
    printf("Enter your diary entry: ");
    scanf(" %[^\n]%*c", diary[*num_entries].content);
    sprintf(diary[*num_entries].date_time, "%s", date_time);
    *num_entries += 1;
    printf("Entry added successfully!\n");
}

// Function to view all diary entries or those on a specific date
void viewEntries(struct entry* diary, int num_entries) {
    char date[20];
    printf("Enter a date (dd/mm/yyyy) to view entries: ");
    scanf(" %[^\n]%*c", date);

    int num_entries_found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(diary[i].date_time, date) == 0) {
            printf("\nDate and Time: %s\n", diary[i].date_time);
            printf("Entry: %s\n", diary[i].content);
            num_entries_found++;
        }
    }

    if (num_entries_found == 0) {
        printf("No entries found for the selected date!\n");
    }
}

// Main function
int main() {
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0;
    char choice = ' ';

    while (choice != '3') {
        choice = getMenuChoice();

        switch (choice) {
            case '1':
                addEntry(diary, &num_entries);
                break;
            case '2':
                viewEntries(diary, num_entries);
                break;
            case '3':
                printf("\nExiting the diary... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}