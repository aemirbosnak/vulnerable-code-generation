//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char title[100];
    char content[1024];
    time_t timestamp;
} DiaryEntry;

// Function to create a new diary entry
DiaryEntry* createEntry(char* title, char* content) {
    DiaryEntry* entry = malloc(sizeof(DiaryEntry));
    strcpy(entry->title, title);
    strcpy(entry->content, content);
    entry->timestamp = time(NULL);
    return entry;
}

// Function to print a diary entry
void printEntry(DiaryEntry* entry) {
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
    printf("Timestamp: %s\n", ctime(&entry->timestamp));
}

// Function to add a new entry to the diary
void addEntry(DiaryEntry*** diary, int* entriesCount, DiaryEntry* entry) {
    *diary = realloc(*diary, sizeof(DiaryEntry*) * (*entriesCount + 1));
    (*diary)[*entriesCount] = entry;
    (*entriesCount)++;
}

// Function to get an entry from the diary by its index
DiaryEntry* getEntry(DiaryEntry** diary, int entriesCount, int index) {
    if (index < 0 || index >= entriesCount) {
        return NULL;
    }
    return diary[index];
}

// Function to delete an entry from the diary
void deleteEntry(DiaryEntry*** diary, int* entriesCount, int index) {
    if (index < 0 || index >= *entriesCount) {
        return;
    }
    free((*diary)[index]);
    for (int i = index; i < *entriesCount - 1; i++) {
        (*diary)[i] = (*diary)[i + 1];
    }
    (*diary) = realloc(*diary, sizeof(DiaryEntry*) * (*entriesCount - 1));
    (*entriesCount)--;
}

// Function to print all entries in the diary
void printAllEntries(DiaryEntry** diary, int entriesCount) {
    for (int i = 0; i < entriesCount; i++) {
        printEntry(diary[i]);
        printf("\n");
    }
}

int main() {
    // Create a new diary
    DiaryEntry** diary = NULL;
    int entriesCount = 0;

    // Add some entries to the diary
    addEntry(&diary, &entriesCount, createEntry("My First Entry", "This is my first entry in my digital diary."));
    addEntry(&diary, &entriesCount, createEntry("My Second Entry", "This is my second entry in my digital diary."));
    addEntry(&diary, &entriesCount, createEntry("My Third Entry", "This is my third entry in my digital diary."));

    // Print all entries in the diary
    printAllEntries(diary, entriesCount);

    // Get an entry from the diary by its index
    DiaryEntry* entry = getEntry(diary, entriesCount, 1);

    // Print the entry
    printEntry(entry);

    // Delete an entry from the diary
    deleteEntry(&diary, &entriesCount, 1);

    // Print all entries in the diary
    printAllEntries(diary, entriesCount);

    // Free the diary
    for (int i = 0; i < entriesCount; i++) {
        free(diary[i]);
    }
    free(diary);

    return 0;
}