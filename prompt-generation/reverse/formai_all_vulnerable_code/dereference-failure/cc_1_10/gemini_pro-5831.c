//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *title;
    char *entry;
    time_t timestamp;
} DiaryEntry;

int main() {
    // Initialize the digital diary
    DiaryEntry *diary = NULL;
    int num_entries = 0;

    // Loop to add diary entries
    while (1) {
        // Get the title of the entry
        char title[100];
        printf("Enter the title of your entry (or q to quit): ");
        scanf("%s", title);

        // Check if the user wants to quit
        if (strcmp(title, "q") == 0) {
            break;
        }

        // Get the entry text
        char entry[1000];
        printf("Enter your entry: ");
        scanf(" %[^\n]%*c", entry);  // Read until newline

        // Create a new diary entry
        DiaryEntry *new_entry = malloc(sizeof(DiaryEntry));
        new_entry->title = strdup(title);
        new_entry->entry = strdup(entry);
        new_entry->timestamp = time(NULL);

        // Add the new entry to the diary
        diary = realloc(diary, (num_entries + 1) * sizeof(DiaryEntry));
        diary[num_entries++] = *new_entry;
    }

    // Print out the diary entries
    printf("\nYour digital diary:\n\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n", diary[i].title);
        printf("%s\n", diary[i].entry);
        printf("Timestamp: %s\n\n", ctime(&diary[i].timestamp));
    }

    // Free the memory allocated for the diary entries
    for (int i = 0; i < num_entries; i++) {
        free(diary[i].title);
        free(diary[i].entry);
    }
    free(diary);

    return 0;
}