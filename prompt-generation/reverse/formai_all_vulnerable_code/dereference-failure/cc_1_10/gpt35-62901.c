//FormAI DATASET v1.0 Category: Digital Diary ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRY_SIZE 1000
#define MAX_ENTRIES 10

// Function to display the menu and get user input
int displayMenu()
{
    int choice;
    printf("\n----------MENU----------\n");
    printf("1. Add new entry\n");
    printf("2. Display all entries\n");
    printf("3. Search for a particular entry\n");
    printf("4. Delete an entry\n");
    printf("5. Exit\n");
    printf("------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Struct to hold the diary entry data
typedef struct {
    char dateStr[20];
    char entryContent[MAX_ENTRY_SIZE];
} diaryEntry;

// Function to add a new entry to the diary
void addNewEntry(diaryEntry *entries, int *numEntries)
{
    // Get current date and time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    // Format the date string
    sprintf(entries[*numEntries].dateStr, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    // Get user input for the entry content
    printf("Enter new diary entry (max %d characters):\n", MAX_ENTRY_SIZE);
    getchar(); // consume newline character
    fgets(entries[*numEntries].entryContent, MAX_ENTRY_SIZE, stdin);
    // Increment the number of entries
    (*numEntries)++;
    // Display success message
    printf("New entry added successfully!\n");
}

// Function to display all the entries in the diary
void displayAllEntries(diaryEntry *entries, int numEntries)
{
    if(numEntries == 0) {
        printf("No entries found!\n");
        return;
    }
    printf("\n-----------DIARY ENTRIES-----------\n");
    for(int i=0; i<numEntries; i++) {
        printf("%s\n%s", entries[i].dateStr, entries[i].entryContent);
        printf("------------------------------------\n");
    }
}

// Function to search for a particular entry in the diary
void searchEntry(diaryEntry *entries, int numEntries)
{
    if(numEntries == 0) {
        printf("No entries found!\n");
        return;
    }
    printf("Enter the search text: ");
    char searchText[MAX_ENTRY_SIZE];
    getchar(); // consume newline character
    fgets(searchText, MAX_ENTRY_SIZE, stdin);
    printf("\n-----------SEARCH RESULTS-----------\n");
    int found = 0;
    for(int i=0; i<numEntries; i++) {
        if(strstr(entries[i].entryContent, searchText) != NULL) {
            found = 1;
            printf("%s\n%s", entries[i].dateStr, entries[i].entryContent);
            printf("------------------------------------\n");
        }
    }
    if(!found) {
        printf("No results found for '%s'!\n", searchText);
    }
}

// Function to delete an entry from the diary
void deleteEntry(diaryEntry *entries, int *numEntries)
{
    if(*numEntries == 0) {
        printf("No entries found!\n");
        return;
    }
    printf("Enter the index of the entry to delete (1-%d): ", *numEntries);
    int choice;
    scanf("%d", &choice);
    if(choice < 1 || choice > *numEntries) {
        printf("Invalid choice!\n");
        return;
    }
    for(int i=choice-1; i<*numEntries-1; i++) {
        strcpy(entries[i].dateStr, entries[i+1].dateStr);
        strcpy(entries[i].entryContent, entries[i+1].entryContent);
    }
    (*numEntries)--;
    printf("Entry deleted successfully!\n");
}

int main()
{
    diaryEntry entries[MAX_ENTRIES];
    int numEntries = 0;
    int choice = 0;
    while(choice != 5) {
        choice = displayMenu();
        switch(choice) {
            case 1:
                addNewEntry(entries, &numEntries);
                break;
            case 2:
                displayAllEntries(entries, numEntries);
                break;
            case 3:
                searchEntry(entries, numEntries);
                break;
            case 4:
                deleteEntry(entries, &numEntries);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}