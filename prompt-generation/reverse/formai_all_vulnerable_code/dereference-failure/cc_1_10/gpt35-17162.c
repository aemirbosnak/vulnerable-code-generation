//FormAI DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 200

typedef struct diary_entry_t {
    char date[15];
    char time[10];
    char entry[MAX_SIZE];
    struct diary_entry_t *next;
} DiaryEntry;

DiaryEntry *head = NULL;

void print_options() {
    printf("Welcome to the Digital Diary\n");
    printf("1. Add entry\n");
    printf("2. Search entry\n");
    printf("3. Delete entry\n");
    printf("4. Print entries\n");
    printf("5. Exit\n");
}

void insert_entry(char date[], char time[], char entry[]) {
    DiaryEntry *new_entry = (DiaryEntry*)malloc(sizeof(DiaryEntry));
    strcpy(new_entry->date, date);
    strcpy(new_entry->time, time);
    strcpy(new_entry->entry, entry);
    new_entry->next = head;
    head = new_entry;
}

void add_entry() {
    char date[15], time[10], entry[MAX_SIZE];
    getchar();

    printf("Enter date (dd/mm/yyyy): ");
    fgets(date, sizeof(date), stdin);

    printf("Enter time (hh:mm): ");
    fgets(time, sizeof(time), stdin);

    printf("Enter diary entry: ");
    fgets(entry, sizeof(entry), stdin);

    insert_entry(date, time, entry);
    printf("Entry added!\n");
}

void search_entry() {
    char keyword[MAX_SIZE];
    getchar();

    printf("Enter search keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    int count = 0;

    for (DiaryEntry *entry = head; entry != NULL; entry = entry->next) {
        if (strstr(entry->entry, keyword)) {
            count++;
            printf("Date: %s", entry->date);
            printf("Time: %s", entry->time);
            printf("Entry: %s", entry->entry);
        }
    }

    if (count == 0) {
        printf("No entries found with the keyword: %s\n", keyword);
    }
}

void delete_entry() {
    char date[15], time[10];
    getchar();

    printf("Enter date (dd/mm/yyyy) of entry to delete: ");
    fgets(date, sizeof(date), stdin);

    printf("Enter time (hh:mm) of entry to delete: ");
    fgets(time, sizeof(time), stdin);

    DiaryEntry *prev_entry = NULL;

    for (DiaryEntry *entry = head; entry != NULL; entry = entry->next) {
        if (strcmp(entry->date, date) == 0 && strcmp(entry->time, time) == 0) {
            if (prev_entry == NULL) {
                head = entry->next;
            } else {
                prev_entry->next = entry->next;
            }
            free(entry);
            printf("Entry deleted!\n");
            return;
        }
        prev_entry = entry;
    }

    printf("Entry not found for date: %s and time: %s\n", date, time);
}

void print_entries() {
    if (head == NULL) {
        printf("No entries found\n");
        return;
    }

    for (DiaryEntry *entry = head; entry != NULL; entry = entry->next) {
        printf("Date: %s", entry->date);
        printf("Time: %s", entry->time);
        printf("Entry: %s", entry->entry);
    }
}

int main() {
    int choice;

    do {
        print_options();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_entry();
                break;
            case 2:
                search_entry();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                print_entries();
                break;
            case 5:
                printf("Exiting digital diary...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
        printf("\n");
    } while(choice != 5);

    return 0;
}