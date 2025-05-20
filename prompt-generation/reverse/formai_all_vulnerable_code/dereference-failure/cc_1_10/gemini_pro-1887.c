//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store a diary entry
typedef struct diary_entry {
    char *title;
    char *content;
    time_t timestamp;
} diary_entry;

// Function to create a new diary entry
diary_entry *create_entry(char *title, char *content) {
    diary_entry *entry = malloc(sizeof(diary_entry));
    entry->title = strdup(title);
    entry->content = strdup(content);
    entry->timestamp = time(NULL);
    return entry;
}

// Function to free a diary entry
void free_entry(diary_entry *entry) {
    free(entry->title);
    free(entry->content);
    free(entry);
}

// Function to add a diary entry to a file
void add_entry_to_file(diary_entry *entry, FILE *file) {
    fprintf(file, "%s\n", entry->title);
    fprintf(file, "%s\n", entry->content);
    fprintf(file, "%ld\n", entry->timestamp);
}

// Function to read a diary entry from a file
diary_entry *read_entry_from_file(FILE *file) {
    char *title = NULL;
    char *content = NULL;
    time_t timestamp;
    size_t len;

    // Read the title
    getline(&title, &len, file);

    // Read the content
    getline(&content, &len, file);

    // Read the timestamp
    fscanf(file, "%ld", &timestamp);

    // Create a new diary entry
    diary_entry *entry = create_entry(title, content);
    entry->timestamp = timestamp;

    // Free the title and content strings
    free(title);
    free(content);

    return entry;
}

// Function to print a diary entry
void print_entry(diary_entry *entry) {
    printf("%s\n", entry->title);
    printf("%s\n", entry->content);
    printf("%ld\n", entry->timestamp);
}

// Function to get the current date and time
char *get_current_date_and_time() {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    char *date_and_time = malloc(30);
    strftime(date_and_time, 30, "%Y-%m-%d %H:%M:%S", tm);
    return date_and_time;
}

// Main function
int main() {
    // Create a new diary entry
    char *title = "My first diary entry";
    char *content = "This is my first diary entry. I'm so excited to start writing in a diary! I'm going to write about all the things that happen to me, both good and bad. I hope that this diary will help me to learn more about myself and to grow as a person.";
    diary_entry *entry = create_entry(title, content);

    // Open a file to write the diary entry to
    FILE *file = fopen("diary.txt", "a");

    // Add the diary entry to the file
    add_entry_to_file(entry, file);

    // Close the file
    fclose(file);

    // Print the diary entry
    printf("Current date and time: %s\n", get_current_date_and_time());
    print_entry(entry);

    // Free the diary entry
    free_entry(entry);

    return 0;
}