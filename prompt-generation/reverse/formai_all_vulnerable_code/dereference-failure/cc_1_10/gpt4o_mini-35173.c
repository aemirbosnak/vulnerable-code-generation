//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define DIARY_FILE "diary.txt"

void add_entry();
void view_entries();
void delete_entry();
void clear_buffer();

int main() {
    int choice;

    do {
        printf("\n--- Digital Diary Menu ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        clear_buffer(); // clear the input buffer

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
                printf("Exiting the diary. Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void add_entry() {
    FILE *file = fopen(DIARY_FILE, "a");
    if (!file) {
        perror("Error opening diary file");
        return;
    }

    char entry[MAX_LENGTH];
    printf("Enter your diary entry (max 255 characters): ");
    fgets(entry, MAX_LENGTH, stdin);
    
    // Remove newline character if it exists
    entry[strcspn(entry, "\n")] = 0; 

    fprintf(file, "%s\n", entry);
    fclose(file);

    printf("Diary entry added successfully!\n");
}

void view_entries() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (!file) {
        perror("Error opening diary file");
        return;
    }

    char entry[MAX_LENGTH];
    printf("\n--- Diary Entries ---\n");
    while (fgets(entry, MAX_LENGTH, file)) {
        printf("%s", entry);
    }

    fclose(file);
}

void delete_entry() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (!file) {
        perror("Error opening diary file");
        return;
    }

    // Read all entries into a temporary array
    char *entries[MAX_ENTRIES];
    int count = 0;

    while (count < MAX_ENTRIES && !feof(file)) {
        entries[count] = malloc(MAX_LENGTH);
        if (fgets(entries[count], MAX_LENGTH, file)) {
            count++;
        }
    }

    fclose(file);

    if (count == 0) {
        printf("No entries to delete.\n");
        return;
    }

    printf("\n--- Current Diary Entries ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s", i + 1, entries[i]);
    }

    int entry_to_delete;
    printf("Enter the entry number you want to delete: ");
    scanf("%d", &entry_to_delete);
    clear_buffer(); // clear the input buffer

    if (entry_to_delete < 1 || entry_to_delete > count) {
        printf("Invalid entry number.\n");
    } else {
        // Remove the selected entry
        FILE *temp = fopen("temp.txt", "w");
        for (int i = 0; i < count; i++) {
            if (i != entry_to_delete - 1) {
                fprintf(temp, "%s", entries[i]);
            }
            free(entries[i]); // Free allocated memory
        }
        fclose(temp);
        remove(DIARY_FILE);
        rename("temp.txt", DIARY_FILE);
        printf("Diary entry %d deleted successfully!\n", entry_to_delete);
    }
}

void clear_buffer() {
    while (getchar() != '\n'); // Clear the input buffer
}