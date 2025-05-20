//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a diary entry
typedef struct diary_entry {
    char *title;
    char *content;
    time_t timestamp;
} diary_entry;

// Function to create a new diary entry
diary_entry *new_diary_entry(char *title, char *content) {
    diary_entry *entry = malloc(sizeof(diary_entry));
    entry->title = strdup(title);
    entry->content = strdup(content);
    entry->timestamp = time(NULL);
    return entry;
}

// Function to free the memory allocated for a diary entry
void free_diary_entry(diary_entry *entry) {
    free(entry->title);
    free(entry->content);
    free(entry);
}

// Function to add a diary entry to a file
void add_diary_entry(char *filename, diary_entry *entry) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(fp, "%s\n", entry->title);
    fprintf(fp, "%s\n", entry->content);
    fprintf(fp, "%ld\n", entry->timestamp);

    fclose(fp);
}

// Function to read a diary entry from a file
diary_entry *read_diary_entry(char *filename, int index) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char line[1024];
    int i = 0;
    diary_entry *entry = NULL;

    while (fgets(line, sizeof(line), fp)) {
        if (i == index * 3) {
            entry = new_diary_entry(line, "");
        } else if (i == index * 3 + 1) {
            entry->content = strdup(line);
        } else if (i == index * 3 + 2) {
            entry->timestamp = atol(line);
        }
        i++;
    }

    fclose(fp);

    return entry;
}

// Function to print a diary entry
void print_diary_entry(diary_entry *entry) {
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
    printf("Timestamp: %ld\n", entry->timestamp);
}

// Function to get the number of diary entries in a file
int get_num_diary_entries(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    int num_entries = 0;
    char line[1024];

    while (fgets(line, sizeof(line), fp)) {
        num_entries++;
    }

    fclose(fp);

    return num_entries;
}

// Function to delete a diary entry from a file
void delete_diary_entry(char *filename, int index) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    FILE *fp_new = fopen("temp.txt", "w");
    if (fp_new == NULL) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    int i = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (i != index * 3 && i != index * 3 + 1 && i != index * 3 + 2) {
            fprintf(fp_new, "%s", line);
        }
        i++;
    }

    fclose(fp);
    fclose(fp_new);

    remove(filename);
    rename("temp.txt", filename);
}

// Main function
int main() {
    // Create a new diary entry
    diary_entry *entry = new_diary_entry("My first diary entry", "This is my first diary entry. I am so excited to start writing in a diary.");

    // Add the diary entry to a file
    add_diary_entry("diary.txt", entry);

    // Read the diary entry from the file
    diary_entry *entry2 = read_diary_entry("diary.txt", 0);

    // Print the diary entry
    print_diary_entry(entry2);

    // Get the number of diary entries in the file
    int num_entries = get_num_diary_entries("diary.txt");

    // Delete the diary entry from the file
    delete_diary_entry("diary.txt", 0);

    // Free the memory allocated for the diary entries
    free_diary_entry(entry);
    free_diary_entry(entry2);

    return 0;
}