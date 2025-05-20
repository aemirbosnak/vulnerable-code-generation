//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define BUF_SIZE 256

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char entry[BUF_SIZE];
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int entryCount = 0;

void displayMenu() {
    printf("\n====================\n");
    printf("     Digital Diary   \n");
    printf("====================\n");
    printf("1. Add Diary Entry\n");
    printf("2. View All Entries\n");
    printf("3. Search Entry by Date\n");
    printf("4. Delete Entry by Date\n");
    printf("5. Exit\n");
    printf("====================\n");
    printf("Choose an option: ");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Can't add more entries.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(entries[entryCount].date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    
    printf("Enter your diary entry (max %d characters): ", BUF_SIZE - 1);
    getchar(); // Clear newline from input buffer
    fgets(entries[entryCount].entry, BUF_SIZE, stdin);
    
    // Remove newline character if present
    size_t len = strlen(entries[entryCount].entry);
    if (len > 0 && entries[entryCount].entry[len-1] == '\n') {
        entries[entryCount].entry[len-1] = '\0';
    }
    
    entryCount++;
    printf("Entry added for date: %s\n", entries[entryCount - 1].date);
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries found!\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        printf("Date: %s\n", entries[i].date);
        printf("Entry: %s\n\n", entries[i].entry);
    }
}

void searchEntry() {
    char date[11];
    printf("Enter date to search (YYYY-MM-DD): ");
    scanf("%10s", date);
    
    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            printf("Date: %s\n", entries[i].date);
            printf("Entry: %s\n", entries[i].entry);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No entry found for date: %s\n", date);
    }
}

void deleteEntry() {
    char date[11];
    printf("Enter date to delete (YYYY-MM-DD): ");
    scanf("%10s", date);

    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            found = 1;
            // Shift entries to delete the current one
            for (int j = i; j < entryCount - 1; j++) {
                entries[j] = entries[j + 1];
            }
            entryCount--;
            printf("Entry on date %s has been deleted.\n", date);
            break;
        }
    }

    if (!found) {
        printf("No entry found for date: %s to delete.\n", date);
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                deleteEntry();
                break;
            case 5:
                printf("Exiting Digital Diary. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}