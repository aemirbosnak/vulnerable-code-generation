//FormAI DATASET v1.0 Category: Digital Diary ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct {
    char date[20];
    char body[1000];
} journal_entry;

void add_entry(journal_entry* entries, int* num_entries) {
    char* date = (char*)malloc(sizeof(char)*20);
    printf("Enter Date (MM/DD/YYYY): ");
    scanf("%s", date);
    strcpy(*(entries + *num_entries)->date, date);
    printf("Enter Body of Entry: ");
    char* body = (char*)malloc(sizeof(char)*1000);
    getchar();
    fgets(body, 1000, stdin);
    strcpy(*(entries + *num_entries)->body, body);
    (*num_entries)++;
}

void display_entries(journal_entry* entries, int num_entries) {
    printf("Journal Entries:\n");
    for(int i = 0; i < num_entries; i++) {
        printf("Date: %s\n", (entries + i)->date);
        printf("Entry:\n%s\n", (entries + i)->body);
    }
}

int main() {
    int option, num_entries = 0;
    journal_entry* entries = (journal_entry*)malloc(sizeof(journal_entry)*100);
    printf("Welcome to your Digital Diary!\n");
    do {
        printf("\n1. Add Entry\n2. View Entries\n3. Exit\n");
        printf("Enter Option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_entry(entries, &num_entries);
                break;
            case 2:
                display_entries(entries, num_entries);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Option, Please try again.\n");
                break;
        }
    } while(option != 3);
    return 0;
}