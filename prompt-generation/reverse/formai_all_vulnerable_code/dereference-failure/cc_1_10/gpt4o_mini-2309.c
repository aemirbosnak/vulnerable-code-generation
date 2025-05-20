//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct Entry {
    char date[20];
    char content[MAX_LENGTH];
} Entry;

Entry diary[MAX_ENTRIES];
int current_entries = 0;

void addEntry();
void viewEntries();
void deleteEntry();
void saveDiary();
void loadDiary();
void displayMenu();

int main() {
    loadDiary();
    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        getchar(); // consume newline
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
                saveDiary();
                break;
            case 5:
                printf("Exiting the diary. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n==== Digital Diary Menu ====\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Save Diary\n");
    printf("5. Exit\n");
}

void addEntry() {
    if (current_entries >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add more entries.\n");
        return;
    }
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(diary[current_entries].date, sizeof(diary[current_entries].date), 
             "%04d-%02d-%02d %02d:%02d:%02d", 
             tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, 
             tm.tm_hour, tm.tm_min, tm.tm_sec);

    printf("Enter your diary entry: ");
    fgets(diary[current_entries].content, MAX_LENGTH, stdin);
    diary[current_entries].content[strcspn(diary[current_entries].content, "\n")] = 0; // Remove newline
    
    current_entries++;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (current_entries == 0) {
        printf("No entries found.\n");
        return;
    }
    
    printf("\n==== Diary Entries ====\n");
    for (int i = 0; i < current_entries; i++) {
        printf("%d. [%s] %s\n", i + 1, diary[i].date, diary[i].content);
    }
}

void deleteEntry() {
    if (current_entries == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int entry_number;
    printf("Enter entry number to delete: ");
    scanf("%d", &entry_number);
    getchar(); // consume newline

    if (entry_number < 1 || entry_number > current_entries) {
        printf("Invalid entry number.\n");
        return;
    }

    for (int i = entry_number - 1; i < current_entries - 1; i++) {
        diary[i] = diary[i + 1]; // Shift entries to fill the gap
    }
    current_entries--;
    printf("Entry deleted successfully!\n");
}

void saveDiary() {
    FILE *file = fopen("diary.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < current_entries; i++) {
        fprintf(file, "%s\n%s\n", diary[i].date, diary[i].content);
    }
    fclose(file);
    printf("Diary saved successfully!\n");
}

void loadDiary() {
    FILE *file = fopen("diary.txt", "r");
    if (!file) {
        printf("No existing diary found. Starting a new one.\n");
        return;
    }

    while (fgets(diary[current_entries].date, sizeof(diary[current_entries].date), file) && 
           fgets(diary[current_entries].content, sizeof(diary[current_entries].content), file)) {
        diary[current_entries].date[strcspn(diary[current_entries].date, "\n")] = 0; // Remove newline
        diary[current_entries].content[strcspn(diary[current_entries].content, "\n")] = 0; // Remove newline
        current_entries++;
        if (current_entries >= MAX_ENTRIES) break; // Limiting entries
    }
    fclose(file);
    printf("Diary loaded successfully with %d entry(ies).\n", current_entries);
}