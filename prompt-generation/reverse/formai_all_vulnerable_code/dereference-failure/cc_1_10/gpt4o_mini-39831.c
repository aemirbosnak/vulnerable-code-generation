//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define FILE_NAME "diary.txt"

typedef struct {
    char date[MAX_LENGTH];
    char entry[MAX_LENGTH];
} DiaryEntry;

void writeEntryToFile(DiaryEntry entry) {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Unable to open diary file.\n");
        return;
    }
    fprintf(file, "%s\n%s\n", entry.date, entry.entry);
    fclose(file);
}

void displayEntries() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No diary entries found.\n");
        return;
    }

    char buffer[MAX_LENGTH * 2];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("Date: %s", buffer);
        fgets(buffer, sizeof(buffer), file);
        printf("Entry: %s\n", buffer);
    }
    fclose(file);
}

void deleteDiaryEntries() {
    if (remove(FILE_NAME) == 0) {
        printf("All diary entries deleted successfully.\n");
    } else {
        printf("Error deleting diary entries.\n");
    }
}

void getCurrentDate(char *dateBuffer) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(dateBuffer, MAX_LENGTH, "%02d-%02d-%d %02d:%02d:%02d", 
             tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, 
             tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void addEntry() {
    DiaryEntry entry;
    char date[MAX_LENGTH];

    getCurrentDate(date);
    strcpy(entry.date, date);
    printf("Enter your diary entry: ");
    fgets(entry.entry, sizeof(entry.entry), stdin);
    entry.entry[strcspn(entry.entry, "\n")] = 0; // Remove newline character

    writeEntryToFile(entry);
    printf("Diary entry added successfully for date: %s\n", date);
}

void displayMenu() {
    printf("\n=== Digital Diary ===\n");
    printf("1. Add Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Delete All Diary Entries\n");
    printf("4. Exit\n");
    printf("=====================\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // consume the newline character left by scanf

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                displayEntries();
                break;
            case 3:
                deleteDiaryEntries();
                break;
            case 4:
                printf("Exiting the diary. Bye!\n");
                exit(0);
            default:
                printf("Invalid choice, please select again.\n");
                break;
        }
    }
    
    return 0;
}