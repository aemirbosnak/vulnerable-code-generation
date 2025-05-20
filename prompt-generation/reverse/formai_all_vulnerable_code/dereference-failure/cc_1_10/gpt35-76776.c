//FormAI DATASET v1.0 Category: Digital Diary ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 10
#define MAX_CHARACTERS 256

typedef struct {
    char date[20];
    char entry[MAX_CHARACTERS];
} DiaryEntry;

void print_welcome_message() {
    printf("Welcome to your happy digital diary!\n");
    printf("What would you like to do today?\n");
}

void add_new_entry(DiaryEntry* diary, int* num_entries) {
    char entry[MAX_CHARACTERS];
    printf("Enter your happy new diary entry:\n");

    // Read input from user
    fgets(entry, MAX_CHARACTERS, stdin);

    // Add entry to diary
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(diary[*num_entries].date, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    strcpy(diary[*num_entries].entry, entry);
    (*num_entries)++;

    printf("Your happy diary was updated!\n");
}

void print_all_entries(DiaryEntry* diary, int num_entries) {
    printf("Here are all your happy diary entries:\n");

    // Print out each entry in the diary
    for (int i = 0; i < num_entries; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n", diary[i].entry);
    }
}

void print_menu_options() {
    printf("Choose an option from the menu:\n");
    printf("1. Write a happy new diary entry\n");
    printf("2. View all happy diary entries\n");
    printf("3. Exit\n");
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int num_entries = 0;
    int choice;

    // Print welcome message
    print_welcome_message();

    // Loop until user chooses to exit
    while (1) {
        print_menu_options();

        // Read input from user
        scanf("%d", &choice);

        // Handle user choice
        switch (choice) {
            case 1:
                add_new_entry(diary, &num_entries);
                break;
            case 2:
                print_all_entries(diary, num_entries);
                break;
            case 3:
                printf("Goodbye! Thanks for using your happy digital diary!\n");
                return 0;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    }

    return 0;
}