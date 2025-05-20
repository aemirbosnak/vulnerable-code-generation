//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1000

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the structure of a diary entry
typedef struct diary_entry {
    time_t timestamp;
    char *text;
} diary_entry_t;

// Create a new diary entry
diary_entry_t *create_entry(time_t timestamp, char *text) {
    diary_entry_t *entry = malloc(sizeof(diary_entry_t));
    if (entry == NULL) {
        return NULL;
    }
    entry->timestamp = timestamp;
    entry->text = strdup(text);
    return entry;
}

// Write a diary entry to a file
int write_entry(diary_entry_t *entry, FILE *fp) {
    if (fwrite(&entry->timestamp, sizeof(time_t), 1, fp) != 1) {
        return -1;
    }
    if (fwrite(entry->text, strlen(entry->text) + 1, 1, fp) != 1) {
        return -1;
    }
    return 0;
}

// Read a diary entry from a file
diary_entry_t *read_entry(FILE *fp) {
    diary_entry_t *entry = malloc(sizeof(diary_entry_t));
    if (entry == NULL) {
        return NULL;
    }
    if (fread(&entry->timestamp, sizeof(time_t), 1, fp) != 1) {
        free(entry);
        return NULL;
    }
    char *text = malloc(MAX_ENTRY_LENGTH + 1);
    if (text == NULL) {
        free(entry);
        return NULL;
    }
    if (fread(text, MAX_ENTRY_LENGTH + 1, 1, fp) != 1) {
        free(entry);
        free(text);
        return NULL;
    }
    entry->text = text;
    return entry;
}

// Print a diary entry
void print_entry(diary_entry_t *entry) {
    printf("%s\n", ctime(&entry->timestamp));
    printf("%s\n", entry->text);
}

// Free a diary entry
void free_entry(diary_entry_t *entry) {
    free(entry->text);
    free(entry);
}

// Main function
int main() {
    // Create a new diary file
    FILE *fp = fopen("diary.txt", "w");
    if (fp == NULL) {
        perror("Error opening diary file");
        return EXIT_FAILURE;
    }

    // Write some diary entries
    time_t now = time(NULL);
    diary_entry_t *entry1 = create_entry(now, "Today was a great day!");
    write_entry(entry1, fp);
    free_entry(entry1);
    diary_entry_t *entry2 = create_entry(now, "I learned a lot today.");
    write_entry(entry2, fp);
    free_entry(entry2);
    diary_entry_t *entry3 = create_entry(now, "I'm so happy!");
    write_entry(entry3, fp);
    free_entry(entry3);

    // Close the diary file
    fclose(fp);

    // Reopen the diary file for reading
    fp = fopen("diary.txt", "r");
    if (fp == NULL) {
        perror("Error opening diary file");
        return EXIT_FAILURE;
    }

    // Read and print the diary entries
    while (1) {
        diary_entry_t *entry = read_entry(fp);
        if (entry == NULL) {
            break;
        }
        print_entry(entry);
        free_entry(entry);
    }

    // Close the diary file
    fclose(fp);

    return EXIT_SUCCESS;
}