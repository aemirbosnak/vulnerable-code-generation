//FormAI DATASET v1.0 Category: Digital Diary ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DiaryEntry {
    int date; // stores date in format of yyyymmdd (e.g. 20210904)
    char *entry_text; // stores the diary entry text 
} DiaryEntry;

void add_entry(DiaryEntry diary[], int *num_entries) {
    DiaryEntry new_entry;
    char buffer[256];

    printf("Enter the date in format of yyyymmdd: ");
    scanf("%d", &new_entry.date);

    printf("Enter the diary entry text: ");
    fgets(buffer, sizeof(buffer), stdin);

    // allocate memory for entry text and copy the input text
    new_entry.entry_text = (char *) malloc(strlen(buffer) + 1);
    strcpy(new_entry.entry_text, buffer);

    // add new entry to the diary
    diary[*num_entries] = new_entry;
    (*num_entries)++;
}

void view_entries(DiaryEntry diary[], int num_entries) {
    int i;
    char date_str[11];

    // print out all diary entries
    for (i = 0; i < num_entries; i++) {
        sprintf(date_str, "%d-%d-%d", diary[i].date / 10000, (diary[i].date % 10000) / 100, diary[i].date % 100);
        printf("Date: %s\nEntry: %s\n", date_str, diary[i].entry_text);
    }
}

int main() {
    DiaryEntry diary[100];
    int num_entries = 0;
    int selection = -1;

    while (selection != 0) {
        printf("Enter 1 to add a diary entry or 2 to view diary entries\n");
        printf("Enter 0 to exit the program\n");
        printf("Selection: ");
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                add_entry(diary, &num_entries);
                break;
            case 2:
                view_entries(diary, num_entries);
                break;
            case 0:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid selection. Try again.\n");
        }
    }

    // free memory used by entry text strings
    int i;
    for (i = 0; i < num_entries; i++) {
        free(diary[i].entry_text);
    }

    return 0;
}