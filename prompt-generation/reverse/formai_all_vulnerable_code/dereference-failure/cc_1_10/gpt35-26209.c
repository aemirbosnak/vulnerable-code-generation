//FormAI DATASET v1.0 Category: Digital Diary ; Style: detailed
/*
A Digital Diary program in C
Author: AI Chatbot
Date: August 2021
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to add a new entry to the diary
void addEntry(char **diary, int *size) {
    // Prompt user for input
    printf("Enter the date (DD/MM/YYYY): ");
    char date[11];
    fgets(date, 11, stdin);
    fflush(stdin);

    printf("Enter your entry: ");
    char *entry = (char*) malloc(sizeof(char) * 1000);
    fgets(entry, 1000, stdin);
    fflush(stdin);

    // Resize diary to accommodate new entry
    *diary = (char*) realloc(*diary, sizeof(char) * ((*size) + 1) * 1011);

    // Add new entry to diary
    strcat(*(diary+*size), date);
    strcat(*(diary+*size), "\n");
    strcat(*(diary+*size), entry);

    (*size)++;

    printf("New entry added successfully!\n");
}

// Function to display all entries in the diary
void displayEntries(char **diary, int size) {
    if (size == 0) {
        printf("Diary is empty.\n");
        return;
    }

    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%s", *(diary+i));
        printf("\n");
    }
}

// Function to search for entries containing a given keyword
void searchEntries(char **diary, int size) {
    if (size == 0) {
        printf("Diary is empty.\n");
        return;
    }

    printf("Enter the keyword to search for: ");
    char keyword[50];
    fgets(keyword, 50, stdin);
    fflush(stdin);

    printf("\n");
    for (int i = 0; i < size; i++) {
        if (strstr(*(diary+i), keyword) != NULL) {
            printf("%s", *(diary+i));
            printf("\n");
        }
    }
}

int main() {
    char **diary = (char**) malloc(sizeof(char*));
    *diary = (char*) calloc(1, sizeof(char) * 1011);
    int size = 0;
    int choice;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add new entry\n");
        printf("2. Display all entries\n");
        printf("3. Search for entries\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        fflush(stdin);

        switch(choice) {
            case 1: addEntry(diary, &size);
                    break;
            case 2: displayEntries(diary, size);
                    break;
            case 3: searchEntries(diary, size);
                    break;
            case 4: printf("Exiting program...\n");
                    exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}