//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the structure of a diary entry
typedef struct {
    char date[11]; // Format: "YYYY-MM-DD"
    char time[6]; // Format: "HH:MM"
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

// Define the structure of the digital diary
typedef struct {
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries;
} DigitalDiary;

// Create a new digital diary
DigitalDiary* create_diary() {
    DigitalDiary* diary = malloc(sizeof(DigitalDiary));
    if (diary == NULL) {
        return NULL;
    }

    diary->num_entries = 0;

    return diary;
}

// Add a new entry to the digital diary
int add_entry(DigitalDiary* diary, const char* date, const char* time, const char* entry) {
    if (diary->num_entries >= MAX_ENTRIES) {
        return -1; // Error: diary is full
    }

    strcpy(diary->entries[diary->num_entries].date, date);
    strcpy(diary->entries[diary->num_entries].time, time);
    strcpy(diary->entries[diary->num_entries].entry, entry);
    diary->num_entries++;

    return 0; // Success
}

// Print the entries in the digital diary
void print_diary(DigitalDiary* diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        printf("%s %s\n", diary->entries[i].date, diary->entries[i].time);
        printf("%s\n\n", diary->entries[i].entry);
    }
}

// Free the memory allocated for the digital diary
void free_diary(DigitalDiary* diary) {
    free(diary);
}

int main() {
    // Create a new digital diary
    DigitalDiary* diary = create_diary();

    // Add some entries to the diary
    add_entry(diary, "2023-03-08", "10:00", "Dear diary,\n\nToday was a great day! I woke up feeling refreshed and energized, and I had a productive day at work. I also got to spend some time with my friends and family, which was really nice.\n\nI'm feeling really grateful for everything I have in my life. I'm so lucky to have such amazing people in my life, and I'm so happy to be able to share my life with them.");
    add_entry(diary, "2023-03-09", "15:00", "Dear diary,\n\nToday was a bit of a tough day. I had a lot of work to do, and I didn't get everything done that I wanted to. I also had a bit of a fight with my friend, which was really upsetting.\n\nBut I'm trying to stay positive. I know that things will get better, and I'm determined to make the best of every day.");
    add_entry(diary, "2023-03-10", "09:00", "Dear diary,\n\nToday is a new day, and I'm feeling refreshed and ready to take on whatever comes my way. I'm going to focus on the positive things in my life, and I'm going to try to make the most of every moment.\n\nI know that there will be challenges along the way, but I'm determined to overcome them. I'm going to keep my head up, and I'm going to keep moving forward.");

    // Print the entries in the diary
    print_diary(diary);

    // Free the memory allocated for the digital diary
    free_diary(diary);

    return 0;
}