//FormAI DATASET v1.0 Category: Digital Diary ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Representation of a diary entry
struct DiaryEntry {
    int year;
    int month;
    int day;
    char entry[2000];
};

// Function to create a new diary entry
struct DiaryEntry *createEntry(int year, int month, int day, char entry[]) {
    struct DiaryEntry *newEntry = (struct DiaryEntry*) malloc(sizeof(struct DiaryEntry));
    newEntry->year = year;
    newEntry->month = month;
    newEntry->day = day;
    strcpy(newEntry->entry, entry);
    return newEntry;
}

// Function to add a new diary entry to the diary
void addEntry(struct DiaryEntry **diary, int *numEntries, struct DiaryEntry *newEntry) {
    *numEntries += 1;
    *diary = (struct DiaryEntry*) realloc(*diary, (*numEntries) * sizeof(struct DiaryEntry));
    (*diary)[*numEntries-1] = *newEntry;
}

// Function to print the diary entries for a given day
void printEntries(struct DiaryEntry *diary, int numEntries, int year, int month, int day) {
    printf("Diary entries for %d-%d-%d:\n", year, month, day);
    for(int i = 0; i < numEntries; i++) {
        if(diary[i].year == year && diary[i].month == month && diary[i].day == day) {
            printf("%s\n", diary[i].entry);
        }
    }
}

// Main function
int main() {
    int numEntries = 0;
    struct DiaryEntry *diary = NULL;

    // Sample diary entries
    struct DiaryEntry *entry1 = createEntry(2022, 4, 19, "Today I started learning C programming!");
    addEntry(&diary, &numEntries, entry1);

    struct DiaryEntry *entry2 = createEntry(2022, 4, 20, "Today I practiced pointers and dynamic memory allocation.");
    addEntry(&diary, &numEntries, entry2);

    struct DiaryEntry *entry3 = createEntry(2022, 4, 20, "I also learned about structures and how to create my own data types.");
    addEntry(&diary, &numEntries, entry3);

    // Print all diary entries
    for(int i = 0; i < numEntries; i++) {
        printf("%d-%d-%d:%s\n", diary[i].year, diary[i].month, diary[i].day, diary[i].entry);
    }

    // Print entries for a specific day
    printEntries(diary, numEntries, 2022, 4, 20);

    // Free allocated memory
    free(diary);
    
    return 0;
}