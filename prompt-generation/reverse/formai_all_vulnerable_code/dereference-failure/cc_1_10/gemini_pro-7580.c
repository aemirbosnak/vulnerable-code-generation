//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store a diary entry
typedef struct {
    char *title;
    char *body;
    time_t timestamp;
} DiaryEntry;

// Function to create a new diary entry
DiaryEntry *create_entry(char *title, char *body) {
    DiaryEntry *entry = malloc(sizeof(DiaryEntry));
    entry->title = strdup(title);
    entry->body = strdup(body);
    entry->timestamp = time(NULL);
    return entry;
}

// Function to get the date and time of a diary entry
char *get_timestamp(time_t timestamp) {
    char *buffer = malloc(26);
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", localtime(&timestamp));
    return buffer;
}

// Function to free the memory allocated for a diary entry
void free_entry(DiaryEntry *entry) {
    free(entry->title);
    free(entry->body);
    free(entry);
}

// Function to display the digital diary
void display_diary(DiaryEntry **entries, int num_entries) {
    printf("====================================================\n");
    printf("|                              Digital Diary                              |\n");
    printf("====================================================\n\n");

    for (int i = 0; i < num_entries; i++) {
        printf("----------------------------------------------------\n");
        printf("| Title: %s                                  |\n", entries[i]->title);
        printf("| Date and Time: %s                              |\n", get_timestamp(entries[i]->timestamp));
        printf("| Body: \n%s\n\n", entries[i]->body);
    }

    printf("----------------------------------------------------\n");
}

int main() {
    // Create a digital diary with some sample entries
    DiaryEntry *entries[] = {
        create_entry("My First Entry", "This is my first entry in my digital diary. I'm excited to use this to track my thoughts and experiences."),
        create_entry("A Day at the Park", "Today I went to the park with my friends. We had a lot of fun playing on the swings and slides."),
        create_entry("A Movie Night", "Last night I watched a movie with my family. It was a really good movie and we all enjoyed it."),
        create_entry("A New Beginning", "Today is a new day. I'm starting a new chapter in my life and I'm excited to see what the future holds.")
    };

    int num_entries = sizeof(entries) / sizeof(DiaryEntry *);

    // Display the digital diary
    display_diary(entries, num_entries);

    // Free the memory allocated for the diary entries
    for (int i = 0; i < num_entries; i++) {
        free_entry(entries[i]);
    }

    return 0;
}