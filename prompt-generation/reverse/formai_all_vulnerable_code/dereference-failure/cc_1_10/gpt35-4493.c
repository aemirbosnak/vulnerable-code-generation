//FormAI DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to display the menu
void display_menu() {
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("      C DIGITAL DIARY\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Choose an option:\n");
    printf("1. Add a new entry\n");
    printf("2. View previous entries\n");
    printf("3. Search for an entry\n");
    printf("4. Exit\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

// Function to add a new entry
void add_entry() {
    FILE *fp;
    char title[50], date[50], entry[500];

    // Get the input from the user
    printf("Enter the title of the entry: ");
    fflush(stdin);
    fgets(title, 50, stdin);
    printf("Enter the date of the entry (in dd/mm/yyyy format): ");
    fflush(stdin);
    fgets(date, 50, stdin);
    printf("Enter the entry:\n");
    fflush(stdin);
    fgets(entry, 500, stdin);

    // Open the file in append mode
    fp = fopen("digital_diary.txt", "a");

    // Write the entry to the file
    fprintf(fp, "Title: %s", title);
    fprintf(fp, "Date: %s", date);
    fprintf(fp, "Entry: %s\n", entry);

    // Close the file
    fclose(fp);

    printf("Entry added successfully!\n");
}

// Function to view previous entries
void view_entries() {
    FILE *fp;
    char ch;

    // Open the file
    fp = fopen("digital_diary.txt", "r");

    // Check if the file exists
    if (fp == NULL) {
        printf("No entries found!\n");
        return;
    }

    // Print the contents of the file
    while((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    // Close the file
    fclose(fp);
}

// Function to search for an entry
void search_entry() {
    FILE *fp;
    char query[50], ch;

    // Get the query from the user
    printf("Enter the search query: ");
    fflush(stdin);
    fgets(query, 50, stdin);

    // Open the file
    fp = fopen("digital_diary.txt", "r");

    // Check if the file exists
    if (fp == NULL) {
        printf("No entries found!\n");
        return;
    }

    // Search for the query in the file
    while((ch = fgetc(fp)) != EOF) {
        if(ch == query[0]) {
            fseek(fp, -1, SEEK_CUR);
            if(strstr(query, fgets(ch, 50, fp)) != NULL) {
                printf("\nMatch found:\n");
                while((ch = fgetc(fp)) != '\n') {
                    printf("%c", ch);
                }
                printf("\n");
            }
        }
    }

    // Close the file
    fclose(fp);
}

int main() {
    int choice;

    while(1) {
        display_menu();

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }

    }

    return 0;
}