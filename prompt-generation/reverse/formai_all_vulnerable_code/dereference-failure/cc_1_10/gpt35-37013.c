//FormAI DATASET v1.0 Category: Browser Plugin ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_URL_LENGTH 100
#define MAX_HISTORY_ENTRIES 10

// Linked list data structure to store browser history
typedef struct _history_entry {
    char url[MAX_URL_LENGTH];
    struct _history_entry* next;
} HistoryEntry;

// Function to add a new URL to browser history
void add_url_to_history(HistoryEntry** history, char* url) {
    // Check if history is already full
    if (count_history_entries(*history) >= MAX_HISTORY_ENTRIES) {
        printf("Error: History is full. Cannot add URL.\n");
        return;
    }

    // Create new history entry
    HistoryEntry* new_entry = (HistoryEntry*) malloc(sizeof(HistoryEntry));
    strcpy(new_entry->url, url);
    new_entry->next = NULL;

    // Add new entry to beginning of history list
    new_entry->next = *history;
    *history = new_entry;
}

// Function to count number of history entries
int count_history_entries(HistoryEntry* history) {
    int count = 0;
    while (history != NULL) {
        count++;
        history = history->next;
    }
    return count;
}

// Function to print browser history
void print_history(HistoryEntry* history) {
    printf("Browser history:\n");
    while (history != NULL) {
        printf("- %s\n", history->url);
        history = history->next;
    }
}

// Function to check if a string is a valid URL
bool is_valid_url(char* str) {
    // Check if string starts with "http://" or "https://"
    if (strncmp(str, "http://", 7) == 0 || strncmp(str, "https://", 8) == 0) {
        // Check if rest of string contains only alphabets, digits, ".", "-", and ":"
        for (int i = (int) strlen(str) - 1; i > 7; i--) {
            if (!isalnum(str[i]) && str[i] != '.' && str[i] != '-' && str[i] != ':') {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main() {
    HistoryEntry* history = NULL;

    // Add some example URLs to browser history
    add_url_to_history(&history, "https://www.google.com");
    add_url_to_history(&history, "https://www.youtube.com");
    add_url_to_history(&history, "https://www.github.com");

    // Print current browser history
    print_history(history);

    // Get new URL from user and add to history
    char new_url[MAX_URL_LENGTH];
    printf("Enter a new URL to add to history: ");
    scanf("%s", new_url);
    if (is_valid_url(new_url)) {
        add_url_to_history(&history, new_url);
    } else {
        printf("Error: Invalid URL.\n");
    }

    // Print updated browser history
    print_history(history);

    return 0;
}