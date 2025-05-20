//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 512
#define DATE_LENGTH 20

typedef struct {
    char date[DATE_LENGTH];
    char entry[ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void logEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Can't add more entries.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("Enter your diary entry: ");
    getchar(); // to consume newline character from previous input
    fgets(diary[entryCount].entry, ENTRY_LENGTH, stdin);

    snprintf(diary[entryCount].date, DATE_LENGTH, "%02d-%02d-%04d",
             tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    printf("Entry logged on %s\n", diary[entryCount].date);
    entryCount++;
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No diary entries found.\n");
        return;
    }
    printf("\n----> Diary Entries <---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n", diary[i].entry);
        printf("-----------------------\n");
    }
}

void searchEntry() {
    if (entryCount == 0) {
        printf("No diary entries found to search.\n");
        return;
    }
    
    char searchTerm[ENTRY_LENGTH];
    printf("Enter a word/term to search for: ");
    getchar(); // to consume newline character from previous input
    fgets(searchTerm, ENTRY_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove trailing newline

    printf("\n----> Search Results for '%s' <---\n", searchTerm);
    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strstr(diary[i].entry, searchTerm)) {
            printf("Date: %s\n", diary[i].date);
            printf("Entry: %s\n", diary[i].entry);
            printf("-----------------------\n");
            found++;
        }
    }

    if (found == 0) {
        printf("No entries found containing '%s'.\n", searchTerm);
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No diary entries found to delete.\n");
        return;
    }

    int index;
    printf("Enter the entry index to delete (0 to %d): ", entryCount - 1);
    scanf("%d", &index);

    if (index < 0 || index >= entryCount) {
        printf("Invalid index. No entry deleted.\n");
        return;
    }

    for (int i = index; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entryCount--;
    printf("Entry deleted successfully.\n");
}

void mainMenu() {
    int choice;
    do {
        printf("\n--- Diary App Menu ---\n");
        printf("1. Log New Entry\n");
        printf("2. View All Entries\n");
        printf("3. Search Entry\n");
        printf("4. Delete Entry\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                logEntry();
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
                printf("Exiting the diary app. Take care!\n");
                break;
            default:
                printf("Invalid option! Please choose between 1-5.\n");
        }
    } while (choice != 5);
}

int main() {
    mainMenu();
    return 0;
}