//FormAI DATASET v1.0 Category: Digital Diary ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_STRING_LENGTH 200

struct DiaryEntry {
    int day;
    int month;
    int year;
    char text[MAX_STRING_LENGTH];
};

struct Diary {
    struct DiaryEntry *entries[MAX_ENTRIES];
    int numEntries;
};

void printEntry(struct DiaryEntry *entry) {
    printf("%d/%d/%d: %s\n", entry->day, entry->month, entry->year, entry->text);
}

void printDiary(struct Diary *diary) {
    printf("Diary contains %d entries:\n", diary->numEntries);
    for(int i=0; i<diary->numEntries; i++) {
        printf("%d. ", i+1);
        printEntry(diary->entries[i]);
    }
}

void insertEntry(struct Diary *diary, struct DiaryEntry *entry) {
    // Make sure diary isn't full
    if(diary->numEntries == MAX_ENTRIES) {
        printf("Error: diary is full.\n");
        return;
    }
    
    // Find index to insert at (in sorted order)
    int index = diary->numEntries;
    for(int i=0; i<diary->numEntries; i++) {
        struct DiaryEntry *curr = diary->entries[i];
        if(entry->year < curr->year || (entry->year == curr->year && entry->month < curr->month) || 
           (entry->year == curr->year && entry->month == curr->month && entry->day < curr->day)) {
            index = i;
            break;
        }
    }
    
    // Shift all entries after index to make room for new entry
    for(int i=diary->numEntries; i>index; i--) {
        diary->entries[i] = diary->entries[i-1];
    }
    diary->entries[index] = entry;
    diary->numEntries++;
}

void addEntry(struct Diary *diary) {
    // Get user input
    struct DiaryEntry *entry = (struct DiaryEntry *) malloc(sizeof(struct DiaryEntry));
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &entry->day, &entry->month, &entry->year);
    printf("Enter text entry (max %d characters): ", MAX_STRING_LENGTH-1);
    scanf(" %[^\n]", entry->text);
    
    // Insert entry into diary
    insertEntry(diary, entry);
}

void removeEntry(struct Diary *diary, int index) {
    // Check if index is valid
    if(index < 0 || index >= diary->numEntries) {
        printf("Error: invalid index.\n");
        return;
    }
    
    // Free memory for entry and shift entries after index
    struct DiaryEntry *entry = diary->entries[index];
    free(entry);
    for(int i=index; i<diary->numEntries-1; i++) {
        diary->entries[i] = diary->entries[i+1];
    }
    diary->numEntries--;
}

void removeEntriesByYear(struct Diary *diary, int year) {
    // Remove all entries with matching year
    for(int i=diary->numEntries-1; i>=0; i--) {
        struct DiaryEntry *entry = diary->entries[i];
        if(entry->year == year) {
            removeEntry(diary, i);
        }
    }
}

void searchEntries(struct Diary *diary, char *query) {
    // Print all entries that contain query in text
    printf("Entries containing \"%s\":\n", query);
    int count = 0;
    for(int i=0; i<diary->numEntries; i++) {
        struct DiaryEntry *entry = diary->entries[i];
        if(strstr(entry->text, query) != NULL) {
            count++;
            printf("%d. ", count);
            printEntry(entry);
        }
    }
    if(count == 0) {
        printf("None found.\n");
    }
}

void saveDiary(struct Diary *diary, char *filename) {
    // Open file for writing
    FILE *file = fopen(filename, "wb");
    if(file == NULL) {
        printf("Error: could not open file.\n");
        return;
    }
    
    // Write number of entries
    fwrite(&diary->numEntries, sizeof(int), 1, file);
    
    // Write each entry
    for(int i=0; i<diary->numEntries; i++) {
        struct DiaryEntry *entry = diary->entries[i];
        fwrite(entry, sizeof(struct DiaryEntry), 1, file);
    }
    
    // Close file
    fclose(file);
    printf("Diary saved to %s.\n", filename);
}

void loadDiary(struct Diary *diary, char *filename) {
    // Open file for reading
    FILE *file = fopen(filename, "rb");
    if(file == NULL) {
        printf("Error: could not open file.\n");
        return;
    }
    
    // Read number of entries
    int numEntries;
    fread(&numEntries, sizeof(int), 1, file);
    
    // Read each entry and insert into diary
    for(int i=0; i<numEntries; i++) {
        struct DiaryEntry *entry = (struct DiaryEntry *) malloc(sizeof(struct DiaryEntry));
        fread(entry, sizeof(struct DiaryEntry), 1, file);
        insertEntry(diary, entry);
    }
    
    // Close file
    fclose(file);
    printf("Diary loaded from %s.\n", filename);
}

void printMenu() {
    printf("Menu:\n");
    printf("1. Add entry\n");
    printf("2. Remove entry\n");
    printf("3. Remove entries by year\n");
    printf("4. Search entries\n");
    printf("5. Save diary\n");
    printf("6. Load diary\n");
    printf("7. Exit\n");
    printf("Enter choice: ");
}

int main() {
    struct Diary diary;
    diary.numEntries = 0;
    
    // Seed random number generator
    srand(time(NULL));
    
    while(1) {
        printMenu();
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addEntry(&diary);
                break;
            case 2:
                printf("Enter index to remove: ");
                int index;
                scanf("%d", &index);
                removeEntry(&diary, index-1);
                break;
            case 3:
                printf("Enter year to remove: ");
                int year;
                scanf("%d", &year);
                removeEntriesByYear(&diary, year);
                break;
            case 4:
                printf("Enter query string: ");
                char query[MAX_STRING_LENGTH];
                scanf(" %[^\n]", query);
                searchEntries(&diary, query);
                break;
            case 5:
                printf("Enter filename to save to: ");
                char saveFilename[MAX_STRING_LENGTH];
                scanf(" %[^\n]", saveFilename);
                saveDiary(&diary, saveFilename);
                break;
            case 6:
                printf("Enter filename to load from: ");
                char loadFilename[MAX_STRING_LENGTH];
                scanf(" %[^\n]", loadFilename);
                loadDiary(&diary, loadFilename);
                break;
            case 7:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Error: invalid choice. Try again.\n");
                break;
        }
        
        printf("\n");
        printDiary(&diary);
        printf("\n");
    }
}