//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store a diary entry
struct diary_entry {
    time_t timestamp;
    char *text;
};

// Function to create a new diary entry
struct diary_entry *new_diary_entry(char *text) {
    struct diary_entry *entry = malloc(sizeof(struct diary_entry));
    entry->timestamp = time(NULL);
    entry->text = strdup(text);
    return entry;
}

// Function to free a diary entry
void free_diary_entry(struct diary_entry *entry) {
    free(entry->text);
    free(entry);
}

// Function to print a diary entry
void print_diary_entry(struct diary_entry *entry) {
    printf("--------------------------------------------------\n");
    printf("Timestamp: %s", ctime(&entry->timestamp));
    printf("Text: %s", entry->text);
    printf("--------------------------------------------------\n");
}

// Function to add a new diary entry to a file
void add_diary_entry(char *filename, struct diary_entry *entry) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fprintf(fp, "%ld\n", entry->timestamp);
    fprintf(fp, "%s\n", entry->text);
    fclose(fp);
}

// Function to read a diary entry from a file
struct diary_entry *read_diary_entry(char *filename, long timestamp) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    long current_timestamp;
    char *current_text;
    while (fscanf(fp, "%ld\n", &current_timestamp) != EOF) {
        if (current_timestamp == timestamp) {
            getline(&current_text, NULL, fp);
            struct diary_entry *entry = new_diary_entry(current_text);
            fclose(fp);
            return entry;
        } else {
            getline(&current_text, NULL, fp);
            free(current_text);
        }
    }
    fclose(fp);
    return NULL;
}

// Function to print all diary entries in a file
void print_all_diary_entries(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    long timestamp;
    while (fscanf(fp, "%ld\n", &timestamp) != EOF) {
        struct diary_entry *entry = read_diary_entry(filename, timestamp);
        print_diary_entry(entry);
        free_diary_entry(entry);
    }
    fclose(fp);
}

int main() {
    // Create a new diary entry
    struct diary_entry *entry = new_diary_entry("My first diary entry!");

    // Add the entry to a file
    add_diary_entry("diary.txt", entry);

    // Free the entry
    free_diary_entry(entry);

    // Read the entry from the file
    entry = read_diary_entry("diary.txt", entry->timestamp);

    // Print the entry
    print_diary_entry(entry);

    // Free the entry
    free_diary_entry(entry);

    // Print all entries from the file
    print_all_diary_entries("diary.txt");

    return 0;
}