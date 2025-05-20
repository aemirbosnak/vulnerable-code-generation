//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256

typedef struct {
    char date[11]; // "YYYY-MM-DD"
    char entry[ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry();
void viewEntries();
void deleteEntry();
void displayMenu();
void clearEntries();
void sortEntries();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                clearEntries();
                break;
            case 5:
                sortEntries();
                break;
            case 6:
                printf("Exiting the diary program... Thank you for sharing your thoughts! 😲\n");
                exit(0);
            default:
                printf("Whoa! That's not a valid option! Try again! 😱\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n========= Digital Diary =========\n");
    printf("1. Add a new entry\n");
    printf("2. View all entries\n");
    printf("3. Delete an entry\n");
    printf("4. Clear all entries\n");
    printf("5. Sort entries by date\n");
    printf("6. Exit\n");
    printf("=================================\n");
}

void addEntry() {
    if (entryCount < MAX_ENTRIES) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        sprintf(diary[entryCount].date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

        printf("Enter your diary entry: ");
        fgets(diary[entryCount].entry, ENTRY_LENGTH, stdin);
        diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = 0; // Remove newline

        printf("Entry added on %s! Wow! 🥳\n", diary[entryCount].date);
        entryCount++;
    } else {
        printf("Oh no! The diary is full! Can't add more entries! 😱\n");
    }
}

void viewEntries() {
    printf("\n=== Your Diary Entries ===\n");
    if (entryCount == 0) {
        printf("No entries found! Fill your diary with thoughts! 📖\n");
    } else {
        for (int i = 0; i < entryCount; i++) {
            printf("[%d] - %s: %s\n", i + 1, diary[i].date, diary[i].entry);
        }
    }
}

void deleteEntry() {
    int entryNumber;
    printf("Enter entry number to delete: ");
    scanf("%d", &entryNumber);
    getchar(); // Consume the newline character

    if (entryNumber < 1 || entryNumber > entryCount) {
        printf("Error! You have entered an invalid entry number! 😳\n");
        return;
    }

    for (int i = entryNumber - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1]; // Shift entries left
    }
    entryCount--;
    printf("Entry %d deleted! What a bummer! 😞\n", entryNumber);
}

void clearEntries() {
    entryCount = 0;
    printf("All entries have been cleared! The slate is clean! 💥\n");
}

void sortEntries() {
    if (entryCount < 2) {
        printf("Nothing to sort! Your diary is either empty or has just one entry! 🤷‍♀️\n");
        return;
    }

    for (int i = 0; i < entryCount - 1; i++) {
        for (int j = i + 1; j < entryCount; j++) {
            if (strcmp(diary[i].date, diary[j].date) > 0) {
                DiaryEntry temp = diary[i];
                diary[i] = diary[j];
                diary[j] = temp;
            }
        }
    }

    printf("Entries sorted by date! How orderly! 🎉\n");
}