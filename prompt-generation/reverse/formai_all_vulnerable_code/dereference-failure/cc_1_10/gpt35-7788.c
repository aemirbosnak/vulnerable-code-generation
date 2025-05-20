//FormAI DATASET v1.0 Category: Digital Diary ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare function prototypes
void displayMenu();
void addEntry();
void viewEntries();

// Define global variables
char entries[1000][1000];
int entryCount = 0;

int main() {
    int choice;
    srand(time(NULL)); // Seed random number generator
    printf("Welcome to your Digital Diary\n\n");
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);
    return 0;
}

// Function to display the main menu
void displayMenu() {
    printf("1. Add entry\n");
    printf("2. View entries\n");
    printf("3. Exit\n");
}

// Function to add an entry to the diary
void addEntry() {
    char date[20];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    printf("\nEnter your entry for %s:\n", date);
    scanf(" %[^\n]", entries[entryCount]);
    printf("\nEntry added successfully!\n\n");
    entryCount++;
}

// Function to view all entries in the diary
void viewEntries() {
    if(entryCount == 0) {
        printf("\nNo entries found. Please add an entry.\n\n");
        return;
    }
    printf("\n\nYour diary entries:\n");
    for(int i = 0; i < entryCount; i++) {
        printf("%d. %s\n", i+1, entries[i]);
    }
    printf("\n\n");
}