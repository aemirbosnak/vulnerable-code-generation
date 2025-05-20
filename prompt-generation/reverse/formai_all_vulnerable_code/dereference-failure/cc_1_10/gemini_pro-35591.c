//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a diary entry
typedef struct diary_entry {
    char *title;
    char *body;
    char *date;
} diary_entry;

// Function to create a new diary entry
diary_entry *create_diary_entry(char *title, char *body, char *date) {
    diary_entry *entry = malloc(sizeof(diary_entry));
    entry->title = strdup(title);
    entry->body = strdup(body);
    entry->date = strdup(date);
    return entry;
}

// Function to free the memory allocated for a diary entry
void free_diary_entry(diary_entry *entry) {
    free(entry->title);
    free(entry->body);
    free(entry->date);
    free(entry);
}

// Function to add a new diary entry to a file
void add_diary_entry(char *filename, diary_entry *entry) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(fp, "%s\n", entry->title);
    fprintf(fp, "%s\n", entry->body);
    fprintf(fp, "%s\n", entry->date);
    fclose(fp);
}

// Function to read a diary entry from a file
diary_entry *read_diary_entry(char *filename, int index) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }
    char *line = NULL;
    size_t len = 0;
    int count = 0;
    diary_entry *entry = NULL;
    while (getline(&line, &len, fp) != -1) {
        if (count == index * 3) {
            entry = create_diary_entry(line, NULL, NULL);
        } else if (count == index * 3 + 1) {
            entry->body = strdup(line);
        } else if (count == index * 3 + 2) {
            entry->date = strdup(line);
            break;
        }
        count++;
    }
    free(line);
    fclose(fp);
    return entry;
}

// Function to print a diary entry
void print_diary_entry(diary_entry *entry) {
    printf("Title: %s\n", entry->title);
    printf("Body: %s\n", entry->body);
    printf("Date: %s\n", entry->date);
}

// Function to get the number of diary entries in a file
int get_num_diary_entries(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }
    int count = 0;
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fp) != -1) {
        count++;
    }
    free(line);
    fclose(fp);
    return count / 3;
}

// Function to delete a diary entry from a file
void delete_diary_entry(char *filename, int index) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    char *line = NULL;
    size_t len = 0;
    int count = 0;
    FILE *fp_new = fopen("temp.txt", "w");
    if (fp_new == NULL) {
        perror("Error opening file");
        return;
    }
    while (getline(&line, &len, fp) != -1) {
        if (count != index * 3 && count != index * 3 + 1 && count != index * 3 + 2) {
            fprintf(fp_new, "%s", line);
        }
        count++;
    }
    free(line);
    fclose(fp);
    fclose(fp_new);
    remove(filename);
    rename("temp.txt", filename);
}

// Main function
int main() {
    // Create a new diary entry
    diary_entry *entry = create_diary_entry("My first entry", "This is my first entry in my digital diary.", "2023-01-01");

    // Add the entry to a file
    add_diary_entry("diary.txt", entry);

    // Read the entry from the file
    diary_entry *entry2 = read_diary_entry("diary.txt", 0);

    // Print the entry
    print_diary_entry(entry2);

    // Get the number of entries in the file
    int num_entries = get_num_diary_entries("diary.txt");

    // Delete the entry from the file
    delete_diary_entry("diary.txt", 0);

    // Free the memory allocated for the entries
    free_diary_entry(entry);
    free_diary_entry(entry2);

    return 0;
}