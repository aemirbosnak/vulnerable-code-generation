//FormAI DATASET v1.0 Category: Digital Diary ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char* date;
    char* time;
    char* entry;
} DiaryEntry;

int entriesCount = 0;
DiaryEntry entries[MAX_ENTRIES];

void printMenu() {
    printf("\n1. Add entry\n");
    printf("2. View all entries\n");
    printf("3. View entries by date\n");
    printf("4. Delete all entries\n");
    printf("5. Exit\n");
}

void addEntry() {
    if (entriesCount == MAX_ENTRIES) {
        printf("\nDiary is full. Delete some entries to add new ones.\n");
        return;
    }
    DiaryEntry entry;
    entry.date = (char*)malloc(20*sizeof(char));
    entry.time = (char*)malloc(20*sizeof(char));
    entry.entry = (char*)malloc(400*sizeof(char));
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(entry.date, 20, "%Y-%m-%d", timeinfo);
    strftime(entry.time, 20, "%H:%M:%S", timeinfo);
    printf("\nEnter your entry (Max. 400 characters):\n");
    getchar();
    fgets(entry.entry, 400, stdin);
    entries[entriesCount++] = entry;
    printf("\nEntry added successfully!\n");
}

void viewAllEntries() {
    if (entriesCount == 0) {
        printf("\nNo entries found!\n");
        return;
    }
    printf("\nAll Entries:\n\n");
    for (int i = 0; i < entriesCount; i++) {
        printf("%s %s:\n%s\n", entries[i].date, entries[i].time, entries[i].entry);
    }
}

void viewEntriesByDate() {
    char date[20];
    printf("\nEnter date (e.g.: 2022-08-01):\n");
    scanf("%s", date);
    printf("\nEntries on %s:\n\n", date);
    int count = 0;
    for (int i = 0; i < entriesCount; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            printf("%s %s:\n%s\n", entries[i].date, entries[i].time, entries[i].entry);
            count++;
        }
    }
    if (count == 0) {
        printf("No entries found on %s\n", date);
    }
}

void deleteAllEntries() {
    entriesCount = 0;
    printf("\nAll entries deleted successfully!\n");
}

int main() {
    int choice;
    do {
        printMenu();
        printf("\nEnter your choice (1-5):\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewAllEntries();
                break;
            case 3:
                viewEntriesByDate();
                break;
            case 4:
                deleteAllEntries();
                break;
            case 5:
                printf("\nExiting. Bye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}