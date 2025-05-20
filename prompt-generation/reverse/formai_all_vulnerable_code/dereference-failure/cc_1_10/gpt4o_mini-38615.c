//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 500
#define DIARY_FILE "diary_entries.txt"

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void add_entry();
void view_entries();
void save_entries_to_file();
void load_entries_from_file();
void display_menu();

int main() {
    load_entries_from_file();
    int choice;

    do {
        display_menu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character after entering the choice

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                save_entries_to_file();
                break;
            case 4:
                printf("Exiting the diary. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

void display_menu() {
    printf("\n=== Digital Diary ===\n");
    printf("1. Add a new entry\n");
    printf("2. View all entries\n");
    printf("3. Save entries to file\n");
    printf("4. Exit\n");
}

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    printf("Enter the title of your entry: ");
    fgets(diary[entry_count].title, MAX_TITLE_LENGTH, stdin);
    diary[entry_count].title[strcspn(diary[entry_count].title, "\n")] = 0; // Trim newline

    printf("Enter the content of your entry:\n");
    fgets(diary[entry_count].content, MAX_CONTENT_LENGTH, stdin);
    diary[entry_count].content[strcspn(diary[entry_count].content, "\n")] = 0; // Trim newline

    entry_count++;
    printf("Entry added successfully!\n");
}

void view_entries() {
    if (entry_count == 0) {
        printf("No diary entries found.\n");
        return;
    }

    printf("\n=== Diary Entries ===\n");
    for (int i = 0; i < entry_count; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Title: %s\n", diary[i].title);
        printf("Content: %s\n", diary[i].content);
        printf("---------------------\n");
    }
}

void save_entries_to_file() {
    FILE *file = fopen(DIARY_FILE, "w");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "Entry %d:\n", i + 1);
        fprintf(file, "Title: %s\n", diary[i].title);
        fprintf(file, "Content: %s\n", diary[i].content);
        fprintf(file, "---------------------\n");
    }

    fclose(file);
    printf("Diary entries saved to %s successfully!\n", DIARY_FILE);
}

void load_entries_from_file() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (file == NULL) {
        printf("No previous diary entries found. Starting fresh.\n");
        return;
    }

    while (fgets(diary[entry_count].title, MAX_TITLE_LENGTH, file) != NULL) {
        diary[entry_count].title[strcspn(diary[entry_count].title, "\n")] = 0; // Trim newline
        fgets(diary[entry_count].content, MAX_CONTENT_LENGTH, file);
        diary[entry_count].content[strcspn(diary[entry_count].content, "\n")] = 0; // Trim newline
        fgets(NULL, 100, file); // To consume the separator line
        entry_count++;
        if (entry_count >= MAX_ENTRIES) break;
    }

    fclose(file);
    printf("Diary entries loaded successfully! Total entries: %d\n", entry_count);
}