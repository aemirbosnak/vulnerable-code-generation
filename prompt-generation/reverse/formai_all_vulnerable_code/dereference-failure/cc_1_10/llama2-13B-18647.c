//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Define brave variables
#define BRAVE_DIARY_MAX_ENTRIES 10
#define BRAVE_DIARY_ENTRY_LENGTH 256
#define BRAVE_DIARY_DAYS_TO_KEEP 7

// Structure to store diary entries
typedef struct {
    char day[10];  // Day of the week (e.g. "Monday")
    char entry[BRAVE_DIARY_ENTRY_LENGTH];  // Entry text
} brave_diary_entry_t;

// Array to store diary entries
brave_diary_entry_t diary[BRAVE_DIARY_MAX_ENTRIES];

// Function to add a new diary entry
void brave_diary_add_entry(char *day, char *entry) {
    int i = 0;
    for (i = 0; i < BRAVE_DIARY_MAX_ENTRIES; i++) {
        if (strcmp(diary[i].day, day) != 0) {
            break;
        }
    }
    if (i == BRAVE_DIARY_MAX_ENTRIES) {
        printf("BRAVE DIARY FULL! 😱\n");
        return;
    }
    strcpy(diary[i].day, day);
    strcpy(diary[i].entry, entry);
}

// Function to display today's diary entry
void brave_diary_display_today(void) {
    time_t now = time(NULL);
    struct tm today = *localtime(&now);
    char today_day[10];
    strftime(today_day, 10, "%A", &today);
    int i = 0;
    for (i = 0; i < BRAVE_DIARY_MAX_ENTRIES; i++) {
        if (strcmp(diary[i].day, today_day) == 0) {
            printf("%s: %s\n", today_day, diary[i].entry);
            break;
        }
    }
    if (i == BRAVE_DIARY_MAX_ENTRIES) {
        printf("NO DIARY ENTRIES FOR TODAY 😔\n");
    }
}

// Function to display all diary entries
void brave_diary_display_all(void) {
    int i = 0;
    for (i = 0; i < BRAVE_DIARY_MAX_ENTRIES; i++) {
        printf("%s: %s\n", diary[i].day, diary[i].entry);
    }
}

// Main function
int main(void) {
    setbuf(stdout, NULL);  // For brave output

    // Initialize diary array
    for (int i = 0; i < BRAVE_DIARY_MAX_ENTRIES; i++) {
        strcpy(diary[i].day, "");
        strcpy(diary[i].entry, "");
    }

    // Display today's diary entry
    brave_diary_display_today();

    // Display all diary entries
    brave_diary_display_all();

    return 0;
}