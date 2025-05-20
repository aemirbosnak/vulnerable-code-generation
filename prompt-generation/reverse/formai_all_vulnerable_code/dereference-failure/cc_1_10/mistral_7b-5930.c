//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRY 100
#define ENTRY_LEN 256
#define DATE_LEN 20

typedef struct DiaryEntry {
    char title[ENTRY_LEN];
    char content[ENTRY_LEN];
    char date[DATE_LEN];
    int index;
} DiaryEntry;

DiaryEntry diary[MAX_ENTRY];
int count = 0;

void print_menu() {
    printf("\n---- Digital Diary ----\n");
    printf("1. Add Entry\n");
    printf("2. View Entry\n");
    printf("3. Delete Entry\n");
    printf("4. Search Entry\n");
    printf("5. Exit\n");
}

int find_empty() {
    for(int i = 0; i < MAX_ENTRY; i++) {
        if(diary[i].index == -1) {
            return i;
        }
    }
    return -1;
}

void get_date(char date[DATE_LEN]) {
    time_t now = time(NULL);
    struct tm *local = localtime(&now);

    strftime(date, DATE_LEN, "%Y-%m-%d", local);
}

void add_entry() {
    int i;
    DiaryEntry *entry = &diary[find_empty()];

    if(entry == NULL) {
        printf("Diary is full!\n");
        return;
    }

    printf("Enter title: ");
    scanf("%s", entry->title);

    printf("Enter content: ");
    scanf("%[^\n]s", entry->content);

    get_date(entry->date);

    entry->index = count++;
}

void view_entry(int index) {
    DiaryEntry *entry = &diary[index];

    if(entry == NULL) {
        printf("Invalid index!\n");
        return;
    }

    printf("\nTitle: %s\n", entry->title);
    printf("Date: %s\n", entry->date);
    printf("Content: %s\n", entry->content);
}

void delete_entry(int index) {
    DiaryEntry *entry = &diary[index];

    if(entry == NULL) {
        printf("Invalid index!\n");
        return;
    }

    memset(entry, 0, sizeof(DiaryEntry));
    entry->index = -1;
}

void search_entry(char keyword[ENTRY_LEN]) {
    for(int i = 0; i < MAX_ENTRY; i++) {
        DiaryEntry *entry = &diary[i];

        if(entry->index == -1) {
            continue;
        }

        if(strstr(entry->title, keyword) != NULL ||
           strstr(entry->content, keyword) != NULL) {
            view_entry(i);
            break;
        }
    }
}

int main() {
    int choice;
    char keyword[ENTRY_LEN];

    while(1) {
        print_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_entry();
                break;
            case 2:
                printf("Enter index: ");
                scanf("%d", &choice);
                view_entry(choice);
                break;
            case 3:
                printf("Enter index: ");
                scanf("%d", &choice);
                delete_entry(choice);
                break;
            case 4:
                printf("Enter keyword: ");
                scanf("%s", keyword);
                search_entry(keyword);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}