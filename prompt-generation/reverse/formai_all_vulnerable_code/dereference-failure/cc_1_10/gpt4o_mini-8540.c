//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11]; // YYYY-MM-DD format
    char text[MAX_LENGTH];
} DiaryEntry;

void get_current_date(char *date_str) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date_str, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

void add_entry(DiaryEntry *diary, int *entry_count) {
    if (*entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    char date[11];
    get_current_date(date);
    
    printf("Enter your diary entry: ");
    // Clear the input buffer
    fgetc(stdin); 
    fgets(diary[*entry_count].text, MAX_LENGTH, stdin);
    diary[*entry_count].text[strcspn(diary[*entry_count].text, "\n")] = 0; // Remove newline
    
    strcpy(diary[*entry_count].date, date);
    (*entry_count)++;
    
    printf("Entry added successfully on %s\n", date);
}

void display_entries(DiaryEntry *diary, int entry_count) {
    if (entry_count == 0) {
        printf("No diary entries found.\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        printf("[%d] %s\n%s\n", i + 1, diary[i].date, diary[i].text);
        printf("---------------------------------------------------\n");
    }
}

void save_to_file(DiaryEntry *diary, int entry_count) {
    FILE *file = fopen("diary_entries.txt", "w");
    if (file == NULL) {
        printf("Error saving diary entries to file.\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "%s\n%s\n", diary[i].date, diary[i].text);
        fprintf(file, "---------------------------------------------------\n");
    }

    fclose(file);
    printf("Diary entries saved to diary_entries.txt successfully.\n");
}

void load_from_file(DiaryEntry *diary, int *entry_count) {
    FILE *file = fopen("diary_entries.txt", "r");
    if (file == NULL) {
        printf("No previous diary entries found.\n");
        return;
    }

    while (fgets(diary[*entry_count].date, 11, file) != NULL) {
        diary[*entry_count].date[strcspn(diary[*entry_count].date, "\n")] = 0; // Remove newline
        fgets(diary[*entry_count].text, MAX_LENGTH, file);
        diary[*entry_count].text[strcspn(diary[*entry_count].text, "\n")] = 0; // Remove newline
        fgetc(file); // Skip the separator line
        (*entry_count)++;
    }

    fclose(file);
    printf("Diary entries loaded successfully. You have %d entries.\n", *entry_count);
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int entry_count = 0;
    int choice;

    load_from_file(diary, &entry_count);

    while (1) {
        printf("\n--- Digital Diary ---\n");
        printf("1. Add Entry\n");
        printf("2. Display All Entries\n");
        printf("3. Save Entries to File\n");
        printf("4. Load Entries from File\n");
        printf("5. Exit\n");
        printf("Select your option: ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(diary, &entry_count);
                break;
            case 2:
                display_entries(diary, entry_count);
                break;
            case 3:
                save_to_file(diary, entry_count);
                break;
            case 4:
                load_from_file(diary, &entry_count);
                break;
            case 5:
                save_to_file(diary, entry_count);
                printf("Exiting the diary. Bye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}