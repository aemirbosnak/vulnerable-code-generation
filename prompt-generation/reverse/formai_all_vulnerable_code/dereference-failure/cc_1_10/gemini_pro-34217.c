//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// User-defined types
typedef struct {
    char *title;
    char *body;
    struct tm timestamp;
} Entry;

// Function prototypes
void add_entry(Entry *entries, int *num_entries);
void print_entry(Entry *entry);
void print_entries(Entry *entries, int num_entries);

// Main function
int main() {
    // Initialize the array of entries
    Entry *entries = malloc(100 * sizeof(Entry));
    int num_entries = 0;

    // Add some entries to the array
    add_entry(entries, &num_entries);
    add_entry(entries, &num_entries);
    add_entry(entries, &num_entries);

    // Print the entries
    print_entries(entries, num_entries);

    // Free the array of entries
    for (int i = 0; i < num_entries; i++) {
        free(entries[i].title);
        free(entries[i].body);
    }
    free(entries);

    return 0;
}

// Function to add an entry to the array
void add_entry(Entry *entries, int *num_entries) {
    // Get the current time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // Get the entry title and body from the user
    char title[100];
    char body[1000];
    printf("Enter the entry title: ");
    scanf("%s", title);
    printf("Enter the entry body: ");
    scanf("%s", body);

    // Allocate memory for the entry
    entries[*num_entries].title = malloc(strlen(title) + 1);
    entries[*num_entries].body = malloc(strlen(body) + 1);

    // Copy the title and body into the entry
    strcpy(entries[*num_entries].title, title);
    strcpy(entries[*num_entries].body, body);

    // Set the entry timestamp
    entries[*num_entries].timestamp = *tm;

    // Increment the number of entries
    (*num_entries)++;
}

// Function to print an entry
void print_entry(Entry *entry) {
    // Print the entry title
    printf("Title: %s\n", entry->title);

    // Print the entry body
    printf("Body: %s\n", entry->body);

    // Print the entry timestamp
    printf("Timestamp: %d/%d/%d %d:%d:%d\n", entry->timestamp.tm_mon + 1, entry->timestamp.tm_mday,
        entry->timestamp.tm_year + 1900, entry->timestamp.tm_hour, entry->timestamp.tm_min,
        entry->timestamp.tm_sec);
}

// Function to print the entries
void print_entries(Entry *entries, int num_entries) {
    // Print each entry
    for (int i = 0; i < num_entries; i++) {
        print_entry(&entries[i]);
        printf("\n");
    }
}