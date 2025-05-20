//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store a diary entry
typedef struct diary_entry {
    time_t timestamp;
    char *title;
    char *body;
} diary_entry;

// Function to create a new diary entry
diary_entry* create_diary_entry(char *title, char *body) {
    diary_entry *entry = malloc(sizeof(diary_entry));
    entry->timestamp = time(NULL);
    entry->title = strdup(title);
    entry->body = strdup(body);
    return entry;
}

// Function to read a diary entry from the file
diary_entry* read_diary_entry(FILE *fp) {
    diary_entry *entry = malloc(sizeof(diary_entry));
    fscanf(fp, "%ld\n", &entry->timestamp);
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, fp);
    entry->title = strdup(line);
    getline(&line, &len, fp);
    entry->body = strdup(line);
    return entry;
}

// Function to write a diary entry to the file
void write_diary_entry(FILE *fp, diary_entry *entry) {
    fprintf(fp, "%ld\n", entry->timestamp);
    fprintf(fp, "%s\n", entry->title);
    fprintf(fp, "%s\n", entry->body);
}

// Function to print a diary entry
void print_diary_entry(diary_entry *entry) {
    printf("Timestamp: %ld\n", entry->timestamp);
    printf("Title: %s\n", entry->title);
    printf("Body: %s\n", entry->body);
}

// Function to free the memory allocated to a diary entry
void free_diary_entry(diary_entry *entry) {
    free(entry->title);
    free(entry->body);
    free(entry);
}

// Main function
int main() {
    // Open the diary file
    FILE *fp = fopen("diary.txt", "a+");
    if (fp == NULL) {
        perror("Error opening the diary file");
        return EXIT_FAILURE;
    }

    // Get the user's input
    char title[100];
    char body[1000];
    printf("Enter the title of your entry: ");
    scanf("%s", title);
    printf("Enter the body of your entry: ");
    scanf("%s", body);

    // Create a new diary entry
    diary_entry *entry = create_diary_entry(title, body);

    // Write the diary entry to the file
    write_diary_entry(fp, entry);

    // Print the diary entry
    print_diary_entry(entry);

    // Free the memory allocated to the diary entry
    free_diary_entry(entry);

    // Close the diary file
    fclose(fp);

    return EXIT_SUCCESS;
}