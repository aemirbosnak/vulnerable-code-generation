//FormAI DATASET v1.0 Category: Digital Diary ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum length of a diary entry
#define MAX_LENGTH 100

// define maximum number of entries in a diary
#define MAX_ENTRIES 10

// define structure for a diary entry
typedef struct {
    char date[11];
    char entry[MAX_LENGTH];
} DiaryEntry;

// define function to display main menu
void displayMenu() {
    printf("C Digital Diary\n\n");
    printf("1. View all entries\n");
    printf("2. Add a new entry\n");
    printf("3. Edit an existing entry\n");
    printf("4. Delete an existing entry\n");
    printf("5. Quit\n\n");
}

// define function to read input string
void readString(char *str, int maxLength) {
    fgets(str, maxLength, stdin);
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}

// define function to display all entries
void viewEntries(DiaryEntry *entries, int entryCount) {
    printf("Digital Diary Entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Date: %s\n", entries[i].date);
        printf("Entry: %s\n\n", entries[i].entry);
    }
}

// define function to add a new entry
void addEntry(DiaryEntry *entries, int *entryCount) {
    if (*entryCount >= MAX_ENTRIES) {
        printf("Maximum number of entries reached.\n\n");
        return;
    }
    printf("Enter date (MM/DD/YYYY): ");
    readString(entries[*entryCount].date, 11);
    printf("Enter entry: ");
    readString(entries[*entryCount].entry, MAX_LENGTH);
    (*entryCount)++;
    printf("Entry added successfully.\n\n");
}

// define function to edit an existing entry
void editEntry(DiaryEntry *entries, int entryCount) {
    printf("Enter date of entry to edit (MM/DD/YYYY): ");
    char date[11];
    readString(date, 11);
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            printf("Enter new date (MM/DD/YYYY): ");
            readString(entries[i].date, 11);
            printf("Enter new entry: ");
            readString(entries[i].entry, MAX_LENGTH);
            printf("Entry edited successfully.\n\n");
            return;
        }
    }
    printf("Entry not found.\n\n");
}

// define function to delete an existing entry
void deleteEntry(DiaryEntry *entries, int *entryCount) {
    printf("Enter date of entry to delete (MM/DD/YYYY): ");
    char date[11];
    readString(date, 11);
    for (int i = 0; i < *entryCount; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            for (int j = i; j < *entryCount - 1; j++) {
                strcpy(entries[j].date, entries[j + 1].date);
                strcpy(entries[j].entry, entries[j + 1].entry);
            }
            (*entryCount)--;
            printf("Entry deleted successfully.\n\n");
            return;
        }
    }
    printf("Entry not found.\n\n");
}

// define main function
int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int entryCount = 0;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        char choice[2];
        readString(choice, 2);
        printf("\n");
        switch (choice[0]) {
            case '1':
                viewEntries(entries, entryCount);
                break;
            case '2':
                addEntry(entries, &entryCount);
                break;
            case '3':
                editEntry(entries, entryCount);
                break;
            case '4':
                deleteEntry(entries, &entryCount);
                break;
            case '5':
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n\n");
                break;
        }
    }
}