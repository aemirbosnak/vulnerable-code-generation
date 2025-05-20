//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256
#define FILENAME "diary.txt"

void welcome();
void addEntry();
void viewEntries();
void deleteEntry();
void timestamp(char *buffer);

int main() {
    int choice;
    welcome();
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add Diary Entry\n");
        printf("2. View Diary Entries\n");
        printf("3. Delete Diary Entry\n");
        printf("4. Exit\n");
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
                deleteEntry();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void welcome() {
    printf("Welcome to Your Digital Diary!\n");
    printf("Keep your thoughts and memories safe.\n");
}

void addEntry() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Unable to open diary file");
        return;
    }

    char entry[ENTRY_SIZE];
    char time_buffer[30];
    timestamp(time_buffer);

    printf("Write your diary entry (max %d characters):\n", ENTRY_SIZE - 1);
    fgets(entry, ENTRY_SIZE, stdin);

    // Remove new line if present
    entry[strcspn(entry, "\n")] = 0;
    
    fprintf(file, "[%s] %s\n", time_buffer, entry);
    fclose(file);
    printf("Diary entry added successfully!\n");
}

void viewEntries() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open diary file");
        return;
    }

    char line[ENTRY_SIZE + 30]; // Extra space for timestamp
    printf("Your Diary Entries:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void deleteEntry() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open diary file");
        return;
    }

    char tempFilename[] = "temp.txt";
    FILE *tempFile = fopen(tempFilename, "w");
    if (!tempFile) {
        perror("Unable to create temporary file");
        fclose(file);
        return;
    }

    char line[ENTRY_SIZE + 30];
    int count = 1, entryNum;
    
    printf("Current Diary Entries:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%d: %s", count, line);
        count++;
    }

    printf("Enter the entry number to delete: ");
    scanf("%d", &entryNum);
    getchar(); // Consume newline character

    rewind(file);
    count = 1;
    while (fgets(line, sizeof(line), file)) {
        if (count != entryNum) {
            fputs(line, tempFile);
        }
        count++;
    }

    fclose(file);
    fclose(tempFile);
    
    remove(FILENAME);
    rename(tempFilename, FILENAME);
    
    printf("Diary entry %d deleted successfully!\n", entryNum);
}

void timestamp(char *buffer) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(buffer, "%04d-%02d-%02d %02d:%02d:%02d", 
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
}