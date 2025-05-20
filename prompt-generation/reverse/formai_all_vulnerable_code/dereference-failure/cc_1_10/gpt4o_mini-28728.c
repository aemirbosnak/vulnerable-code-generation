//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_TITLE_LENGTH 50
#define MAX_CONTENT_LENGTH 500
#define DATE_FORMAT_LENGTH 20

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    char date[DATE_FORMAT_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void get_current_date(char* date) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Can't add more entries.\n");
        return;
    }

    char date[DATE_FORMAT_LENGTH];
    get_current_date(date);

    printf("Enter title: ");
    fgets(diary[entry_count].title, MAX_TITLE_LENGTH, stdin);
    diary[entry_count].title[strcspn(diary[entry_count].title, "\n")] = 0; // Remove newline

    printf("Enter content (max %d characters):\n", MAX_CONTENT_LENGTH);
    fgets(diary[entry_count].content, MAX_CONTENT_LENGTH, stdin);
    diary[entry_count].content[strcspn(diary[entry_count].content, "\n")] = 0; // Remove newline

    strcpy(diary[entry_count].date, date);
    entry_count++;
    printf("Entry added successfully!\n");
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries found in the diary.\n");
        return;
    }

    printf("\nYour Diary Entries:\n");
    for (int i = 0; i < entry_count; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Title: %s\n", diary[i].title);
        printf("Content: %s\n", diary[i].content);
        printf("Date: %s\n", diary[i].date);
        printf("-------------------------\n");
    }
}

void delete_entry() {
    if (entry_count == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int entry_number;
    printf("Enter the entry number to delete (1-%d): ", entry_count);
    scanf("%d", &entry_number);
    getchar(); // Consume newline character left by scanf

    if (entry_number < 1 || entry_number > entry_count) {
        printf("Invalid entry number.\n");
        return;
    }

    for (int i = entry_number - 1; i < entry_count - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entry_count--;
    printf("Entry deleted successfully!\n");
}

void save_entries() {
    FILE *file = fopen("diary_entries.txt", "w");
    if (file == NULL) {
        printf("Unable to open file for saving.\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "Title: %s\n", diary[i].title);
        fprintf(file, "Content: %s\n", diary[i].content);
        fprintf(file, "Date: %s\n", diary[i].date);
        fprintf(file, "-------------------------\n");
    }

    fclose(file);
    printf("Entries saved to diary_entries.txt.\n");
}

void load_entries() {
    FILE *file = fopen("diary_entries.txt", "r");
    if (file == NULL) {
        printf("No previous entries found.\n");
        return;
    }

    while (fgets(diary[entry_count].title, MAX_TITLE_LENGTH, file) != NULL) {
        diary[entry_count].title[strcspn(diary[entry_count].title, "\n")] = 0; // Remove newline
        fgets(diary[entry_count].content, MAX_CONTENT_LENGTH, file);
        diary[entry_count].content[strcspn(diary[entry_count].content, "\n")] = 0; // Remove newline
        fgets(diary[entry_count].date, DATE_FORMAT_LENGTH, file);
        diary[entry_count].date[strcspn(diary[entry_count].date, "\n")] = 0; // Remove newline
        entry_count++;
    }
    fclose(file);
    printf("Entries loaded successfully.\n");
}

int main() {
    int choice;

    load_entries();

    while (1) {
        printf("\nDigital Diary Menu:\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Save Entries\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

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
                save_entries();
                break;
            case 5:
                printf("Exiting the diary. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}