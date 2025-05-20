//FormAI DATASET v1.0 Category: Digital Diary ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure to represent a diary entry
struct Entry {
    char date[20];
    char title[50];
    char content[500];
};

// Declare an array to hold up to 100 diary entries
struct Entry diary[100];

// Declare a variable to keep track of the number of entries in the diary
int numEntries = 0;

// Function to get the current date and time in a string format
char* getCurrentDate() {
    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);
    char* dateStr = asctime(timeinfo);
    dateStr[strlen(dateStr) - 1] = '\0'; // Remove the newline character at the end
    return dateStr;
}

// Function to add a new entry to the diary
void addEntry() {
    char title[50], content[500];
    printf("Enter the title of the entry (max 50 characters): ");
    scanf("%s", title);
    printf("Enter the content of the entry (max 500 characters): ");
    getchar(); // Remove the newline character from the input buffer
    fgets(content, 500, stdin);
    char* dateStr = getCurrentDate();
    strcpy(diary[numEntries].date, dateStr);
    strcpy(diary[numEntries].title, title);
    strcpy(diary[numEntries].content, content);
    numEntries++;
    printf("Entry added successfully!\n\n");
}

// Function to display a list of all entries in the diary
void showAllEntries() {
    if (numEntries == 0) {
        printf("No entries to display.\n\n");
        return;
    }
    printf("%-20s %-50s %s\n", "Date", "Title", "Content");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%-20s %-50s %s\n", diary[i].date, diary[i].title, diary[i].content);
    }
    printf("\n");
}

// Function to search for entries by keyword(s)
void searchEntries() {
    if (numEntries == 0) {
        printf("No entries to search.\n\n");
        return;
    }
    char keywords[500],*token;
    printf("Enter one or more keywords to search for: ");
    getchar(); // Remove the newline character from the input buffer
    fgets(keywords, 500, stdin);
    printf("%-20s %-50s %s\n", "Date", "Title", "Content");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < numEntries; i++) {
        char contentCopy[500];
        strcpy(contentCopy, diary[i].content);
        token=strtok(contentCopy, " ");
        while(token!=NULL){
            if(strstr(token,keywords)!=NULL){
                printf("%-20s %-50s %s\n", diary[i].date, diary[i].title, diary[i].content);
                break;
            }
            token = strtok(NULL, " ");
        }
    }
    printf("\n");
}

int main() {
    char choice;
    do {
        printf("Please choose an option:\n");
        printf("1. Add a new entry\n");
        printf("2. Show all entries\n");
        printf("3. Search entries by keyword\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                addEntry();
                break;
            case '2':
                showAllEntries();
                break;
            case '3':
                searchEntries();
                break;
            case '4':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n\n");
                break;
        }
    } while (1);
    return 0;
}