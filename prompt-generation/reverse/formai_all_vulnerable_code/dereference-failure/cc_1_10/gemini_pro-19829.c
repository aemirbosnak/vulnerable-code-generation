//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structure to represent a diary entry
typedef struct diary_entry {
    char *title;
    char *body;
    time_t timestamp;
} diary_entry;

// Function to create a new diary entry
diary_entry *create_diary_entry(char *title, char *body) {
    diary_entry *entry = (diary_entry *)malloc(sizeof(diary_entry));
    if (entry == NULL) {
        return NULL;
    }

    entry->title = strdup(title);
    entry->body = strdup(body);
    entry->timestamp = time(NULL);

    return entry;
}

// Function to free the memory allocated for a diary entry
void free_diary_entry(diary_entry *entry) {
    if (entry == NULL) {
        return;
    }

    free(entry->title);
    free(entry->body);
    free(entry);
}

// Function to add a diary entry to a file
int add_diary_entry_to_file(diary_entry *entry, FILE *fp) {
    if (entry == NULL || fp == NULL) {
        return -1;
    }

    fprintf(fp, "%s\n", entry->title);
    fprintf(fp, "%s\n", entry->body);
    fprintf(fp, "%ld\n", entry->timestamp);

    return 0;
}

// Function to read a diary entry from a file
diary_entry *read_diary_entry_from_file(FILE *fp) {
    if (fp == NULL) {
        return NULL;
    }

    char *title = NULL;
    size_t title_len = 0;
    getline(&title, &title_len, fp);

    char *body = NULL;
    size_t body_len = 0;
    getline(&body, &body_len, fp);

    long timestamp;
    fscanf(fp, "%ld", &timestamp);

    diary_entry *entry = create_diary_entry(title, body);
    entry->timestamp = timestamp;

    free(title);
    free(body);

    return entry;
}

// Function to print a diary entry
void print_diary_entry(diary_entry *entry) {
    if (entry == NULL) {
        return;
    }

    printf("Title: %s\n", entry->title);
    printf("Body: %s\n", entry->body);
    printf("Timestamp: %ld\n", entry->timestamp);
}

// Main function
int main() {
    // Open the diary file
    FILE *fp = fopen("diary.txt", "a+");
    if (fp == NULL) {
        perror("Error opening diary file");
        return EXIT_FAILURE;
    }

    // Get the user's input
    char title[100];
    char body[1000];
    printf("Enter the title of your diary entry: ");
    scanf("%s", title);
    printf("Enter the body of your diary entry: ");
    scanf(" %[^\n]", body);

    // Create a new diary entry
    diary_entry *entry = create_diary_entry(title, body);

    // Add the diary entry to the file
    int result = add_diary_entry_to_file(entry, fp);
    if (result != 0) {
        perror("Error adding diary entry to file");
        return EXIT_FAILURE;
    }

    // Close the diary file
    fclose(fp);

    // Print the diary entry
    print_diary_entry(entry);

    // Free the memory allocated for the diary entry
    free_diary_entry(entry);

    return EXIT_SUCCESS;
}