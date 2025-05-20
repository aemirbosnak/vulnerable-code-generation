//FormAI DATASET v1.0 Category: Digital Diary ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_FILE "diary.txt"
#define MAX_ENTRY_LENGTH 1000

// Function to get current date and time
char* get_time() {
    time_t now = time(NULL);
    char* time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0';  // Remove newline character
    return time_str;
}

// Function to add new entry to diary
void add_entry(char* entry) {
    FILE* fp = fopen(DIARY_FILE, "a");  // Open file in append mode
    char* time_str = get_time();  // Get current date and time
    fprintf(fp, "%s: %s\n", time_str, entry);  // Write entry to file
    fclose(fp);  // Close file
    printf("Entry added to diary.\n");
}

// Function to list all entries in diary
void list_entries() {
    FILE* fp = fopen(DIARY_FILE, "r");  // Open file in read mode
    char entry[MAX_ENTRY_LENGTH];
    if (fp == NULL) {
        printf("No entries found.\n");
    } else {
        printf("Entries:\n");
        while (fgets(entry, MAX_ENTRY_LENGTH, fp)) {  // Read each line in file
            printf("%s", entry);  // Print line
        }
        fclose(fp);  // Close file
    }
}

// Main function
int main() {
    printf("Welcome to your digital diary.\n");
    printf("Enter 'a' to add a new entry, 'l' to list all entries or 'q' to quit:\n");

    char option;
    char entry[MAX_ENTRY_LENGTH];

    while (1) {
        scanf("%c", &option);  // Read user input
        if (option == 'a') {
            printf("Enter your new entry:\n");
            getchar();  // Clear stdin buffer
            fgets(entry, MAX_ENTRY_LENGTH, stdin);  // Read user input
            add_entry(entry);  // Add entry to diary
        } else if (option == 'l') {
            list_entries();  // List all entries in diary
        } else if (option == 'q') {
            break;  // Quit program
        } else {
            printf("Invalid option. Please try again:\n");  // Prompt user for valid input
        }
    }

    return 0;
}