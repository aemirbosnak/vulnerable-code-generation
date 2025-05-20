//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11];  // Format YYYY-MM-DD
    char content[MAX_LENGTH];
} DiaryEntry;

void addEntry(DiaryEntry *diary, int *totalEntries) {
    if (*totalEntries >= MAX_ENTRIES) {
        printf("Diary is full! Can't add more entries.\n");
        return;
    }

    DiaryEntry newEntry;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(newEntry.date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    printf("Enter your diary entry (max %d characters):\n", MAX_LENGTH - 1);
    getchar(); // Consume leftover newline character
    fgets(newEntry.content, MAX_LENGTH, stdin);
    newEntry.content[strcspn(newEntry.content, "\n")] = 0; // Remove newline character

    diary[*totalEntries] = newEntry;
    (*totalEntries)++;
    printf("Entry saved for %s!\n\n", newEntry.date);
}

void viewEntries(DiaryEntry *diary, int totalEntries) {
    if (totalEntries == 0) {
        printf("No entries found!\n\n");
        return;
    }

    for (int i = 0; i < totalEntries; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n\n", diary[i].content);
    }
}

void searchEntry(DiaryEntry *diary, int totalEntries) {
    if (totalEntries == 0) {
        printf("No entries to search through!\n\n");
        return;
    }

    char searchDate[11];
    printf("Enter the date to search (YYYY-MM-DD): ");
    scanf("%10s", searchDate);

    int found = 0;
    for (int i = 0; i < totalEntries; i++) {
        if (strcmp(diary[i].date, searchDate) == 0) {
            found = 1;
            printf("Found entry for %s: %s\n\n", diary[i].date, diary[i].content);
            break;
        }
    }
    if (!found) {
        printf("No entries found for %s!\n\n", searchDate);
    }
}

void deleteEntry(DiaryEntry *diary, int *totalEntries) {
    if (*totalEntries == 0) {
        printf("No entries to delete!\n\n");
        return;
    }

    char deleteDate[11];
    printf("Enter the date to delete the entry (YYYY-MM-DD): ");
    scanf("%10s", deleteDate);

    int found = 0;
    for (int i = 0; i < *totalEntries; i++) {
        if (strcmp(diary[i].date, deleteDate) == 0) {
            found = 1;
            for (int j = i; j < *totalEntries - 1; j++) {
                diary[j] = diary[j + 1];
            }
            (*totalEntries)--;
            printf("Entry for %s deleted!\n\n", deleteDate);
            break;
        }
    }
    if (!found) {
        printf("No entries found for %s to delete!\n\n", deleteDate);
    }
}

void displayMenu() {
    printf("===== Welcome to Your Digital Diary! =====\n");
    printf("1. Add Diary Entry\n");
    printf("2. View All Entries\n");
    printf("3. Search Entry by Date\n");
    printf("4. Delete Entry\n");
    printf("5. Exit\n");
    printf("===========================================\n");
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int totalEntries = 0;
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(diary, &totalEntries);
                break;
            case 2:
                viewEntries(diary, totalEntries);
                break;
            case 3:
                searchEntry(diary, totalEntries);
                break;
            case 4:
                deleteEntry(diary, &totalEntries);
                break;
            case 5:
                printf("Thank you for using the Digital Diary! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose a valid option.\n\n");
        }
    } while (choice != 5);

    return 0;
}