//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a diary entry
typedef struct diary_entry {
    char *title;
    char *content;
    time_t timestamp;
} diary_entry_t;

// Function to create a new diary entry
diary_entry_t *new_diary_entry(char *title, char *content) {
    diary_entry_t *entry = malloc(sizeof(diary_entry_t));
    if (entry == NULL) {
        return NULL;
    }

    entry->title = strdup(title);
    entry->content = strdup(content);
    entry->timestamp = time(NULL);

    return entry;
}

// Function to free a diary entry
void free_diary_entry(diary_entry_t *entry) {
    if (entry == NULL) {
        return;
    }

    free(entry->title);
    free(entry->content);
    free(entry);
}

// Function to add a new diary entry to a file
int add_diary_entry(char *filename, diary_entry_t *entry) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        return -1;
    }

    fprintf(fp, "%s\n", entry->title);
    fprintf(fp, "%s\n", entry->content);
    fprintf(fp, "%ld\n", entry->timestamp);

    fclose(fp);

    return 0;
}

// Function to read a diary entry from a file
diary_entry_t *read_diary_entry(char *filename, int index) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Skip to the specified index
    for (int i = 0; i < index; i++) {
        while ((read = getline(&line, &len, fp)) != -1) {
            if (strlen(line) == 0) {
                break;
            }
        }
    }

    // Read the title
    getline(&line, &len, fp);
    char *title = strdup(line);

    // Read the content
    getline(&line, &len, fp);
    char *content = strdup(line);

    // Read the timestamp
    long timestamp;
    fscanf(fp, "%ld", &timestamp);

    // Create the diary entry
    diary_entry_t *entry = new_diary_entry(title, content);
    entry->timestamp = timestamp;

    // Free the line buffer
    free(line);

    // Close the file
    fclose(fp);

    return entry;
}

// Function to print a diary entry
void print_diary_entry(diary_entry_t *entry) {
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
    printf("Timestamp: %ld\n", entry->timestamp);
}

// Function to get the current date and time as a string
char *get_date_time() {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    char *date_time = malloc(100);
    strftime(date_time, 100, "%Y-%m-%d %H:%M:%S", tm);
    return date_time;
}

// Main function
int main() {
    // Create a new diary entry
    diary_entry_t *entry = new_diary_entry("My First Entry", "This is my first entry in my digital diary. I'm so excited to be able to track my thoughts and feelings in one place.");

    // Add the diary entry to a file
    int result = add_diary_entry("diary.txt", entry);
    if (result != 0) {
        printf("Error adding diary entry to file.\n");
        return 1;
    }

    // Read the diary entry from the file
    diary_entry_t *entry2 = read_diary_entry("diary.txt", 0);

    // Print the diary entry
    print_diary_entry(entry2);

    // Free the diary entry
    free_diary_entry(entry2);

    // Free the diary entry
    free_diary_entry(entry);

    return 0;
}