//FormAI DATASET v1.0 Category: Digital Diary ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Entry {
    char date[20];
    char title[50];
    char body[500];
};

void createEntry(struct Entry entries[], int count) {
    time_t t = time(NULL);
    struct tm *time = localtime(&t);

    printf("\nEnter the title of the entry: ");
    scanf("%s", entries[count].title);

    printf("\nEnter the body of the entry: ");
    scanf("%s", entries[count].body);

    sprintf(entries[count].date, "%d-%d-%d", time->tm_mday, time->tm_mon+1, time->tm_year+1900);

    printf("\nEntry created successfully on %s!\n", entries[count].date);
}

void viewEntries(struct Entry entries[], int count) {
    printf("\n------------------------\n");
    for(int i=0; i<count; i++) {
        printf("\nTitle: %s", entries[i].title);
        printf("\nDate: %s\n", entries[i].date);
        printf("\nBody: %s\n", entries[i].body);
        printf("\n------------------------\n");
    }
}

int main() {
    int choice, entryCount = 0;
    struct Entry entries[100];

    while(1) {
        printf("\n\n-----------MENU-----------\n");
        printf("\n1. Create New Entry\n2. View Entries\n3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                createEntry(entries, entryCount);
                entryCount++;
                break;
            case 2: 
                viewEntries(entries, entryCount);
                break;
            case 3: 
                printf("\nExiting Digital Diary...\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Please try again.");
            }
        }
        return 0;
}