//FormAI DATASET v1.0 Category: Digital Diary ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct {
    char date[11];
    char time[6];
    char event[101];
} DiaryEntry;

DiaryEntry* createNewEntry();
void addEntry();
void searchEntries();
void displayEntry(DiaryEntry*);
void displayAllEntries();

int main() {
    int choice = 0, cont = 1;
    while(cont) {
        printf("\nMENU\n");
        printf("1. Add New Entry\n");
        printf("2. Search for Entries\n");
        printf("3. Display All Entries\n");
        printf("4. Exit Program\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                searchEntries();
                break;
            case 3:
                displayAllEntries();
                break;
            case 4:
                cont = 0;
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }
    printf("Exiting the program...\n");
    return 0;
}

DiaryEntry* createNewEntry() {
    DiaryEntry* entry = malloc(sizeof(DiaryEntry));
    printf("\nEnter the date (in dd/mm/yyyy format): ");
    fflush(stdin);
    gets(entry->date);
    printf("\nEnter the time (in hh:mm format): ");
    fflush(stdin);
    gets(entry->time);
    printf("\nEnter the event: ");
    fflush(stdin);
    gets(entry->event);
    printf("\nEntry Created.\n");
    return entry;
}

void addEntry() {
    DiaryEntry* entry = createNewEntry();
    FILE* fp = fopen("diary.txt", "a+");
    fprintf(fp, "%s %s %s\n", entry->date, entry->time, entry->event);
    fclose(fp);
    free(entry);
}

void searchEntries() {
    printf("\nEnter a search keyword: ");
    fflush(stdin);
    char keyword[101];
    gets(keyword);
    FILE* fp = fopen("diary.txt", "r");
    char line[120];
    fgets(line, 120, fp); //skip first line (column headers)
    int count = 0;
    while(fgets(line, 120, fp)) {
        DiaryEntry* entry = malloc(sizeof(DiaryEntry));
        sscanf(line, "%s %s %[^\n]", entry->date, entry->time, entry->event);
        if(strstr(entry->event, keyword)) {
            displayEntry(entry);
            count++;
        }
        free(entry);
    }
    if(count == 0) {
        printf("\nNo entries found matching the given keyword.\n");
    }
    fclose(fp);
}

void displayEntry(DiaryEntry* entry) {
    printf("\nDate: %s\nTime: %s\nEvent: %s\n", entry->date, entry->time, entry->event);
}

void displayAllEntries() {
    FILE* fp = fopen("diary.txt", "r");
    char line[120];
    fgets(line, 120, fp); //skip first line (column headers)
    int count = 0;
    while(fgets(line, 120, fp)) {
        DiaryEntry* entry = malloc(sizeof(DiaryEntry));
        sscanf(line, "%s %s %[^\n]", entry->date, entry->time, entry->event);
        displayEntry(entry);
        count++;
        free(entry);
    }
    if(count == 0) {
        printf("\nThere are no entries to display.\n");
    }
    fclose(fp);
}