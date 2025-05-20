//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11];  // Format: YYYY-MM-DD
    char content[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry(const char *content) {
    if (entryCount < MAX_ENTRIES) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        snprintf(diary[entryCount].date, sizeof(diary[entryCount].date), "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
        strncpy(diary[entryCount].content, content, MAX_LENGTH);
        entryCount++;
        printf("Entry added successfully!\n");
    } else {
        printf("Diary is full! Cannot add more entries.\n");
    }
}

void displayEntries() {
    if (entryCount == 0) {
        printf("No diary entries available.\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        printf("%s: %s\n", diary[i].date, diary[i].content);
    }
}

void saveDiaryToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s,%s\n", diary[i].date, diary[i].content);
    }
    fclose(file);
    printf("Diary saved to %s successfully!\n", filename);
}

void loadDiaryFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("No existing diary file found. Starting fresh.\n");
        return;
    }
    
    while (fscanf(file, "%10[^,],%255[^\n]\n", diary[entryCount].date, diary[entryCount].content) == 2) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) break;
    }
    fclose(file);
    printf("Diary loaded from %s successfully!\n", filename);
}

void clearDiary() {
    entryCount = 0;
    printf("Diary cleared successfully!\n");
}

void printMenu() {
    printf("\nDigital Diary Menu:\n");
    printf("1. Add Entry\n");
    printf("2. Display Entries\n");
    printf("3. Save Diary\n");
    printf("4. Load Diary\n");
    printf("5. Clear Diary\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char choice;
    char content[MAX_LENGTH];
    const char *filename = "diary.txt";
    
    loadDiaryFromFile(filename);
    
    while (1) {
        printMenu();
        choice = getchar();
        while (getchar() != '\n');  // Clear newline character from buffer

        switch (choice) {
            case '1':
                printf("Enter your diary entry: ");
                fgets(content, sizeof(content), stdin);
                content[strcspn(content, "\n")] = '\0';  // Remove the newline
                addEntry(content);
                break;
            case '2':
                displayEntries();
                break;
            case '3':
                saveDiaryToFile(filename);
                break;
            case '4':
                loadDiaryFromFile(filename);
                break;
            case '5':
                clearDiary();
                break;
            case '6':
                printf("Exiting the Diary Application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}