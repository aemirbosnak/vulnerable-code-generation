//FormAI DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_NAME 50
#define MAX_ENTRY 1000

typedef struct {
    char date[11];
    char content[MAX_ENTRY];
} Entry;

typedef struct {
    char name[MAX_NAME];
    Entry *entries;
    int num_entries;
} Diary;

void add_entry(Diary *diary);
void view_entries(Diary diary);
void search_entries(Diary diary);

int main() {
    char name[MAX_NAME];
    printf("Welcome to your digital diary!\n");
    printf("Please enter your name: ");
    fgets(name, MAX_NAME, stdin);
    name[strlen(name)-1] = '\0'; //To remove the '\n' from name
    Diary diary = {0};
    strcpy(diary.name, name);
    diary.entries = (Entry *)calloc(1, sizeof(Entry));
    diary.num_entries = 0;
    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Add an entry\n");
        printf("2. View all entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); //To remove '\n' from buffer
        switch (choice) {
            case 1:
                add_entry(&diary);
                break;
            case 2:
                if (diary.num_entries == 0) {
                    printf("No entries to show!");
                } else {
                    view_entries(diary);
                }
                break;
            case 3:
                if (diary.num_entries == 0) {
                    printf("No entries to search!");
                } else {
                    search_entries(diary);
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid input!");
                break;
        }
    } while (choice!=4);
    free(diary.entries);
    return 0;
}

void add_entry(Diary *diary) {
    printf("\nEnter today's date (YYYY-MM-DD): ");
    fgets(diary->entries[diary->num_entries].date, 11, stdin);
    diary->entries[diary->num_entries].date[strlen(diary->entries[diary->num_entries].date)-1] = '\0'; //To remove the '\n' from date
    printf("Write your entry:\n");
    fgets(diary->entries[diary->num_entries].content, MAX_ENTRY, stdin);
    diary->entries[diary->num_entries].content[strlen(diary->entries[diary->num_entries].content)-1] = '\0'; //To remove the '\n' from content
    diary->num_entries++;
    diary->entries = (Entry *)realloc(diary->entries, (diary->num_entries+1)*sizeof(Entry));
    printf("Entry added successfully!\n");
}

void view_entries(Diary diary) {
    printf("\nDiary of %s\n", diary.name);
    for (int i=0; i<diary.num_entries; i++) {
        printf("Date: %s\n", diary.entries[i].date);
        printf("Content: %s\n\n", diary.entries[i].content);
    }
}

void search_entries(Diary diary) {
    printf("Enter keyword to search: ");
    char keyword[MAX_ENTRY];
    fgets(keyword, MAX_ENTRY, stdin);
    keyword[strlen(keyword)-1] = '\0'; //To remove '\n' from keyword
    int num_matches = 0;
    for (int i=0; i<diary.num_entries; i++) {
        if (strstr(diary.entries[i].content, keyword)) {
            printf("\nDate: %s\n", diary.entries[i].date);
            printf("Content: %s\n", diary.entries[i].content);
            num_matches++;
        }
    }
    if (num_matches == 0) {
        printf("\nNo matches found!");
    }
}