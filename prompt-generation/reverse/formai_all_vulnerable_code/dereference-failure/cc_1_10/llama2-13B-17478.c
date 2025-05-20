//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

struct entry {
    int date;
    int hour;
    int mood;
    char description[MAX_LENGTH];
};

struct statistics {
    int happy_count;
    int sad_count;
    int neutral_count;
    int total_count;
};

int main() {
    struct statistics stats;
    struct entry current_entry;

    // Initialize statistics
    stats.happy_count = 0;
    stats.sad_count = 0;
    stats.neutral_count = 0;
    stats.total_count = 0;

    // Get current date and time
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    current_entry.date = current_time->tm_mday;
    current_entry.hour = current_time->tm_hour;

    // Read user input
    char description[MAX_LENGTH];
    printf("What's your mood today? (H/S/N): ");
    fgets(description, MAX_LENGTH, stdin);
    current_entry.mood = strtol(description, NULL, 10);

    // Update statistics
    switch (current_entry.mood) {
        case 1:
            stats.happy_count++;
            break;
        case 2:
            stats.sad_count++;
            break;
        default:
            stats.neutral_count++;
            break;
    }

    // Display statistics
    printf("Statistics:\n");
    printf("  Happy: %d (%.2f%%)\n", stats.happy_count,
           (float)stats.happy_count / (float)stats.total_count * 100);
    printf("  Sad: %d (%.2f%%)\n", stats.sad_count,
           (float)stats.sad_count / (float)stats.total_count * 100);
    printf("  Neutral: %d (%.2f%%)\n", stats.neutral_count,
           (float)stats.neutral_count / (float)stats.total_count * 100);

    // Save entry to file
    FILE *file = fopen("digital_diary.txt", "a");
    fprintf(file, "%d-%d-%d %d:%d %c\n", current_entry.date, current_entry.hour,
             current_entry.mood, current_entry.description);
    fclose(file);

    return 0;
}