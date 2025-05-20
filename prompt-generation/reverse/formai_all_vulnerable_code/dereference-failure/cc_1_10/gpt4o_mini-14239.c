//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char content[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry();
void viewEntries();
void writeToFile();
void readFromFile();
void displayMenu();
void currentDate(char* dateStr);

int main() {
    readFromFile(); // Load entries from file at the start
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                writeToFile();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please choose again!\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n=== Digital Diary Menu ===\n");
    printf("1. Add a new entry\n");
    printf("2. View all entries\n");
    printf("3. Save entries to file\n");
    printf("4. Exit\n");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    char date[11];
    char content[MAX_LENGTH];

    currentDate(date);
    printf("Date: %s\n", date);
    strcpy(diary[entryCount].date, date);
    
    printf("Write your diary entry (max %d characters):\n", MAX_LENGTH);
    fgets(content, MAX_LENGTH, stdin);
    content[strcspn(content, "\n")] = 0; // Remove newline character
    strcpy(diary[entryCount].content, content);

    entryCount++;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries found in your diary.\n");
        return;
    }

    printf("\n=== Your Diary Entries ===\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Date: %s\n", diary[i].date);
        printf("Content: %s\n", diary[i].content);
        printf("------------------------\n");
    }
}

void writeToFile() {
    FILE *file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "Entry %d:\n", i + 1);
        fprintf(file, "Date: %s\n", diary[i].date);
        fprintf(file, "Content: %s\n", diary[i].content);
        fprintf(file, "------------------------\n");
    }

    fclose(file);
    printf("Entries saved to diary.txt successfully!\n");
}

void readFromFile() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("No existing diary file found. Starting fresh!\n");
        return;
    }

    while (fgets(diary[entryCount].date, sizeof(diary[entryCount].date), file) != NULL) {
        diary[entryCount].date[strcspn(diary[entryCount].date, "\n")] = 0; // Remove newline character
        fgets(diary[entryCount].content, sizeof(diary[entryCount].content), file);
        diary[entryCount].content[strcspn(diary[entryCount].content, "\n")] = 0; // Remove newline character
        fgets(NULL, 0, file); // Reads the separator line
        entryCount++;
    }
    fclose(file);
    printf("Entries loaded from diary.txt successfully!\n");
}

void currentDate(char* dateStr) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(dateStr, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}