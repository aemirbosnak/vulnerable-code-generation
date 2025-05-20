//FormAI DATASET v1.0 Category: Digital Diary ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Define constants */
#define MAX_ENTRIES 100
#define ENTRY_LENGTH 500

/* Define data structure for diary entry */
struct DiaryEntry {
    char date[20];
    char entry[ENTRY_LENGTH];
};

/* Function to display menu */
void display_menu() {
    printf("\n\nWelcome to the Digital Diary!\n");
    printf("1. Add new entry\n");
    printf("2. View previous entries\n");
    printf("3. Exit\n");
}

/* Function to get current date and time */
char* get_current_date() {
    time_t rawtime;
    struct tm* timeinfo;
    char* date = (char*)malloc(sizeof(char)*20);
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(date, 20, "%Y-%m-%d %H:%M:%S", timeinfo);
    return date;
}

/* Function to add new entry */
void add_entry(struct DiaryEntry diary[], int* num_entries) {
    char* date = get_current_date();
    printf("\nEnter your diary entry for %s: ", date);
    fgets(diary[*num_entries].entry, ENTRY_LENGTH, stdin);
    strcpy(diary[*num_entries].date, date);
    (*num_entries)++;
    printf("Entry added successfully!\n");
}

/* Function to view previous entries */
void view_entries(struct DiaryEntry diary[], int num_entries) {
    int i;
    printf("\n\nDate\t\tEntry\n");
    printf("-----------------------------------------------\n");
    for(i=0; i<num_entries; i++) {
        printf("%s\t%s\n", diary[i].date, diary[i].entry);
        printf("-----------------------------------------------\n");
    }
}

int main() {
    /* Declare variables */
    int choice, num_entries=0;
    struct DiaryEntry diary[MAX_ENTRIES];

    /* Display menu */
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); /* consume newline character */
        switch(choice) {
            case 1:
                add_entry(diary, &num_entries);
                break;
            case 2:
                view_entries(diary, num_entries);
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}