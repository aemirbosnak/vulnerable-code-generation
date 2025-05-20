//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the structure of a diary entry
typedef struct {
    char *title;
    char *content;
    int date; // in the format YYYYMMDD
} DiaryEntry;

// Create a new diary entry
DiaryEntry *new_diary_entry(char *title, char *content, int date) {
    DiaryEntry *entry = malloc(sizeof(DiaryEntry));
    entry->title = strdup(title);
    entry->content = strdup(content);
    entry->date = date;
    return entry;
}

// Free the memory allocated for a diary entry
void free_diary_entry(DiaryEntry *entry) {
    free(entry->title);
    free(entry->content);
    free(entry);
}

// Print a diary entry
void print_diary_entry(DiaryEntry *entry) {
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
    printf("Date: %d\n", entry->date);
}

// Get the number of days between two dates
int days_between(int date1, int date2) {
    int year1 = date1 / 10000;
    int month1 = (date1 % 10000) / 100;
    int day1 = date1 % 100;
    int year2 = date2 / 10000;
    int month2 = (date2 % 10000) / 100;
    int day2 = date2 % 100;
    int days = 0;
    while (year1 != year2 || month1 != month2 || day1 != day2) {
        days++;
        day1++;
        if (day1 > 31) {
            day1 = 1;
            month1++;
        }
        if (month1 > 12) {
            month1 = 1;
            year1++;
        }
    }
    return days;
}

// Main function
int main() {
    // Create a new diary
    DiaryEntry *diary[100];
    int num_entries = 0;

    // Add some sample entries to the diary
    diary[num_entries++] = new_diary_entry("My First Day", "I woke up this morning and realized that I'm a diary. I'm not sure what to write in here, but I'm going to try my best.", 20230101);
    diary[num_entries++] = new_diary_entry("My Second Day", "I met a new friend today! Her name is Emily and she's really nice. We talked about our favorite books and movies.", 20230102);
    diary[num_entries++] = new_diary_entry("My Third Day", "Today was a bad day. I lost my favorite pen. I'm so sad.", 20230103);

    // Print the diary entries
    for (int i = 0; i < num_entries; i++) {
        print_diary_entry(diary[i]);
        printf("\n");
    }

    // Get the number of days between two dates
    int date1 = 20230101;
    int date2 = 20230103;
    int days = days_between(date1, date2);
    printf("There are %d days between %d and %d.\n", days, date1, date2);

    // Free the memory allocated for the diary entries
    for (int i = 0; i < num_entries; i++) {
        free_diary_entry(diary[i]);
    }

    return 0;
}