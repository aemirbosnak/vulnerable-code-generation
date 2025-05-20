//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define DATE_LENGTH 11
#define DIARY_ENTRY_LENGTH 256

typedef struct {
    char date[DATE_LENGTH];
    char entry[DIARY_ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    printf("Enter your diary entry (max %d characters):\n", DIARY_ENTRY_LENGTH - 1);
    fgets(diary[entry_count].entry, DIARY_ENTRY_LENGTH, stdin);

    // Get current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(diary[entry_count].date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    entry_count++;
    printf("Entry added successfully on %s\n", diary[entry_count - 1].date);
}

void view_entries() {
    if (entry_count == 0) {
        printf("No diary entries found.\n");
        return;
    }

    printf("Your Diary Entries:\n");
    for (int i = 0; i < entry_count; i++) {
        printf("Date: %s\nEntry: %s\n", diary[i].date, diary[i].entry);
        printf("-----------------------------\n");
    }
}

void delete_entry() {
    if (entry_count == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int index;
    printf("Enter the entry number to delete (1 to %d): ", entry_count);
    scanf("%d", &index);
    getchar();  // Consume newline after number input

    if (index < 1 || index > entry_count) {
        printf("Invalid entry number.\n");
        return;
    }

    for (int i = index - 1; i < entry_count - 1; i++) {
        diary[i] = diary[i + 1]; // Shift entries left
    }
    entry_count--;
    printf("Entry %d deleted successfully.\n", index);
}

void save_diary() {
    FILE *file = fopen("diary.txt", "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "Date: %s\nEntry: %s\n-----------------------------\n", diary[i].date, diary[i].entry);
    }
    fclose(file);
    printf("Diary saved successfully in diary.txt\n");
}

void load_diary() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("No previous diary entries found.\n");
        return;
    }
    
    while (fgets(diary[entry_count].date, DATE_LENGTH, file) != NULL && entry_count < MAX_ENTRIES) {
        // Read the entry
        fgets(diary[entry_count].entry, DIARY_ENTRY_LENGTH, file);
        fgets(NULL, DIARY_ENTRY_LENGTH, file); // consume the line separator
        entry_count++;
    }
    fclose(file);
    printf("Diary loaded successfully. You have %d entries.\n", entry_count);
}

void display_menu() {
    printf("\n*** Digital Diary Menu ***\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Save Diary\n");
    printf("5. Load Diary\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    load_diary();

    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                save_diary();
                break;
            case 5:
                load_diary();
                break;
            case 6:
                printf("Exiting diary application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}