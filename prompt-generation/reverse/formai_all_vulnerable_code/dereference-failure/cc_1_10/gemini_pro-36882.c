//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the maximum number of diary entries
#define MAX_ENTRIES 10

// Define the structure of a diary entry
typedef struct {
    char *text;
    int length;
} DiaryEntry;

// Define the structure of a digital diary
typedef struct {
    DiaryEntry entries[MAX_ENTRIES];
    int numEntries;
} DigitalDiary;

// Create a new digital diary
DigitalDiary *createDiary() {
    DigitalDiary *diary = malloc(sizeof(DigitalDiary));
    if (diary == NULL) {
        printf("Error: Could not allocate memory for diary.\n");
        return NULL;
    }

    diary->numEntries = 0;

    return diary;
}

// Add a new entry to the digital diary
void addEntry(DigitalDiary *diary, char *text) {
    if (diary->numEntries >= MAX_ENTRIES) {
        printf("Error: Diary is full.\n");
        return;
    }

    int length = strlen(text);
    if (length > MAX_ENTRY_LENGTH) {
        printf("Error: Entry is too long.\n");
        return;
    }

    DiaryEntry *entry = &diary->entries[diary->numEntries];
    entry->text = malloc(length + 1);
    if (entry->text == NULL) {
        printf("Error: Could not allocate memory for entry.\n");
        return;
    }

    strcpy(entry->text, text);
    entry->length = length;

    diary->numEntries++;
}

// Print the contents of the digital diary
void printDiary(DigitalDiary *diary) {
    for (int i = 0; i < diary->numEntries; i++) {
        DiaryEntry *entry = &diary->entries[i];
        printf("Entry %d:\n", i + 1);
        printf("%s\n", entry->text);
    }
}

// Free the memory allocated for the digital diary
void freeDiary(DigitalDiary *diary) {
    for (int i = 0; i < diary->numEntries; i++) {
        DiaryEntry *entry = &diary->entries[i];
        free(entry->text);
    }

    free(diary);
}

int main() {
    // Create a new digital diary
    DigitalDiary *diary = createDiary();

    // Add some entries to the digital diary
    addEntry(diary, "Dear Diary,\n"
                    "Today was a great day! I went to the park and played with my friends.");
    addEntry(diary, "Dear Diary,\n"
                    "Today was a bad day. I lost my favorite toy.");
    addEntry(diary, "Dear Diary,\n"
                    "Today was a weird day. I saw a flying cow.");

    // Print the contents of the digital diary
    printDiary(diary);

    // Free the memory allocated for the digital diary
    freeDiary(diary);

    return 0;
}