//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 512
#define FILENAME "diary.txt"

typedef struct {
    char date[11]; // format: YYYY-MM-DD
    char entry[ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int diary_count = 0;

// Function declarations
void display_menu();
void add_entry();
void view_entries();
void save_entries();
void load_entries();
void print_entry(DiaryEntry entry);
void clear_buffer();

int main() {
    load_entries();
    int choice;

    do {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        clear_buffer(); // clear newline from buffer

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                save_entries();
                printf("Entries saved successfully!\n");
                break;
            case 4:
                printf("Exiting the diary. Happy journaling!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void display_menu() {
    printf("\n--- My Digital Diary ---\n");
    printf("1. Add a Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Save Diary Entries\n");
    printf("4. Exit\n");
}

void add_entry() {
    if (diary_count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    time_t now = time(0);
    struct tm *t = localtime(&now);
    sprintf(diary[diary_count].date, "%04d-%02d-%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);

    printf("Writing your entry for %s\n", diary[diary_count].date);
    printf("Please compose your diary entry (max %d characters): ", ENTRY_LENGTH - 1);
    fgets(diary[diary_count].entry, ENTRY_LENGTH, stdin);
    diary[diary_count].entry[strcspn(diary[diary_count].entry, "\n")] = 0; // remove newline

    diary_count++;
    printf("Your entry has been saved!\n");
}

void view_entries() {
    if (diary_count == 0) {
        printf("Your diary is empty. Write something!\n");
        return;
    }
  
    printf("\n--- Your Diary Entries ---\n");
    for (int i = 0; i < diary_count; i++) {
        print_entry(diary[i]);
    }
}

void print_entry(DiaryEntry entry) {
    printf("Date: %s\n", entry.date);
    printf("Entry: %s\n", entry.entry);
    printf("-------------------------------\n");
}

void save_entries() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file to save entries.\n");
        return;
    }

    for (int i = 0; i < diary_count; i++) {
        fprintf(file, "%s\n%s\n", diary[i].date, diary[i].entry);
    }

    fclose(file);
}

void load_entries() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No previous entries found. Starting new diary.\n");
        return;
    }

    while (fscanf(file, "%10s\n%511[^\n]\n", diary[diary_count].date, diary[diary_count].entry) == 2) {
        diary_count++;
        if (diary_count >= MAX_ENTRIES) {
            break;
        }
    }

    fclose(file);
}

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}