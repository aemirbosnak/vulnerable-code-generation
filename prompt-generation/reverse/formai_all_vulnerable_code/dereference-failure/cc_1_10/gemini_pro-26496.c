//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a diary entry
typedef struct diary_entry {
    char *date;
    char *title;
    char *content;
} diary_entry;

// Function to create a new diary entry
diary_entry *create_diary_entry(char *date, char *title, char *content) {
    diary_entry *entry = malloc(sizeof(diary_entry));
    entry->date = strdup(date);
    entry->title = strdup(title);
    entry->content = strdup(content);
    return entry;
}

// Function to free the memory allocated for a diary entry
void free_diary_entry(diary_entry *entry) {
    free(entry->date);
    free(entry->title);
    free(entry->content);
    free(entry);
}

// Function to add a new diary entry to a file
void add_diary_entry(char *filename, diary_entry *entry) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "%s\n%s\n%s\n", entry->date, entry->title, entry->content);
    fclose(fp);
}

// Function to read a diary entry from a file
diary_entry *read_diary_entry(char *filename, int index) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    char line[1024];
    diary_entry *entry = NULL;
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (i == index) {
            char *date = strdup(line);
            fgets(line, sizeof(line), fp);
            char *title = strdup(line);
            fgets(line, sizeof(line), fp);
            char *content = strdup(line);
            entry = create_diary_entry(date, title, content);
            break;
        }
        i++;
    }
    fclose(fp);
    return entry;
}

// Function to print a diary entry
void print_diary_entry(diary_entry *entry) {
    printf("Date: %s\n", entry->date);
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
}

// Function to get the number of diary entries in a file
int get_num_diary_entries(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    int num_entries = 0;
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
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
        exit(EXIT_FAILURE);
    }
    int i = 0;
    char line[1024];
    FILE *fp_new = fopen("temp.txt", "w");
    if (fp_new == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (i != index) {
            fprintf(fp_new, "%s", line);
        }
        i++;
    }
    fclose(fp);
    fclose(fp_new);
    remove(filename);
    rename("temp.txt", filename);
}

// Function to edit a diary entry in a file
void edit_diary_entry(char *filename, int index, diary_entry *entry) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    char line[1024];
    FILE *fp_new = fopen("temp.txt", "w");
    if (fp_new == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (i == index) {
            fprintf(fp_new, "%s\n%s\n%s\n", entry->date, entry->title, entry->content);
        } else {
            fprintf(fp_new, "%s", line);
        }
        i++;
    }
    fclose(fp);
    fclose(fp_new);
    remove(filename);
    rename("temp.txt", filename);
}

int main() {
    // Create a new diary entry
    diary_entry *entry = create_diary_entry("2023-03-08", "My First Entry", "This is my first entry in my digital diary.");

    // Add the diary entry to a file
    add_diary_entry("diary.txt", entry);

    // Read the diary entry from the file
    diary_entry *entry2 = read_diary_entry("diary.txt", 0);

    // Print the diary entry
    print_diary_entry(entry2);

    // Get the number of diary entries in the file
    int num_entries = get_num_diary_entries("diary.txt");
    printf("Number of diary entries: %d\n", num_entries);

    // Delete the diary entry from the file
    delete_diary_entry("diary.txt", 0);

    // Edit the diary entry in the file
    diary_entry *entry3 = create_diary_entry("2023-03-09", "My Second Entry", "This is my second entry in my digital diary.");
    edit_diary_entry("diary.txt", 0, entry3);

    // Free the memory allocated for the diary entries
    free_diary_entry(entry);
    free_diary_entry(entry2);
    free_diary_entry(entry3);

    return 0;
}