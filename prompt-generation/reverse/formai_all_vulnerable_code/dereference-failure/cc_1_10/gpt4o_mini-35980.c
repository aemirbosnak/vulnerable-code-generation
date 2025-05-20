//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define FILE_NAME "diary.txt"

typedef struct {
    char date[MAX_LENGTH];
    char entry[MAX_LENGTH * 2];
} DiaryEntry;

void addEntry();
void viewEntries();
void clearScreen();
void displayMenu();
void saveEntry(DiaryEntry entry);
void loadEntries();

DiaryEntry entries[MAX_ENTRIES];
int entryCount = 0;

int main() {
    int choice;
    
    loadEntries();
    
    while (1) {
        displayMenu();
        printf("Select an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // clear newline character from input buffer
        
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                clearScreen();
                break;
            case 4:
                printf("Exiting Diary. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    clearScreen();
    printf("=======================================\n");
    printf("          Retro Digital Diary          \n");
    printf("=======================================\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Clear Screen\n");
    printf("4. Exit\n");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full. Can't add new entries!\n");
        return;
    }
    
    DiaryEntry newEntry;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    sprintf(newEntry.date, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    
    printf("Enter your diary entry (max %d characters):\n", MAX_LENGTH * 2);
    fgets(newEntry.entry, MAX_LENGTH * 2, stdin);
    
    // Save entry to array and file
    entries[entryCount] = newEntry;
    saveEntry(newEntry);
    entryCount++;
    
    printf("Entry added successfully!\n");
    getchar(); // Pause to view message
}

void viewEntries() {
    clearScreen();
    printf("=======================================\n");
    printf("         Your Diary Entries           \n");
    printf("=======================================\n");
    
    if (entryCount == 0) {
        printf("No entries found.\n");
    } else {
        for (int i = 0; i < entryCount; i++) {
            printf("Date: %s\n", entries[i].date);
            printf("Entry: %s\n", entries[i].entry);
            printf("---------------------------------------\n");
        }
    }
    getchar(); // Pause to view entries
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear terminal screen
}

void saveEntry(DiaryEntry entry) {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Error opening diary file!\n");
        return;
    }
    fprintf(file, "Date: %s\n", entry.date);
    fprintf(file, "Entry: %s", entry.entry);
    fclose(file);
}

void loadEntries() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No diary file found. Starting fresh...\n");
        return;
    }
    
    while (fgets(entries[entryCount].date, MAX_LENGTH, file) != NULL && entryCount < MAX_ENTRIES) {
        strtok(entries[entryCount].date, "\n"); // Remove newline character
        fgets(entries[entryCount].entry, MAX_LENGTH * 2, file);
        entryCount++;
    }
    fclose(file);
}